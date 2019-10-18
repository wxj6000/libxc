/* 
  This file was generated automatically with ./maple2c_new.pl.
  Do not edit this file directly as it can be overwritten!!

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Maple version     : Maple 2018 (X86 64 LINUX)
  Maple source      : ../maple/lda_exc/lda_c_chachiyo.mpl
  Type of functional: lda_exc
*/

#define maple2c_order 3

static inline void
func_unpol(const xc_func_type *p, int order, const double *rho, double *zk, double *vrho, double *v2rho2, double *v3rho3)
{
  double t1, t2, t3, t5, t7, t8, t9, t13;
  double t14, t16, t17, t18, t22, t23, t24, t33;
  double t34, t49, t52, t53, t54, t63;

  lda_c_chachiyo_params *params;

  assert(p->params != NULL);
  params = (lda_c_chachiyo_params * )(p->params);

  t1 = M_CBRT3;
  t2 = t1 * t1;
  t3 = params->bp * t2;
  t5 = POW_1_3(0.1e1 / M_PI);
  t7 = M_CBRT4;
  t8 = 0.1e1 / t5 * t7;
  t9 = POW_1_3(rho[0]);
  t13 = params->bp * t1;
  t14 = t5 * t5;
  t16 = t7 * t7;
  t17 = 0.1e1 / t14 * t16;
  t18 = t9 * t9;
  t22 = 0.1e1 + t3 * t8 * t9 / 0.3e1 + t13 * t17 * t18 / 0.3e1;
  t23 = log(t22);
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = params->ap * t23;

#ifndef XC_DONT_COMPILE_VXC

  if(order < 1) return;


  t24 = rho[0] * params->ap;
  t33 = t3 * t8 / t18 / 0.9e1 + 0.2e1 / 0.9e1 * t13 * t17 / t9;
  t34 = 0.1e1 / t22;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = t24 * t33 * t34 + (params->ap * t23);

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  t49 = -0.2e1 / 0.27e2 * t3 * t8 / t18 / rho[0] - 0.2e1 / 0.27e2 * t13 * t17 / t9 / rho[0];
  t52 = t33 * t33;
  t53 = t22 * t22;
  t54 = 0.1e1 / t53;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = t24 * t49 * t34 - t24 * t52 * t54 + 0.2e1 * params->ap * t33 * t34;

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  t63 = rho[0] * rho[0];
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = 0.3e1 * params->ap * t49 * t34 - 0.3e1 * params->ap * t52 * t54 + t24 * (0.10e2 / 0.81e2 * t3 * t8 / t18 / t63 + 0.8e1 / 0.81e2 * t13 * t17 / t9 / t63) * t34 - 0.3e1 * t24 * t49 * t54 * t33 + 0.2e1 * t24 * t52 * t33 / t53 / t22;

#ifndef XC_DONT_COMPILE_LXC

  if(order < 4) return;


#endif

#endif

#endif

#endif


}


static inline void
func_ferr(const xc_func_type *p, int order, const double *rho, double *zk, double *vrho, double *v2rho2, double *v3rho3)
{
  double t1, t2, t3, t5, t7, t8, t9, t13;
  double t14, t16, t17, t18, t22, t23, t24, t33;
  double t34, t49, t52, t53, t54, t63;

  lda_c_chachiyo_params *params;

  assert(p->params != NULL);
  params = (lda_c_chachiyo_params * )(p->params);

  t1 = M_CBRT3;
  t2 = t1 * t1;
  t3 = params->bf * t2;
  t5 = POW_1_3(0.1e1 / M_PI);
  t7 = M_CBRT4;
  t8 = 0.1e1 / t5 * t7;
  t9 = POW_1_3(rho[0]);
  t13 = params->bf * t1;
  t14 = t5 * t5;
  t16 = t7 * t7;
  t17 = 0.1e1 / t14 * t16;
  t18 = t9 * t9;
  t22 = 0.1e1 + t3 * t8 * t9 / 0.3e1 + t13 * t17 * t18 / 0.3e1;
  t23 = log(t22);
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = params->af * t23;

#ifndef XC_DONT_COMPILE_VXC

  if(order < 1) return;


  t24 = rho[0] * params->af;
  t33 = t3 * t8 / t18 / 0.9e1 + 0.2e1 / 0.9e1 * t13 * t17 / t9;
  t34 = 0.1e1 / t22;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = t24 * t33 * t34 + (params->af * t23);

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  t49 = -0.2e1 / 0.27e2 * t3 * t8 / t18 / rho[0] - 0.2e1 / 0.27e2 * t13 * t17 / t9 / rho[0];
  t52 = t33 * t33;
  t53 = t22 * t22;
  t54 = 0.1e1 / t53;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = t24 * t49 * t34 - t24 * t52 * t54 + 0.2e1 * params->af * t33 * t34;

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  t63 = rho[0] * rho[0];
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = 0.3e1 * params->af * t49 * t34 - 0.3e1 * params->af * t52 * t54 + t24 * (0.10e2 / 0.81e2 * t3 * t8 / t18 / t63 + 0.8e1 / 0.81e2 * t13 * t17 / t9 / t63) * t34 - 0.3e1 * t24 * t49 * t54 * t33 + 0.2e1 * t24 * t52 * t33 / t53 / t22;

#ifndef XC_DONT_COMPILE_LXC

  if(order < 4) return;


#endif

#endif

#endif

#endif


}


