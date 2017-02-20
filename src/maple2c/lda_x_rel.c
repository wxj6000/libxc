/* 
  This file was generated automatically with ../scripts/maple2c.pl.
  Do not edit this file directly as it can be overwritten!!

  Maple source      : ../maple/lda_x_rel.mpl
  Type of functional: work_lda
*/

static void
func0(const XC(func_type) *p, XC(lda_work_t) *r)
{
  double t1, t2, t3, t4, t5, t6, t10, t13;
  double t14, t16, t21, t22, t26, t27, t28, t32;
  double t36, t39, t42, t46, t47, t55, t61, t64;
  double t77, t80, t85, t90;


  t1 = 0.1e1 / r->rs;
  t2 = r->rs * r->rs;
  t3 = 0.1e1 / t2;
  t4 = 0.19613371278049345815e-3 * t3;
  t5 = 0.10e1 + t4;
  t6 = sqrt(t5);
  t10 = log(0.14004774642260169484e-1 * t1 + sqrt(pow(0.14004774642260169484e-1 * t1, 0.2e1) + 0.1e1));
  t13 = 0.71404219314064903973e2 * t6 * r->rs - 0.50985625358510794657e4 * t10 * t2;
  t14 = t13 * t13;
  t16 = 0.10e1 - 0.15e1 * t14;
  r->f = -0.45816529328314289346e0 * t1 * t16;

  if(r->order < 1) return;

  t21 = t1 * t13;
  t22 = 0.1e1 / t6;
  t26 = t4 + 0.1e1;
  t27 = sqrt(t26);
  t28 = 0.1e1 / t27;
  t32 = -0.14004774642260169484e-1 * t22 * t3 + 0.71404219314064903973e2 * t6 + 0.71404219314064903974e2 * t28 - 0.10197125071702158931e5 * t10 * r->rs;
  r->dfdrs = 0.45816529328314289346e0 * t3 * t16 + 0.13744958798494286804e1 * t21 * t32;
  r->dfdz = 0;

  if(r->order < 2) return;

  t36 = 0.1e1 / t2 / r->rs;
  t39 = t3 * t13;
  t42 = t32 * t32;
  t46 = 0.1e1 / t6 / t5;
  t47 = t2 * t2;
  t55 = 0.1e1 / t27 / t26;
  t61 = -0.27468084472405941018e-5 * t46 / t47 / r->rs + 0.14004774642260169484e-1 * t22 * t36 + 0.14004774642260169484e-1 * t55 * t36 + 0.14280843862812980794e3 * t1 * t28 - 0.10197125071702158931e5 * t10;
  r->d2fdrs2 = -0.91633058656628578692e0 * t36 * t16 - 0.27489917596988573608e1 * t39 * t32 + 0.13744958798494286804e1 * t1 * t42 + 0.13744958798494286804e1 * t21 * t61;
  r->d2fdrsz = 0;
  r->d2fdz2 = 0;

  if(r->order < 3) return;

  t64 = 0.1e1 / t47;
  t77 = t5 * t5;
  t80 = t47 * t47;
  t85 = 0.1e1 / t47 / t2;
  t90 = t26 * t26;
  r->d3fdrs3 = 0.27489917596988573608e1 * t64 * t16 + 0.82469752790965720824e1 * t36 * t13 * t32 - 0.41234876395482860412e1 * t3 * t42 - 0.41234876395482860412e1 * t39 * t61 + 0.41234876395482860412e1 * t1 * t32 * t61 + 0.13744958798494286804e1 * t21 * (-0.16162252171623597064e-8 / t6 / t77 / t80 + 0.16480850683443564611e-4 * t46 * t85 - 0.42014323926780508452e-1 * t22 * t64 + 0.82404253417217823054e-5 / t27 / t90 * t85 - 0.14004774642260169485e-1 * t55 * t64);
  r->d3fdrs2z = 0;
  r->d3fdrsz2 = 0;
  r->d3fdz3 = 0;

  if(r->order < 4) return;


}

