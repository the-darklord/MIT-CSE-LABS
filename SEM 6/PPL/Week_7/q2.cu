#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>

__global__ void add(int *a,int *b,int *c)
{
    int i = threadIdx.x + blockDim.x*blockIdx.x;
    c[i] = a[i] + b[i];
}

int main(void)
{
    int *a,*b,*c;
    int *da,*db,*dc;
    int n = 512;
    int size = n*sizeof(int);
    a = (int*)malloc(size);
    b = (int*)malloc(size);
    c = (int*)malloc(size);
    for(int i=0;i<n;i++)
    {
        a[i] = i;
        b[i] = n-i;
    }
    cudaMalloc((void**)&da,size);
    cudaMalloc((void**)&db,size);
    cudaMalloc((void**)&dc,size);
    cudaMemcpy(da,a,size,cudaMemcpyHostToDevice);
    cudaMemcpy(db,b,size,cudaMemcpyHostToDevice);
    add<<<2,256>>>(da,db,dc);
    cudaMemcpy(c,dc,size,cudaMemcpyDeviceToHost);
    printf("Result : \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",c[i]);
    }
    printf("\n");
    cudaFree(da);
    cudaFree(db);
    cudaFree(dc);
    return 0;
}