static inline void
func_pol(const xc_func_type *p, int order, const double *rho, double *zk, double *vrho, double *v2rho2, double *v3rho3)
{
  double t1, t2, t3, t5, t7, t8, t9, t10;
  double t11, t14, t15, t17, t18, t19, t20, t23;
  double t24, t25, t26, t29, t32, t33, t35, t36;
  double t37, t38, t39, t40, t42, t43, t45, t47;
  double t50, t51, t53, t57, t60, t62, t63, t68;
  double t70, t72, t74, t75, t76, t77, t78, t80;
  double t83, t85, t88, t90, t93, t95, t98, t99;
  double t103, t107, t111, t112, t113, t115, t116, t117;
  double t122, t124, t126, t127, t129, t131, t133, t134;
  double t135, t136, t137, t141, t142, t144, t147, t148;
  double t149, t152, t155, t157, t161, t162, t165, t168;
  double t171, t174, t176, t180, t181, t185, t188, t191;
  double t194, t196, t199, t200, t201, t206, t211, t216;
  double t219, t225, t244, t246, t249, t252, t259, t260;
  double t261, t263, t267, t283, t286, t289, t324, t335;
  double t364;

  lda_c_chachiyo_params *params;

  assert(p->params != NULL);
  params = (lda_c_chachiyo_params * )(p->params);

  t1 = M_CBRT3;
  t2 = t1 * t1;
  t3 = params->bp * t2;
  t5 = POW_1_3(0.1e1 / M_PI);
  t7 = M_CBRT4;
  t8 = 0.1e1 / t5 * t7;
  t9 = rho[0] + rho[1];
  t10 = POW_1_3(t9);
  t11 = t8 * t10;
  t14 = params->bp * t1;
  t15 = t5 * t5;
  t17 = t7 * t7;
  t18 = 0.1e1 / t15 * t17;
  t19 = t10 * t10;
  t20 = t18 * t19;
  t23 = 0.1e1 + t3 * t11 / 0.3e1 + t14 * t20 / 0.3e1;
  t24 = log(t23);
  t25 = params->ap * t24;
  t26 = params->bf * t2;
  t29 = params->bf * t1;
  t32 = 0.1e1 + t26 * t11 / 0.3e1 + t29 * t20 / 0.3e1;
  t33 = log(t32);
  t35 = params->af * t33 - t25;
  t36 = rho[0] - rho[1];
  t37 = 0.1e1 / t9;
  t38 = t36 * t37;
  t39 = 0.1e1 + t38;
  t40 = POW_1_3(t39);
  t42 = 0.1e1 - t38;
  t43 = POW_1_3(t42);
  t45 = t40 * t39 + t43 * t42 - 0.2e1;
  t47 = M_CBRT2;
  t50 = 0.1e1 / (0.2e1 * t47 - 0.2e1);
  t51 = t35 * t45 * t50;
  if(zk != NULL && (p->info->flags & XC_FLAGS_HAVE_EXC))
    *zk = t25 + t51;

#ifndef XC_DONT_COMPILE_VXC

  if(order < 1) return;


  t53 = t8 / t19;
  t57 = t18 / t10;
  t60 = t3 * t53 / 0.9e1 + 0.2e1 / 0.9e1 * t14 * t57;
  t62 = 0.1e1 / t23;
  t63 = params->ap * t60 * t62;
  t68 = t26 * t53 / 0.9e1 + 0.2e1 / 0.9e1 * t29 * t57;
  t70 = 0.1e1 / t32;
  t72 = params->af * t68 * t70 - t63;
  t74 = t72 * t45 * t50;
  t75 = t9 * t9;
  t76 = 0.1e1 / t75;
  t77 = t36 * t76;
  t78 = t37 - t77;
  t80 = -t78;
  t83 = 0.4e1 / 0.3e1 * t40 * t78 + 0.4e1 / 0.3e1 * t43 * t80;
  t85 = t35 * t83 * t50;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[0] = t25 + t51 + t9 * (t63 + t74 + t85);

  t88 = -t37 - t77;
  t90 = -t88;
  t93 = 0.4e1 / 0.3e1 * t40 * t88 + 0.4e1 / 0.3e1 * t43 * t90;
  t95 = t35 * t93 * t50;
  if(vrho != NULL && (p->info->flags & XC_FLAGS_HAVE_VXC))
    vrho[1] = t25 + t51 + t9 * (t63 + t74 + t95);

#ifndef XC_DONT_COMPILE_FXC

  if(order < 2) return;


  t98 = 0.2e1 * t63;
  t99 = 0.2e1 * t74;
  t103 = t8 / t19 / t9;
  t107 = t18 / t10 / t9;
  t111 = params->ap * (-0.2e1 / 0.27e2 * t3 * t103 - 0.2e1 / 0.27e2 * t14 * t107);
  t112 = t111 * t62;
  t113 = t60 * t60;
  t115 = t23 * t23;
  t116 = 0.1e1 / t115;
  t117 = params->ap * t113 * t116;
  t122 = params->af * (-0.2e1 / 0.27e2 * t26 * t103 - 0.2e1 / 0.27e2 * t29 * t107);
  t124 = t68 * t68;
  t126 = t32 * t32;
  t127 = 0.1e1 / t126;
  t129 = -params->af * t124 * t127 + t122 * t70 - t112 + t117;
  t131 = t129 * t45 * t50;
  t133 = t72 * t83 * t50;
  t134 = 0.2e1 * t133;
  t135 = t40 * t40;
  t136 = 0.1e1 / t135;
  t137 = t78 * t78;
  t141 = 0.1e1 / t75 / t9;
  t142 = t36 * t141;
  t144 = -0.2e1 * t76 + 0.2e1 * t142;
  t147 = t43 * t43;
  t148 = 0.1e1 / t147;
  t149 = t80 * t80;
  t152 = -t144;
  t155 = 0.4e1 / 0.9e1 * t136 * t137 + 0.4e1 / 0.3e1 * t40 * t144 + 0.4e1 / 0.9e1 * t148 * t149 + 0.4e1 / 0.3e1 * t43 * t152;
  t157 = t35 * t155 * t50;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[0] = t98 + t99 + 0.2e1 * t85 + t9 * (t112 - t117 + t131 + t134 + t157);

  t161 = t72 * t93 * t50;
  t162 = t136 * t88;
  t165 = t40 * t36;
  t168 = t148 * t90;
  t171 = t43 * t36;
  t174 = 0.4e1 / 0.9e1 * t162 * t78 + 0.8e1 / 0.3e1 * t165 * t141 + 0.4e1 / 0.9e1 * t168 * t80 - 0.8e1 / 0.3e1 * t171 * t141;
  t176 = t35 * t174 * t50;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[1] = t98 + t99 + t85 + t95 + t9 * (t112 - t117 + t131 + t133 + t161 + t176);

  t180 = 0.2e1 * t161;
  t181 = t88 * t88;
  t185 = 0.2e1 * t76 + 0.2e1 * t142;
  t188 = t90 * t90;
  t191 = -t185;
  t194 = 0.4e1 / 0.9e1 * t136 * t181 + 0.4e1 / 0.3e1 * t40 * t185 + 0.4e1 / 0.9e1 * t148 * t188 + 0.4e1 / 0.3e1 * t43 * t191;
  t196 = t35 * t194 * t50;
  if(v2rho2 != NULL && (p->info->flags & XC_FLAGS_HAVE_FXC))
    v2rho2[2] = t98 + t99 + 0.2e1 * t95 + t9 * (t112 - t117 + t131 + t180 + t196);

#ifndef XC_DONT_COMPILE_KXC

  if(order < 3) return;


  t199 = 0.3e1 * t112;
  t200 = 0.3e1 * t117;
  t201 = 0.3e1 * t131;
  t206 = t8 / t19 / t75;
  t211 = t18 / t10 / t75;
  t216 = params->ap * (0.10e2 / 0.81e2 * t3 * t206 + 0.8e1 / 0.81e2 * t14 * t211) * t62;
  t219 = 0.3e1 * t111 * t116 * t60;
  t225 = 0.2e1 * params->ap * t113 * t60 / t115 / t23;
  t244 = (params->af * (0.10e2 / 0.81e2 * t26 * t206 + 0.8e1 / 0.81e2 * t29 * t211) * t70 - 0.3e1 * t122 * t127 * t68 + 0.2e1 * params->af * t124 * t68 / t126 / t32 - t216 + t219 - t225) * t45 * t50;
  t246 = t129 * t83 * t50;
  t249 = t72 * t155 * t50;
  t252 = 0.1e1 / t135 / t39;
  t259 = t75 * t75;
  t260 = 0.1e1 / t259;
  t261 = t36 * t260;
  t263 = 0.6e1 * t141 - 0.6e1 * t261;
  t267 = 0.1e1 / t147 / t42;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[0] = t199 - t200 + t201 + 0.6e1 * t133 + 0.3e1 * t157 + t9 * (t216 - t219 + t225 + t244 + 0.3e1 * t246 + 0.3e1 * t249 + t35 * (-0.8e1 / 0.27e2 * t252 * t137 * t78 + 0.4e1 / 0.3e1 * t136 * t78 * t144 + 0.4e1 / 0.3e1 * t40 * t263 - 0.8e1 / 0.27e2 * t267 * t149 * t80 + 0.4e1 / 0.3e1 * t148 * t80 * t152 - 0.4e1 / 0.3e1 * t43 * t263) * t50);

  t283 = 0.2e1 * t176;
  t286 = t129 * t93 * t50;
  t289 = 0.2e1 * t72 * t174 * t50;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[1] = t199 - t200 + t201 + 0.4e1 * t133 + t157 + t180 + t283 + t9 * (t216 - t219 + t225 + t244 + 0.2e1 * t246 + t249 + t286 + t289 + t35 * (-0.8e1 / 0.27e2 * t252 * t88 * t137 + 0.16e2 / 0.9e1 * t136 * t36 * t141 * t78 + 0.4e1 / 0.9e1 * t162 * t144 + 0.8e1 / 0.3e1 * t40 * t141 - 0.8e1 * t165 * t260 - 0.8e1 / 0.27e2 * t267 * t90 * t149 - 0.16e2 / 0.9e1 * t148 * t36 * t141 * t80 + 0.4e1 / 0.9e1 * t168 * t152 - 0.8e1 / 0.3e1 * t43 * t141 + 0.8e1 * t171 * t260) * t50);

  t324 = t72 * t194 * t50;
  t335 = -0.2e1 * t141 - 0.6e1 * t261;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[2] = t199 - t200 + t201 + t134 + 0.4e1 * t161 + t283 + t196 + t9 * (t216 - t219 + t225 + t244 + t246 + 0.2e1 * t286 + t289 + t324 + t35 * (-0.8e1 / 0.27e2 * t252 * t181 * t78 + 0.16e2 / 0.9e1 * t162 * t142 + 0.4e1 / 0.9e1 * t136 * t185 * t78 + 0.4e1 / 0.3e1 * t40 * t335 - 0.8e1 / 0.27e2 * t267 * t188 * t80 - 0.16e2 / 0.9e1 * t168 * t142 + 0.4e1 / 0.9e1 * t148 * t191 * t80 - 0.4e1 / 0.3e1 * t43 * t335) * t50);

  t364 = -0.6e1 * t141 - 0.6e1 * t261;
  if(v3rho3 != NULL && (p->info->flags & XC_FLAGS_HAVE_KXC))
    v3rho3[3] = t199 - t200 + t201 + 0.6e1 * t161 + 0.3e1 * t196 + t9 * (t216 - t219 + t225 + t244 + 0.3e1 * t286 + 0.3e1 * t324 + t35 * (-0.8e1 / 0.27e2 * t252 * t181 * t88 + 0.4e1 / 0.3e1 * t162 * t185 + 0.4e1 / 0.3e1 * t40 * t364 - 0.8e1 / 0.27e2 * t267 * t188 * t90 + 0.4e1 / 0.3e1 * t168 * t191 - 0.4e1 / 0.3e1 * t43 * t364) * t50);

#ifndef XC_DONT_COMPILE_LXC

  if(order < 4) return;


#endif

#endif

#endif

#endif


}

