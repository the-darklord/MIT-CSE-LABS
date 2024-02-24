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
    int n;
    printf("Enter Array Size : \t");
    scanf("%d",&n);
    int size = n*sizeof(int);
    a = (int*)malloc(size);
    b = (int*)malloc(size);
    c = (int*)malloc(size);
    printf("\nEnter Array A : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nEnter Array B : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    cudaMalloc((void**)&da,size);
    cudaMalloc((void**)&db,size);
    cudaMalloc((void**)&dc,size);
    cudaMemcpy(da,a,size,cudaMemcpyHostToDevice);
    cudaMemcpy(db,b,size,cudaMemcpyHostToDevice);
    //Use either one
    //add<<<n,1>>>(da,db,dc); //block size as N
    //add<<<1,n>>>(da,db,dc); //N threads
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