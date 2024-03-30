#include <cuda_runtime.h>
#include <device_launch_parameters.h>
#include <stdio.h>
#include <stdlib.h>

void readMatrix(int *M,int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&M[i*c+j]);
        }
    }
}

void printMatrix(int *M,int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d ",M[i*c+j]);
        }
        printf("\n");
    }
}

__global__ void replace(int* A,int* B,int c)
{
    int i = threadIdx.x;
    int r = blockDim.x;
    for(int j=0;j<c;j++)
    {
        if(i==0||i==r-1||j==0||j==c-1)
        {
            B[i*c+j] = A[i*c+j];
        }
        else
        {
            int n = A[i*c+j];
            int a[100];
            int k=0;
            B[i*c+j] = 0;
            for(k=0;n>0;k++)    
            {
                a[k]=n%2;
                n=n/2;
            }
            for(int l=k-1;l>=0;l--)    
            {
                B[i*c+j] = B[i*c+j]*10 + 1-a[l];
            }
        }
    }
}

int main()
{
    int r,c;

    printf("Enter Dimensions of Matrix A : \n");
    scanf("%d %d",&r,&c);

    int *A = (int*)malloc(r*c*sizeof(int));
    int *B = (int*)malloc(r*c*sizeof(int));

    printf("Enter Matrix A : \n");
    readMatrix(A,r,c);

    printf("Matrix A : \n");
    printMatrix(A,r,c);

    int *dA,*dB;
    cudaMalloc(&dA,r*c*sizeof(int));
    cudaMalloc(&dB,r*c*sizeof(int));

    cudaMemcpy(dA,A,r*c*sizeof(int),cudaMemcpyHostToDevice);
    replace<<<1,r>>>(dA,dB,c);
    cudaMemcpy(B,dB,r*c*sizeof(int),cudaMemcpyDeviceToHost);

    printf("Resultant Matrix : \n");
    printMatrix(B,r,c);

    cudaFree(dA);
    cudaFree(dB);

    return 0;
}