static void
func1(const XC(func_type) *p, XC(lda_work_t) *r)
{
  double t1, t2, t3, t4, t5, t6, t7, t8;
  double t9, t10, t11, t12, t16, t19, t20, t22;
  double t25, t28, t32, t33, t34, t38, t39, t42;
  double t44, t46, t47, t51, t52, t57, t61, t62;
  double t70, t76, t77, t80, t85, t87, t89, t90;
  double t93, t106, t109, t114, t119, t144, t146;


  t1 = 0.10e1 + r->z;
  t2 = pow(t1, 0.13333333333333333333e1);
  t3 = 0.10e1 - r->z;
  t4 = pow(t3, 0.13333333333333333333e1);
  t5 = t2 + t4;
  t6 = 0.1e1 / r->rs;
  t7 = t5 * t6;
  t8 = r->rs * r->rs;
  t9 = 0.1e1 / t8;
  t10 = 0.19613371278049345815e-3 * t9;
  t11 = 0.10e1 + t10;
  t12 = sqrt(t11);
  t16 = log(0.14004774642260169484e-1 * t6 + sqrt(pow(0.14004774642260169484e-1 * t6, 0.2e1) + 0.1e1));
  t19 = 0.71404219314064903973e2 * t12 * r->rs - 0.50985625358510794657e4 * t16 * t8;
  t20 = t19 * t19;
  t22 = 0.10e1 - 0.15e1 * t20;
  r->f = -0.22908264664157144673e0 * t7 * t22;

  if(r->order < 1) return;

  t25 = t5 * t9;
  t28 = 0.1e1 / t12;
  t32 = t10 + 0.1e1;
  t33 = sqrt(t32);
  t34 = 0.1e1 / t33;
  t38 = -0.14004774642260169484e-1 * t28 * t9 + 0.71404219314064903973e2 * t12 + 0.71404219314064903974e2 * t34 - 0.10197125071702158931e5 * t16 * r->rs;
  t39 = t19 * t38;
  r->dfdrs = 0.22908264664157144673e0 * t25 * t22 + 0.68724793992471434019e0 * t7 * t39;
  t42 = pow(t1, 0.3333333333333333333e0);
  t44 = pow(t3, 0.3333333333333333333e0);
  t46 = 0.13333333333333333333e1 * t42 - 0.13333333333333333333e1 * t44;
  t47 = t46 * t6;
  r->dfdz = -0.22908264664157144673e0 * t47 * t22;

  if(r->order < 2) return;

  t51 = 0.1e1 / t8 / r->rs;
  t52 = t5 * t51;
  t57 = t38 * t38;
  t61 = 0.1e1 / t12 / t11;
  t62 = t8 * t8;
  t70 = 0.1e1 / t33 / t32;
  t76 = -0.27468084472405941018e-5 * t61 / t62 / r->rs + 0.14004774642260169484e-1 * t28 * t51 + 0.14004774642260169484e-1 * t70 * t51 + 0.14280843862812980794e3 * t6 * t34 - 0.10197125071702158931e5 * t16;
  t77 = t19 * t76;
  r->d2fdrs2 = -0.45816529328314289346e0 * t52 * t22 - 0.13744958798494286804e1 * t25 * t39 + 0.68724793992471434019e0 * t7 * t57 + 0.68724793992471434019e0 * t7 * t77;
  t80 = t46 * t9;
  r->d2fdrsz = 0.22908264664157144673e0 * t80 * t22 + 0.68724793992471434019e0 * t47 * t39;
  t85 = pow(t1, -0.6666666666666666667e0);
  t87 = pow(t3, -0.6666666666666666667e0);
  t89 = 0.44444444444444444439e0 * t85 + 0.44444444444444444439e0 * t87;
  t90 = t89 * t6;
  r->d2fdz2 = -0.22908264664157144673e0 * t90 * t22;

  if(r->order < 3) return;

  t93 = 0.1e1 / t62;
  t106 = t11 * t11;
  t109 = t62 * t62;
  t114 = 0.1e1 / t62 / t8;
  t119 = t32 * t32;
  r->d3fdrs3 = 0.13744958798494286804e1 * t5 * t93 * t22 + 0.41234876395482860412e1 * t52 * t39 - 0.20617438197741430206e1 * t25 * t57 - 0.20617438197741430206e1 * t25 * t77 + 0.20617438197741430206e1 * t7 * t38 * t76 + 0.68724793992471434019e0 * t7 * t19 * (-0.16162252171623597064e-8 / t12 / t106 / t109 + 0.16480850683443564611e-4 * t61 * t114 - 0.42014323926780508452e-1 * t28 * t93 + 0.82404253417217823054e-5 / t33 / t119 * t114 - 0.14004774642260169485e-1 * t70 * t93);
  r->d3fdrs2z = -0.45816529328314289346e0 * t46 * t51 * t22 - 0.13744958798494286804e1 * t80 * t39 + 0.68724793992471434019e0 * t47 * t57 + 0.68724793992471434019e0 * t47 * t77;
  r->d3fdrsz2 = 0.22908264664157144673e0 * t89 * t9 * t22 + 0.68724793992471434019e0 * t90 * t39;
  t144 = pow(t1, -0.16666666666666666667e1);
  t146 = pow(t3, -0.16666666666666666667e1);
  r->d3fdz3 = -0.22908264664157144673e0 * (-0.29629629629629629627e0 * t144 + 0.29629629629629629627e0 * t146) * t6 * t22;

  if(r->order < 4) return;


}

void 
XC(lda_x_rel_func)(const XC(func_type) *p, XC(lda_work_t) *r)
{
  if(p->nspin == XC_UNPOLARIZED)
    func0(p, r);
  else
    func1(p, r);
}

#define maple2c_order 3
#define maple2c_func  XC(lda_x_rel_func)
