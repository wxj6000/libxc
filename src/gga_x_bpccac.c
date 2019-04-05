/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"

#define XC_GGA_X_BPCCAC  98 /* BPCCAC (GRAC for the energy) */

#include "maple2c/gga_exc/gga_x_bpccac.c"
#include "work_gga_new.c"

const xc_func_info_type xc_func_info_gga_x_bpccac = {
  XC_GGA_X_BPCCAC,
  XC_EXCHANGE,
  "BPCCAC (GRAC for the energy)",
  XC_FAMILY_GGA,
  {&xc_ref_Bremond2012_1184, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-24,
  0, NULL, NULL,
  NULL, NULL, 
  NULL, work_gga, NULL
};

