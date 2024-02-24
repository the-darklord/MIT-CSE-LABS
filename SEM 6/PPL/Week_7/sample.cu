#include "cuda_runtime.h"
#include<stdio.h>
#include "device_launch_parameters.h"

__global__ void add(int *a,int *b,int *c)
{
    *c = *a + *b;
}

int main(void)
{
    int a,b,c;
    int *da,*db,*dc;
    int size = sizeof(int);

    cudaMalloc((void**)&da,size);
    cudaMalloc((void**)&db,size);
    cudaMalloc((void**)&dc,size);

    a=3;
    b=5;

    cudaMemcpy(da,&a,size,cudaMemcpyHostToDevice);
    cudaMemcpy(db,&b,size,cudaMemcpyHostToDevice);
    add<<<1,1>>>(da,db,dc);
    cudaMemcpy(&c,dc,size,cudaMemcpyDeviceToHost);
    printf("Result : %d\n",c);

    cudaFree(da);
    cudaFree(db);
    cudaFree(dc);

    return 0;
}