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

__global__ void rowPower(int* A,int* B,int c)
{
    int i = threadIdx.x;
    for(int j=0;j<c;j++)
    {
        int power = 1;
        for(int k=0;k<=i;k++)
        {
            power *= A[i*c+j];
        }
        B[i*c+j] = power;
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
    rowPower<<<1,r>>>(dA,dB,c);
    cudaMemcpy(B,dB,r*c*sizeof(int),cudaMemcpyDeviceToHost);

    printf("Resultant Matrix : \n");
    printMatrix(B,r,c);

    cudaFree(dA);
    cudaFree(dB);

    return 0;
}