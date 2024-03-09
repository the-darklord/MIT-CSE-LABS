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

__global__ void add(int *A,int *B,int *C)
{
    int i = threadIdx.x;
    C[i] = A[i] + B[i];
}

int main()
{
    int *A,*B,*C;
    int r1,c1,r2,c2;
    int *dA,*dB,*dC;
    printf("Enter Dimensions of Matrix A : \n");
    scanf("%d %d",&r1,&c1);
    printf("Enter Dimensions of Matrix B : \n");
    scanf("%d %d",&r2,&c2);
    if(r1!=r2 && c1!=c2)q3
    readMatrix(B,r2,c2);
    printf("\n\n-------------------------------------------------------------------\n\n");
    printf("---------------------------Matrix A---------------------------\n");
    printMatrix(A,r1,c1);
    printf("---------------------------Matrix B---------------------------\n");
    printMatrix(B,r2,c2);
    printf("-------------------------------------------------------------------\n\n");

    cudaMalloc(&dA,r1*c1*sizeof(int));
    cudaMalloc(&dB,r2*c2*sizeof(int));
    cudaMalloc(&dC,r1*c2*sizeof(int));

    cudaMemcpy(dA,A,r1*c1*sizeof(int),cudaMemcpyHostToDevice);
    cudaMemcpy(dB,B,r2*c2*sizeof(int),cudaMemcpyHostToDevice);
    add<<<1,r1*c2>>>(dA,dB,dC);
    cudaMemcpy(C,dC,r1*c2*sizeof(int),cudaMemcpyDeviceToHost);

    printf("---------------------------Matrix C---------------------------\n");
    printMatrix(C,r1,c2);
    printf("-------------------------------------------------------------------\n\n");

    cudaFree(dA);
    cudaFree(dB);
    cudaFree(dC);

    return 0;
}