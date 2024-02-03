#include <stdio.h>
#include <stdlib.h>
#include <CL/cl.h>

#define MAX_SOURCE_SIZE (0x100000)

int main(void)
{
    int i;
    int n;
    printf("Enter how many elements : \t");
    scanf("%d",&n);
    int A[n],B[n];
    for(i=0;i<n;i++)
    {
        A[i] = i;
        B[i] = i+10;
    }
    FILE *fp;
    char *source;
    size_t size;
    fp = fopen("vectorCLKernel.cl","r");
    if(!fp)
    {
        printf("Failed to load kernel\n");
        exit(1);
    }
    source = (char*)malloc(MAX_SOURCE_SIZE);
    size = fread(source,1,MAX_SOURCE_SIZE,fp);
    fclose(fp);
    cl_platform_id pid = NULL;
    cl_device_id did = NULL;
    cl_uint numDevices,numPlatforms;
    cl_int ret = clGetPlatformIDs(1,&pid,&numPlatforms);
    ret = clGetDeviceIDs(pid,CL_DEVICE_TYPE_GPU,1,&did,&numDevices);
    cl_context context = clCreateContext(NULL,1,&did,NULL,NULL,&ret);
    cl_command_queue queue = clCreateCommandQueue(context,did,NULL,&ret);
    cl_mem A_mem = clCreateBuffer(context,CL_MEM_READ_ONLY,n*sizeof(int),NULL,&ret);
    cl_mem B_mem = clCreateBuffer(context,CL_MEM_READ_ONLY,n*sizeof(int),NULL,&ret);
    cl_mem C_mem = clCreateBuffer(context,CL_MEM_WRITE_ONLY,n*sizeof(int),NULL,&ret);
    ret = clEnqueueWriteBuffer(queue,A_mem,CL_TRUE,0,n*sizeof(int),A,0,NULL,NULL);
    ret = clEnqueueWriteBuffer(queue,B_mem,CL_TRUE,0,n*sizeof(int),B,0,NULL,NULL);
    cl_program program = clCreateProgramWithSource(context,1,(const char**)&source,(const size_t*)&size,&ret);
    ret = clBuildProgram(program,1,&did,NULL,NULL,NULL);
    cl_kernel kernel = clCreateKernel(program,"vector_add",&ret);
    ret = clSetKernelArg(kernel,0,sizeof(cl_mem),(void*)&A_mem);
    ret = clSetKernelArg(kernel,1,sizeof(cl_mem),(void*)&B_mem);
    ret = clSetKernelArg(kernel,2,sizeof(cl_mem),(void*)&C_mem);
    size_t globalSize = n;
    size_t localSize = 1;
    cl_event event;
    ret = clEnqueueNDRangeKernel(queue,kernel,1,NULL,&globalSize,&localSize,0,NULL,NULL);
    ret = clFinish(queue);
    int C[n];
    ret = clEnqueueReadBuffer(queue,C_mem,CL_TRUE,0,n*sizeof(int),C,0,NULL,NULL);
    for(i=0;i<n;i++)
    {
        printf("%d + %d = %d\n",A[i],B[i],C[i]);
    }
    ret = clFlush(queue);
    ret = clReleaseKernel(kernel);
    ret = clReleaseProgram(program);
    ret = clReleaseMemObject(A_mem);
    ret = clReleaseMemObject(B_mem);
    ret = clReleaseMemObject(C_mem);
    ret = clReleaseCommandQueue(queue);
    ret = clReleaseContext(context);
    return 0;
}