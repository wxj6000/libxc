/* 
  This file was generated automatically with ./scripts/maple2c_new.pl.
  Do not edit this file directly as it can be overwritten!!

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Maple version     : Maple 2016 (X86 64 LINUX)
  Maple source      : .//maple/lda_xc_tih.mpl
  Type of functional: lda_vxc
*/

#define maple2c_order 3

static inline void
func_unpol(const xc_func_type *p, int order, const double *rho, double *vrho, double *v2rho2, double *v3rho3)
{
  double t3, t7, t11, t15, t19, t23, t27, t31;
  double t33, t35, t37, t39, t41, t43, t45, t47;


  t3 = tanh(0.10953e1 + 0.334789e-1 * rho[0]);
  t7 = tanh(-0.414661e0 + 0.152399e0 * rho[0]);
  t11 = tanh(-0.354691e0 + 0.390837e-1 * rho[0]);
  t15 = tanh(0.748531e-1 + 0.136598e0 * rho[0]);
  t19 = tanh(-0.141063e1 + 0.496577e-2 * rho[0]);
  t23 = tanh(0.48315e0 + 0.402905e1 * rho[0]);
  t27 = tanh(-0.420166e0 + 0.104352e-1 * rho[0]);
  t31 = tanh(0.147409e1 + 0.442455e0 * rho[0]);
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = 0.625039e0 - 0.130351e1 * t3 - 0.137026e1 * t7 - 0.129598e1 * t11 + 0.104305e1 * t15 - 0.909651e0 * t19 - 0.991782e0 * t23 - 0.915745e0 * t27 - 0.195026e1 * t31;

  if(order < 2) return;


  t33 = t3 * t3;
  t35 = t7 * t7;
  t37 = t11 * t11;
  t39 = t15 * t15;
  t41 = t19 * t19;
  t43 = t23 * t23;
  t45 = t27 * t27;
  t47 = t31 * t31;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = -0.503355413957527e1 + 0.43640080939e-1 * t33 + 0.20882625374e0 * t35 + 0.50651693526e-1 * t37 - 0.14247854390e0 * t39 + 0.451711764627e-2 * t41 + 0.399593926710e1 * t43 + 0.95559822240e-2 * t45 + 0.86290228830e0 * t47;

  if(order < 3) return;


  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = 0.87280161878e-1 * t3 * (0.334789e-1 - 0.334789e-1 * t33) + 0.41765250748e0 * t7 * (0.152399e0 - 0.152399e0 * t35) + 0.101303387052e0 * t11 * (0.390837e-1 - 0.390837e-1 * t37) - 0.28495708780e0 * t15 * (0.136598e0 - 0.136598e0 * t39) + 0.903423529254e-2 * t19 * (0.496577e-2 - 0.496577e-2 * t41) + 0.799187853420e1 * t23 * (0.402905e1 - 0.402905e1 * t43) + 0.191119644480e-1 * t27 * (0.104352e-1 - 0.104352e-1 * t45) + 0.172580457660e1 * t31 * (0.442455e0 - 0.442455e0 * t47);

  if(order < 4) return;



}


static inline void
func_ferr(const xc_func_type *p, int order, const double *rho, double *vrho, double *v2rho2, double *v3rho3)
{
  double t3, t7, t11, t15, t19, t23, t27, t31;
  double t33, t35, t37, t39, t41, t43, t45, t47;


  t3 = tanh(0.10953e1 + 0.334789e-1 * rho[0]);
  t7 = tanh(-0.414661e0 + 0.152399e0 * rho[0]);
  t11 = tanh(-0.354691e0 + 0.390837e-1 * rho[0]);
  t15 = tanh(0.748531e-1 + 0.136598e0 * rho[0]);
  t19 = tanh(-0.141063e1 + 0.496577e-2 * rho[0]);
  t23 = tanh(0.48315e0 + 0.402905e1 * rho[0]);
  t27 = tanh(-0.420166e0 + 0.104352e-1 * rho[0]);
  t31 = tanh(0.147409e1 + 0.442455e0 * rho[0]);
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = 0.625039e0 - 0.130351e1 * t3 - 0.137026e1 * t7 - 0.129598e1 * t11 + 0.104305e1 * t15 - 0.909651e0 * t19 - 0.991782e0 * t23 - 0.915745e0 * t27 - 0.195026e1 * t31;

  if(order < 2) return;


  t33 = t3 * t3;
  t35 = t7 * t7;
  t37 = t11 * t11;
  t39 = t15 * t15;
  t41 = t19 * t19;
  t43 = t23 * t23;
  t45 = t27 * t27;
  t47 = t31 * t31;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = -0.503355413957527e1 + 0.43640080939e-1 * t33 + 0.20882625374e0 * t35 + 0.50651693526e-1 * t37 - 0.14247854390e0 * t39 + 0.451711764627e-2 * t41 + 0.399593926710e1 * t43 + 0.95559822240e-2 * t45 + 0.86290228830e0 * t47;

  if(order < 3) return;


  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = 0.87280161878e-1 * t3 * (0.334789e-1 - 0.334789e-1 * t33) + 0.41765250748e0 * t7 * (0.152399e0 - 0.152399e0 * t35) + 0.101303387052e0 * t11 * (0.390837e-1 - 0.390837e-1 * t37) - 0.28495708780e0 * t15 * (0.136598e0 - 0.136598e0 * t39) + 0.903423529254e-2 * t19 * (0.496577e-2 - 0.496577e-2 * t41) + 0.799187853420e1 * t23 * (0.402905e1 - 0.402905e1 * t43) + 0.191119644480e-1 * t27 * (0.104352e-1 - 0.104352e-1 * t45) + 0.172580457660e1 * t31 * (0.442455e0 - 0.442455e0 * t47);

  if(order < 4) return;



}


