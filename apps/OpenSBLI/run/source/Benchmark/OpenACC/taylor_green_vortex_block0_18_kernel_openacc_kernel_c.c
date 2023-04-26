//
// auto-generated by ops.py
//
#include "./OpenACC/OpenSBLI_common.h"

#define OPS_GPU

int xdim0_taylor_green_vortex_block0_18_kernel;
int ydim0_taylor_green_vortex_block0_18_kernel;
int xdim1_taylor_green_vortex_block0_18_kernel;
int ydim1_taylor_green_vortex_block0_18_kernel;
int xdim2_taylor_green_vortex_block0_18_kernel;
int ydim2_taylor_green_vortex_block0_18_kernel;
int xdim3_taylor_green_vortex_block0_18_kernel;
int ydim3_taylor_green_vortex_block0_18_kernel;


#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3


#define OPS_ACC0(x,y,z) (x+xdim0_taylor_green_vortex_block0_18_kernel*(y)+xdim0_taylor_green_vortex_block0_18_kernel*ydim0_taylor_green_vortex_block0_18_kernel*(z))
#define OPS_ACC1(x,y,z) (x+xdim1_taylor_green_vortex_block0_18_kernel*(y)+xdim1_taylor_green_vortex_block0_18_kernel*ydim1_taylor_green_vortex_block0_18_kernel*(z))
#define OPS_ACC2(x,y,z) (x+xdim2_taylor_green_vortex_block0_18_kernel*(y)+xdim2_taylor_green_vortex_block0_18_kernel*ydim2_taylor_green_vortex_block0_18_kernel*(z))
#define OPS_ACC3(x,y,z) (x+xdim3_taylor_green_vortex_block0_18_kernel*(y)+xdim3_taylor_green_vortex_block0_18_kernel*ydim3_taylor_green_vortex_block0_18_kernel*(z))

//user function
inline
 void taylor_green_vortex_block0_18_kernel(const double *u0 , const double *u1 , const double *u2 , const double *rho ,
double *ke , double *enstrophy , double *rhomean)
{
    double temp_eval0 = rinv5*((rc2)*u1[OPS_ACC1(-2,0,0)] - rc3*u1[OPS_ACC1(-1,0,0)] + (rc3)*u1[OPS_ACC1(1,0,0)] -
      rc2*u1[OPS_ACC1(2,0,0)]);
    double temp_eval1 = rinv4*((rc2)*u0[OPS_ACC0(0,-2,0)] - rc3*u0[OPS_ACC0(0,-1,0)] + (rc3)*u0[OPS_ACC0(0,1,0)] -
      rc2*u0[OPS_ACC0(0,2,0)]);
    double temp_eval2 = rinv4*((rc2)*u2[OPS_ACC2(0,-2,0)] - rc3*u2[OPS_ACC2(0,-1,0)] + (rc3)*u2[OPS_ACC2(0,1,0)] -
      rc2*u2[OPS_ACC2(0,2,0)]);
    double temp_eval3 = rinv1*((rc2)*u0[OPS_ACC0(0,0,-2)] - rc3*u0[OPS_ACC0(0,0,-1)] + (rc3)*u0[OPS_ACC0(0,0,1)] -
      rc2*u0[OPS_ACC0(0,0,2)]);
    double temp_eval4 = rinv5*((rc2)*u2[OPS_ACC2(-2,0,0)] - rc3*u2[OPS_ACC2(-1,0,0)] + (rc3)*u2[OPS_ACC2(1,0,0)] -
      rc2*u2[OPS_ACC2(2,0,0)]);
    double temp_eval5 = rinv1*((rc2)*u1[OPS_ACC1(0,0,-2)] - rc3*u1[OPS_ACC1(0,0,-1)] + (rc3)*u1[OPS_ACC1(0,0,1)] -
      rc2*u1[OPS_ACC1(0,0,2)]);
    *ke = *ke + (rc0)*(pow(u0[OPS_ACC0(0,0,0)], 2) + pow(u1[OPS_ACC1(0,0,0)], 2) + pow(u2[OPS_ACC2(0,0,0)],
      2))*rho[OPS_ACC3(0,0,0)];
    *enstrophy = *enstrophy + (rc0)*(pow(temp_eval0 - temp_eval1, 2) + pow(temp_eval2 - temp_eval5, 2) + pow(temp_eval3
      - temp_eval4, 2))*rho[OPS_ACC3(0,0,0)];
   *rhomean = *rhomean + rho[OPS_ACC3(0,0,0)];
}


#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3



void taylor_green_vortex_block0_18_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  double *p_a4,
  double *p_a5,
  double *p_a6,
  int x_size, int y_size, int z_size) {
  double p_a4_0 = p_a4[0];
  double p_a5_0 = p_a5[0];
  double p_a6_0 = p_a6[0];
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2,p_a3) reduction(+:p_a4_0) reduction(+:p_a5_0) reduction(+:p_a6_0)
  #pragma acc loop reduction(+:p_a4_0) reduction(+:p_a5_0) reduction(+:p_a6_0)
  #endif
  for ( int n_z=0; n_z<z_size; n_z++ ){
    #ifdef OPS_GPU
    #pragma acc loop reduction(+:p_a4_0) reduction(+:p_a5_0) reduction(+:p_a6_0)
    #endif
    for ( int n_y=0; n_y<y_size; n_y++ ){
      #ifdef OPS_GPU
      #pragma acc loop reduction(+:p_a4_0) reduction(+:p_a5_0) reduction(+:p_a6_0)
      #endif
      for ( int n_x=0; n_x<x_size; n_x++ ){
        taylor_green_vortex_block0_18_kernel(  p_a0 + n_x*1*1 + n_y*xdim0_taylor_green_vortex_block0_18_kernel*1*1 + n_z*xdim0_taylor_green_vortex_block0_18_kernel*ydim0_taylor_green_vortex_block0_18_kernel*1,
           p_a1 + n_x*1*1 + n_y*xdim1_taylor_green_vortex_block0_18_kernel*1*1 + n_z*xdim1_taylor_green_vortex_block0_18_kernel*ydim1_taylor_green_vortex_block0_18_kernel*1,
           p_a2 + n_x*1*1 + n_y*xdim2_taylor_green_vortex_block0_18_kernel*1*1 + n_z*xdim2_taylor_green_vortex_block0_18_kernel*ydim2_taylor_green_vortex_block0_18_kernel*1,
           p_a3 + n_x*1*1 + n_y*xdim3_taylor_green_vortex_block0_18_kernel*1*1 + n_z*xdim3_taylor_green_vortex_block0_18_kernel*ydim3_taylor_green_vortex_block0_18_kernel*1,
           &p_a4_0,
           &p_a5_0,
           &p_a6_0 );

      }
    }
  }
  p_a4[0] = p_a4_0;
  p_a5[0] = p_a5_0;
  p_a6[0] = p_a6_0;
}
