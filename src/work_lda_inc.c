/*
 Copyright (C) 2006-2018 M.A.L. Marques
 Copyright (C) 2019 X. Andrade

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

/**
 * @file work_lda_inc.c
 * @brief This file is to be included in LDA functionals.
 */

#ifdef XC_DEBUG
#define __USE_GNU 1
#include <fenv.h>
#endif

/* macro to simpligy accessing the variables */
#define VAR(var, ip, index)        var[ip*p->dim.var + index]
#define WORK_LDA_(order, spin)     work_lda_ ## order ## _ ## spin
#define WORK_LDA_GPU_(order, spin) work_lda_gpu_ ## order ## _ ## spin
#define FUNC_(order, spin)         func_     ## order ## _ ## spin

/* we need double escaping of the preprocessor macros */
#define WORK_LDA(order, spin)     WORK_LDA_(order, spin)
#define WORK_LDA_GPU(order, spin) WORK_LDA_GPU_(order, spin)
#define FUNC(order, spin)         FUNC_(order, spin)

#ifndef HAVE_CUDA

static void
WORK_LDA(ORDER_TXT, SPIN_TXT)
(const XC(func_type) *p, size_t np, const double *rho, xc_lda_out_params *out)
{

#ifdef XC_DEBUG
  /* This throws an exception when floating point errors are encountered */
  /*feenableexcept(FE_DIVBYZERO | FE_INVALID);*/
#endif

  size_t ip;
  double dens;
  double my_rho[2] = {0.0, 0.0};

  for(ip = 0; ip < np; ip++){
    /* Screen low density */
    dens = (p->nspin == XC_POLARIZED) ? VAR(rho, ip, 0) + VAR(rho, ip, 1) : VAR(rho, ip, 0);
    if(dens < p->dens_threshold)
      continue;

    /* sanity check of input parameters */
    my_rho[0] = m_max(p->dens_threshold, VAR(rho, ip, 0));
    if(p->nspin == XC_POLARIZED){
      my_rho[1] = m_max(p->dens_threshold, VAR(rho, ip, 1));
    }

    FUNC(ORDER_TXT, SPIN_TXT)(p, ip, my_rho, out);

    /* check for NaNs */
#ifdef XC_DEBUG
    {
      const xc_dimensions *dim = &(p->dim);
      int ii, is_OK = 1;

      if(out->zk != NULL)
        is_OK = is_OK & isfinite(out->VAR(zk, ip, 0));

      if(out->vrho != NULL){
        for(ii=0; ii < dim->vrho; ii++)
          is_OK = is_OK && isfinite(out->VAR(vrho, ip, ii));
      }

      if(!is_OK){
        printf("Problem in the evaluation of the functional\n");
        if(p->nspin == XC_UNPOLARIZED){
          printf("./xc-get_data %d 1 %le 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0\n",
                 p->info->number, VAR(rho, ip, 0));
        }else{
          printf("./xc-get_data %d 2 %le %le 0.0 0.0 0.0 0.0 0.0 0.0 0.0\n",
                 p->info->number, VAR(rho, ip, 0), VAR(rho, ip, 1));
        }
      }
    }
#endif
  }   /* for(ip) */

}


#else

__global__ static void
WORK_LDA_GPU(ORDER_TXT, SPIN_TXT)
(const XC(func_type) *p, size_t np,
             const double *rho,
             xc_lda_out_params *out)
{
  size_t ip = blockIdx.x*blockDim.x + threadIdx.x;
  double dens;
  double my_rho[2] = {0.0, 0.0};

  if(ip >= np) return;

  /* Screen low density */
  dens = (p->nspin == XC_POLARIZED) ? VAR(rho, ip, 0) + VAR(rho, ip, 1) : VAR(rho, ip, 0);
  if(dens < p->dens_threshold)
    return;

  /* sanity check of input parameters */
  my_rho[0] = m_max(p->dens_threshold, VAR(rho, ip, 0));
  if(p->nspin == XC_POLARIZED){
    my_rho[1] = m_max(p->dens_threshold, VAR(rho, ip, 1));
  }

  FUNC(ORDER_TXT, SPIN_TXT)(p, ip, my_rho, out);
}

static void
WORK_LDA(ORDER_TXT, SPIN_TXT)
(XC(func_type) *p, size_t np, const double *rho, xc_lda_out_params *out)
{
  //make a copy of 'p' and 'out' since they might be in host-only memory
  XC(func_type) *pcuda;
  xc_lda_out_params *outcuda;
  cudaMalloc((void**)&pcuda, sizeof(XC(func_type)));
  cudaMalloc((void**)&outcuda, sizeof(xc_lda_out_params));

  // move params to GPU first
  void *params;
  void *params_cuda;
  if (p->params_size > 0){
    params = (void *) p->params;
    cudaMalloc((void**)&params_cuda, p->params_size);

    cudaMemcpy(params_cuda, params, p->params_size, cudaMemcpyHostToDevice);
    p->params = params_cuda;
  }

  // move xc_func to GPU
  cudaMemcpy(pcuda, p, sizeof(XC(func_type)), cudaMemcpyHostToDevice);
  cudaMemcpy(outcuda, out, sizeof(xc_lda_out_params), cudaMemcpyHostToDevice);

  size_t nblocks = np/CUDA_BLOCK_SIZE;
  if(np != nblocks*CUDA_BLOCK_SIZE) nblocks++;

  WORK_LDA_GPU(ORDER_TXT, SPIN_TXT)<<<nblocks, CUDA_BLOCK_SIZE>>>
    (pcuda, np, rho, outcuda);

  cudaFree(pcuda);
  cudaFree(outcuda);

  if (p->params_size > 0){
    cudaFree(params_cuda);

    // change it back to CPU
    p->params = params;
  }
}

#endif
