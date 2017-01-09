
void XC(gga_x_airy_enhance)
  (const XC(func_type) *p, int order, 
   FLOAT x, FLOAT *f, FLOAT *dfdx, FLOAT *d2fdx2, FLOAT *d3fdx3)
{
  double t1, t2, t4, t5, t8, t10, t12, t13;
  double t15, t16, t18, t22, t23, t27, t30, t33;
  double t35, t36, t37, t38, t39, t42, t44, t47;
  double t51, t52, t56, t59, t62, t64, t68, t69;
  double t70, t71, t74, t75, t78, t80, t83, t87;
  double t91, t92, t96, t99, t112, t115, t119, t123;


  if(order < 0) return;

  t1 = X2S * x;
  t2 = pow(t1, 0.2626712e1);
  t4 = 0.10e1 + 0.92070e-1 * t2;
  t5 = pow(t4, -0.657946e0);
  t8 = pow(t1, 0.3217063e1);
  t10 = pow(t1, 0.3223476e1);
  t12 = 0.10e1 - 0.133983631e3 * t8 + 0.136707378e3 * t10;
  t13 = pow(t1, 0.3473804e1);
  t15 = 0.1e1 + 0.2675484e1 * t13;
  t16 = 0.1e1 / t15;

  *f = 0.41106e-1 * t2 * t5 + t12 * t16;

  if(order < 0+1) return;

  t18 = pow(t1, 0.1626712e1);
  t22 = pow(t1, 0.4253424e1);
  t23 = pow(t4, -0.1657946e1);
  t27 = pow(t1, 0.2217063e1);
  t30 = pow(t1, 0.2223476e1);
  t33 = -0.431033781895753e3 * t27 * X2S + 0.440672952005928e3 * t30 * X2S;
  t35 = t15 * t15;
  t36 = 0.1e1 / t35;
  t37 = t12 * t36;
  t38 = pow(t1, 0.2473804e1);
  t39 = t38 * X2S;

  *dfdx = 0.107973623472e0 * t18 * t5 * X2S - 0.65407277144964066998e-2 * t22 * t23 * X2S + t33 * t16 - 0.9294107021136e1 * t37 * t39;

  if(order < 1+1) return;

  t42 = pow(t1, 0.626712e0);
  t44 = X2S * X2S;
  t47 = pow(t1, 0.3253424e1);
  t51 = pow(t1, 0.5880136e1);
  t52 = pow(t4, -0.2657946e1);
  t56 = pow(t1, 0.1217063e1);
  t59 = pow(t1, 0.1223476e1);
  t62 = -0.95562904959114383344e3 * t56 * t44 + 0.97982573263433276573e3 * t59 * t44;
  t64 = t33 * t36;
  t68 = 0.1e1 / t35 / t15;
  t69 = t12 * t68;
  t70 = pow(t1, 0.4947608e1);
  t71 = t70 * t44;
  t74 = pow(t1, 0.1473804e1);
  t75 = t74 * t44;

  *d2fdx2 = 0.175641988985384064e0 * t42 * t5 * t44 - 0.45001096214704449606e-1 * t47 * t23 * t44 + 0.26225697814468100489e-2 * t51 * t52 * t44 + t62 * t16 - 0.18588214042272e2 * t64 * t39 + 0.17276085064065898310e3 * t69 * t71 - 0.22991799125314321344e2 * t37 * t75;

  if(order < 2+1) return;

  t78 = pow(t1, -0.373288e0);
  t80 = t44 * X2S;
  t83 = pow(t1, 0.2253424e1);
  t87 = pow(t1, 0.4880136e1);
  t91 = pow(t1, 0.7506848e1);
  t92 = pow(t4, -0.3657946e1);
  t96 = pow(t1, 0.217063e0);
  t99 = pow(t1, 0.223476e0);
  t112 = t35 * t35;
  t115 = pow(t1, 0.7421412e1);
  t119 = pow(t1, 0.3947608e1);
  t123 = pow(t1, 0.473804e0);

  *d3fdx3 = 0.11007694220100801752e0 * t78 * t5 * t80 - 0.17435554761373467037e0 * t83 * t23 * t80 + 0.33464703750241849756e-1 * t87 * t52 * t80 - 0.16857912969353958325e-2 * t91 * t92 * t80 + (-0.11630607579825462874e4 * t96 * t80 + 0.11987932680605229149e4 * t99 * t80) * t16 - 0.27882321063408e2 * t62 * t36 * t39 + 0.51828255192197694930e3 * t33 * t68 * t71 - 0.68975397375942964032e2 * t64 * t75 - 0.48169735047503294358e4 * t12 / t112 * t115 * t80 + 0.12821294500747942651e4 * t69 * t119 * t80 - 0.33885405518084748054e2 * t37 * t123 * t80;

  if(order < 3+1) return;

}


#define maple2c_order 3
#define maple2c_func  XC(gga_x_airy_enhance)

