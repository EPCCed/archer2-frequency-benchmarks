//
// auto-generated by ops.py//

//header
#define OPS_3D
#define OPS_ACC_MD_MACROS
#include "ops_lib_cpp.h"
#ifdef OPS_MPI
#include "ops_mpi_core.h"
#endif

//set max number of OMP threads for reductions
#ifndef MAX_REDUCT_THREADS
#define MAX_REDUCT_THREADS 64
#endif
//global constants
extern int nx2;
extern int nx1;
extern double deltai2;
extern double rinv9;
extern double Minf;
extern double rinv1;
extern double rinv4;
extern double rinv5;
extern double rinv6;
extern double Pr;
extern double rinv12;
extern double rinv13;
extern double rinv10;
extern double rinv11;
extern double rc8;
extern double rinv14;
extern double rinv15;
extern double rc7;
extern double rc0;
extern double rc2;
extern double rc3;
extern int nx0;
extern double deltai1;
extern double deltai0;
extern double Re;
extern double deltat;
extern double gama;

//user kernel files
#include "taylor_green_vortex_block0_16_kernel_omp_kernel.cpp"
#include "taylor_green_vortex_block0_15_kernel_omp_kernel.cpp"
#include "taylor_green_vortex_block0_0_kernel_omp_kernel.cpp"
#include "taylor_green_vortex_block0_3_kernel_omp_kernel.cpp"
#include "taylor_green_vortex_block0_4_kernel_omp_kernel.cpp"
#include "taylor_green_vortex_block0_5_kernel_omp_kernel.cpp"
#include "taylor_green_vortex_block0_6_kernel_omp_kernel.cpp"
#include "taylor_green_vortex_block0_7_kernel_omp_kernel.cpp"
#include "taylor_green_vortex_block0_8_kernel_omp_kernel.cpp"
#include "taylor_green_vortex_block0_9_kernel_omp_kernel.cpp"
#include "taylor_green_vortex_block0_10_kernel_omp_kernel.cpp"
#include "taylor_green_vortex_block0_11_kernel_omp_kernel.cpp"
#include "taylor_green_vortex_block0_12_kernel_omp_kernel.cpp"
#include "taylor_green_vortex_block0_13_kernel_omp_kernel.cpp"
#include "taylor_green_vortex_block0_14_kernel_omp_kernel.cpp"
#include "taylor_green_vortex_block0_17_kernel_omp_kernel.cpp"
#include "taylor_green_vortex_block0_18_kernel_omp_kernel.cpp"
