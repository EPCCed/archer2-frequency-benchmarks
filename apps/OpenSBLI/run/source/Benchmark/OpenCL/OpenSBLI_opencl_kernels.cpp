//
// auto-generated by ops.py//

//header
#define OPS_ACC_MD_MACROS
#define OPS_3D
#include "stdlib.h"
#include "stdio.h"
#include "ops_lib_cpp.h"
#include "ops_opencl_rt_support.h"
#ifdef OPS_MPI
#include "ops_mpi_core.h"
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

extern ops_opencl_core OPS_opencl_core;

//this needs to be a platform specific copy symbol to device function
void ops_decl_const_char( int dim, char const * type, int typeSize, char * dat, char const * name ) {
  cl_int ret = 0;
  if (OPS_opencl_core.constant == NULL) {
    OPS_opencl_core.constant = (cl_mem*) malloc((27)*sizeof(cl_mem));
    for ( int i=0; i<27; i++ ){
      OPS_opencl_core.constant[i] = NULL;
    }
  }
  if (!strcmp(name,"nx2")) {
    if (OPS_opencl_core.constant[0] == NULL) {
      OPS_opencl_core.constant[0] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[0], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"nx1")) {
    if (OPS_opencl_core.constant[1] == NULL) {
      OPS_opencl_core.constant[1] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[1], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"deltai2")) {
    if (OPS_opencl_core.constant[2] == NULL) {
      OPS_opencl_core.constant[2] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[2], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"rinv9")) {
    if (OPS_opencl_core.constant[3] == NULL) {
      OPS_opencl_core.constant[3] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[3], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"Minf")) {
    if (OPS_opencl_core.constant[4] == NULL) {
      OPS_opencl_core.constant[4] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[4], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"rinv1")) {
    if (OPS_opencl_core.constant[5] == NULL) {
      OPS_opencl_core.constant[5] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[5], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"rinv4")) {
    if (OPS_opencl_core.constant[6] == NULL) {
      OPS_opencl_core.constant[6] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[6], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"rinv5")) {
    if (OPS_opencl_core.constant[7] == NULL) {
      OPS_opencl_core.constant[7] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[7], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"rinv6")) {
    if (OPS_opencl_core.constant[8] == NULL) {
      OPS_opencl_core.constant[8] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[8], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"Pr")) {
    if (OPS_opencl_core.constant[9] == NULL) {
      OPS_opencl_core.constant[9] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[9], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"rinv12")) {
    if (OPS_opencl_core.constant[10] == NULL) {
      OPS_opencl_core.constant[10] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[10], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"rinv13")) {
    if (OPS_opencl_core.constant[11] == NULL) {
      OPS_opencl_core.constant[11] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[11], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"rinv10")) {
    if (OPS_opencl_core.constant[12] == NULL) {
      OPS_opencl_core.constant[12] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[12], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"rinv11")) {
    if (OPS_opencl_core.constant[13] == NULL) {
      OPS_opencl_core.constant[13] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[13], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"rc8")) {
    if (OPS_opencl_core.constant[14] == NULL) {
      OPS_opencl_core.constant[14] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[14], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"rinv14")) {
    if (OPS_opencl_core.constant[15] == NULL) {
      OPS_opencl_core.constant[15] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[15], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"rinv15")) {
    if (OPS_opencl_core.constant[16] == NULL) {
      OPS_opencl_core.constant[16] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[16], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"rc7")) {
    if (OPS_opencl_core.constant[17] == NULL) {
      OPS_opencl_core.constant[17] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[17], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"rc0")) {
    if (OPS_opencl_core.constant[18] == NULL) {
      OPS_opencl_core.constant[18] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[18], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"rc2")) {
    if (OPS_opencl_core.constant[19] == NULL) {
      OPS_opencl_core.constant[19] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[19], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"rc3")) {
    if (OPS_opencl_core.constant[20] == NULL) {
      OPS_opencl_core.constant[20] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[20], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"nx0")) {
    if (OPS_opencl_core.constant[21] == NULL) {
      OPS_opencl_core.constant[21] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[21], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"deltai1")) {
    if (OPS_opencl_core.constant[22] == NULL) {
      OPS_opencl_core.constant[22] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[22], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"deltai0")) {
    if (OPS_opencl_core.constant[23] == NULL) {
      OPS_opencl_core.constant[23] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[23], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"Re")) {
    if (OPS_opencl_core.constant[24] == NULL) {
      OPS_opencl_core.constant[24] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[24], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"deltat")) {
    if (OPS_opencl_core.constant[25] == NULL) {
      OPS_opencl_core.constant[25] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[25], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"gama")) {
    if (OPS_opencl_core.constant[26] == NULL) {
      OPS_opencl_core.constant[26] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[26], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  {
    printf("error: unknown const name\n"); exit(1);
  }
}

extern ops_opencl_core OPS_opencl_core;

void buildOpenCLKernels() {
  static bool isbuilt = false;

  if(!isbuilt) {
    //clSafeCall( clUnloadCompiler() );

    OPS_opencl_core.n_kernels = 17;
    OPS_opencl_core.kernel = (cl_kernel*) malloc(17*sizeof(cl_kernel));
  }
  isbuilt = true;
}

//user kernel files
#include "taylor_green_vortex_block0_16_kernel_opencl_kernel.cpp"
#include "taylor_green_vortex_block0_15_kernel_opencl_kernel.cpp"
#include "taylor_green_vortex_block0_0_kernel_opencl_kernel.cpp"
#include "taylor_green_vortex_block0_3_kernel_opencl_kernel.cpp"
#include "taylor_green_vortex_block0_4_kernel_opencl_kernel.cpp"
#include "taylor_green_vortex_block0_5_kernel_opencl_kernel.cpp"
#include "taylor_green_vortex_block0_6_kernel_opencl_kernel.cpp"
#include "taylor_green_vortex_block0_7_kernel_opencl_kernel.cpp"
#include "taylor_green_vortex_block0_8_kernel_opencl_kernel.cpp"
#include "taylor_green_vortex_block0_9_kernel_opencl_kernel.cpp"
#include "taylor_green_vortex_block0_10_kernel_opencl_kernel.cpp"
#include "taylor_green_vortex_block0_11_kernel_opencl_kernel.cpp"
#include "taylor_green_vortex_block0_12_kernel_opencl_kernel.cpp"
#include "taylor_green_vortex_block0_13_kernel_opencl_kernel.cpp"
#include "taylor_green_vortex_block0_14_kernel_opencl_kernel.cpp"
#include "taylor_green_vortex_block0_17_kernel_opencl_kernel.cpp"
#include "taylor_green_vortex_block0_18_kernel_opencl_kernel.cpp"