static inline void
func_pol(const xc_func_type *p, int order, const double *rho, double *vrho, double *v2rho2, double *v3rho3)
{
  double t4, t9, t14, t19, t24, t29, t34, t39;
  double t41, t43, t45, t47, t49, t51, t53, t55;


  t4 = tanh(0.10953e1 + 0.334789e-1 * rho[0] + 0.334789e-1 * rho[1]);
  t9 = tanh(-0.414661e0 + 0.152399e0 * rho[0] + 0.152399e0 * rho[1]);
  t14 = tanh(-0.354691e0 + 0.390837e-1 * rho[0] + 0.390837e-1 * rho[1]);
  t19 = tanh(0.748531e-1 + 0.136598e0 * rho[0] + 0.136598e0 * rho[1]);
  t24 = tanh(-0.141063e1 + 0.496577e-2 * rho[0] + 0.496577e-2 * rho[1]);
  t29 = tanh(0.48315e0 + 0.402905e1 * rho[0] + 0.402905e1 * rho[1]);
  t34 = tanh(-0.420166e0 + 0.104352e-1 * rho[0] + 0.104352e-1 * rho[1]);
  t39 = tanh(0.147409e1 + 0.442455e0 * rho[0] + 0.442455e0 * rho[1]);
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = 0.625039e0 - 0.130351e1 * t4 - 0.137026e1 * t9 - 0.129598e1 * t14 + 0.104305e1 * t19 - 0.909651e0 * t24 - 0.991782e0 * t29 - 0.915745e0 * t34 - 0.195026e1 * t39;

  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[1] = vrho[0];

  if(order < 2) return;


  t41 = t4 * t4;
  t43 = t9 * t9;
  t45 = t14 * t14;
  t47 = t19 * t19;
  t49 = t24 * t24;
  t51 = t29 * t29;
  t53 = t34 * t34;
  t55 = t39 * t39;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = -0.503355413957527e1 + 0.43640080939e-1 * t41 + 0.20882625374e0 * t43 + 0.50651693526e-1 * t45 - 0.14247854390e0 * t47 + 0.451711764627e-2 * t49 + 0.399593926710e1 * t51 + 0.95559822240e-2 * t53 + 0.86290228830e0 * t55;

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[1] = v2rho2[0];

  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[2] = v2rho2[1];

  if(order < 3) return;


  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = 0.87280161878e-1 * t4 * (0.334789e-1 - 0.334789e-1 * t41) + 0.41765250748e0 * t9 * (0.152399e0 - 0.152399e0 * t43) + 0.101303387052e0 * t14 * (0.390837e-1 - 0.390837e-1 * t45) - 0.28495708780e0 * t19 * (0.136598e0 - 0.136598e0 * t47) + 0.903423529254e-2 * t24 * (0.496577e-2 - 0.496577e-2 * t49) + 0.799187853420e1 * t29 * (0.402905e1 - 0.402905e1 * t51) + 0.191119644480e-1 * t34 * (0.104352e-1 - 0.104352e-1 * t53) + 0.172580457660e1 * t39 * (0.442455e0 - 0.442455e0 * t55);

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[1] = v3rho3[0];

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[2] = v3rho3[1];

  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[3] = v3rho3[2];

  if(order < 4) return;



}

