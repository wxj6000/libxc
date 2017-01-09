
void XC(gga_x_rpbe_enhance)
  (const XC(func_type) *p, int order, 
   FLOAT x, FLOAT *f, FLOAT *dfdx, FLOAT *d2fdx2, FLOAT *d3fdx3)
{
  double t1, t2, t3, t4, t5, t7, t14, t15;
  double t16, t28;

  gga_x_rpbe_params *params;
 
  assert(p->params != NULL);
  params = (gga_x_rpbe_params * )(p->params);

  if(order < 0) return;

  t1 = X2S * X2S;
  t2 = params->mu * t1;
  t3 = x * x;
  t4 = 0.1e1 / params->kappa;
  t5 = t3 * t4;
  t7 = exp(-t2 * t5);

  *f = 0.10e1 + params->kappa * (0.10e1 - t7);

  if(order < 0+1) return;


  *dfdx = 0.2e1 * t2 * x * t7;

  if(order < 1+1) return;

  t14 = params->mu * params->mu;
  t15 = t1 * t1;
  t16 = t14 * t15;

  *d2fdx2 = -0.4e1 * t16 * t5 * t7 + 0.2e1 * t2 * t7;

  if(order < 2+1) return;

  t28 = params->kappa * params->kappa;

  *d3fdx3 = -0.12e2 * t16 * x * t4 * t7 + 0.8e1 * t14 * params->mu * t15 * t1 * t3 * x / t28 * t7;

  if(order < 3+1) return;

}


#define maple2c_order 3
#define maple2c_func  XC(gga_x_rpbe_enhance)

