/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 3 of the License, or
 (at your option) any later version.
  
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU Lesser General Public License for more details.
  
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <stdio.h>
#include "util.h"

/************************************************************************
 Wigner's parametrization from the low density limit
************************************************************************/

#define XC_LDA_C_WIGNER  2   /* Wigner parametrization       */

#include "maple2c/lda_c_wigner.c"

#define func maple2c_func
#include "work_lda.c"

const XC(func_info_type) XC(func_info_lda_c_wigner) = {
  XC_LDA_C_WIGNER,
  XC_CORRELATION,
  "Wigner",
  XC_FAMILY_LDA,
  {&xc_ref_Wigner1938_678, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC | XC_FLAGS_HAVE_FXC | XC_FLAGS_HAVE_KXC,
  1e-32, 0.0, 0.0, 1e-32,
  0, NULL, NULL,
  NULL,     /* init */
  NULL,     /* end  */
  work_lda, /* lda  */
  NULL,
  NULL
};
