#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <math.h>
#include <stdio.h>

__global__ void calculate(double *a,double *b)
{
    int i = threadIdx.x;
    b[i] = sin(a[i]);
}

int main()
{
    double *a,*b;
    double *da,*db;
    int n;
    printf("Enter array size : \t");
    scanf("%d",&n);
    a = (double *)malloc(n*sizeof(double));
    b = (double *)malloc(n*sizeof(double));
    for(int i=0;i<n;i++)
    {
        a[i] = i*3.14/180.0;
    }
    cudaMalloc((void **)&da,n*sizeof(double));
    cudaMalloc((void **)&db,n*sizeof(double));
    cudaMemcpy(da,a,n*sizeof(double),cudaMemcpyHostToDevice);
    calculate<<<1,n>>>(da,db);
    cudaMemcpy(b,db,n*sizeof(double),cudaMemcpyDeviceToHost);
    for(int i=0;i<n;i++)
    {
        printf("%lf\n",b[i]);
    }
    cudaFree(da);
    cudaFree(db);
    return 0;
}