#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>

__global__ void convolution(float *n,float *m,float *p,int *mWidth,int *width)
{
    int i = threadIdx.x + blockDim.x*blockIdx.x;
    float value = 0;
    int start = i - (*mWidth/2);
    for(int j=0;j<*mWidth;j++)
    {
        if(start+j>=0 && start+j<*width)
        {
            value += n[start+j]*m[j];
        }
    }
    p[i] = value;
}

int main(void)
{
    float *n,*m,*p;
    int width,mWidth;
    float *dn,*dm,*dp;
    int *dw,*dmw;
    printf("Enter Width and Mask Width : \n");
    scanf("%d %d",&width,&mWidth);
    int size = sizeof(float);
    n = (float*)malloc(width*size);
    m = (float*)malloc(mWidth*size);
    p = (float*)malloc(width*size);
    for(int i=0;i<width;i++)
    {
        n[i] = i+1;
    }
    for(int i=0;i<mWidth;i++)
    {
        m[i] = i+10;
    }
    cudaMalloc((void**)&dn,width*size);
    cudaMalloc((void**)&dm,mWidth*size);
    cudaMalloc((void**)&dp,width*size);
    cudaMalloc((void**)&dw,sizeof(int));
    cudaMalloc((void**)&dmw,sizeof(int));
    
    cudaMemcpy(dn,n,width*size,cudaMemcpyHostToDevice);
    cudaMemcpy(dm,m,mWidth*size,cudaMemcpyHostToDevice);
    cudaMemcpy(dmw,&mWidth,sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(dw,&width,sizeof(int), cudaMemcpyHostToDevice);
    convolution<<<1,width>>>(dn,dm,dp,dmw,dw);
    cudaMemcpy(p,dp,width*size,cudaMemcpyDeviceToHost);
    printf("Result : \n");
    for(int i=0;i<width;i++)
    {
        printf("%f ",p[i]);
    }
    printf("\n");
    cudaFree(dn);
    cudaFree(dm);
    cudaFree(dp);
    cudaFree(dw);
    cudaFree(dmw);
    return 0;
}