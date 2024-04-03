#include <stdio.h>
#include <stdlib.h>
#include <cuda_runtime.h>
#include <device_launch_parameters.h>
#include <unistd.h>

#define BLOCK_WIDTH 2
#define TILE_WIDTH 2
#define WIDTH 4

__global__ void MatMulElementThreadShared(int *a,int *b,int *c)
{
    __shared__ int MDs[TILE_WIDTH][TILE_WIDTH];
    __shared__ int NDs[TILE_WIDTH][TILE_WIDTH];
    int m;

    int bx = blockIdx.x;
    int by = blockIdx.y;
    int tx = threadIdx.x;
    int ty = threadIdx.y;
    
    int row = by*TILE_WIDTH + ty;
    int col = bx*TILE_WIDTH + tx;

    int pVal = 0;
    for(m=0;m<WIDTH/TILE_WIDTH;m++)
    {
        MDs[ty][tx] = a[row*WIDTH + m*TILE_WIDTH + tx];
        NDs[ty][tx] = b[(m*TILE_WIDTH + ty)*WIDTH + col];
        __syncthreads();
        for(int k=0;k<TILE_WIDTH;k++)
        {
            pVal += MDs[ty][k]*NDs[k][tx];
        }
        __syncthreads();
    }
    c[row*WIDTH+col] = pVal;
}

int main()
{
    int *matA,*matB,*matProd;
    int *dA,*dB,*dC;

    printf("\n==Enter elements of Matrix A (4x4) ==\n");
    matA = (int*)malloc(sizeof(int)*WIDTH*WIDTH);
    for(int i=0;i<WIDTH*WIDTH;i++)
    {
        scanf("%d",&matA[i]);
    }
    printf("\n==Enter elements of Matrix B (4x4) ==\n");
    matB = (int*)malloc(sizeof(int)*WIDTH*WIDTH);
    for(int i=0;i<WIDTH*WIDTH;i++)
    {
        scanf("%d",&matB[i]);
    }
    matProd = (int*)malloc(sizeof(int)*WIDTH*WIDTH);

    cudaMalloc(&dA,sizeof(int)*WIDTH*WIDTH);
    cudaMalloc(&dB,sizeof(int)*WIDTH*WIDTH);
    cudaMalloc(&dC,sizeof(int)*WIDTH*WIDTH);

    cudaMemcpy(dA,matA,sizeof(int)*WIDTH*WIDTH,cudaMemcpyHostToDevice);
    cudaMemcpy(dB,matB,sizeof(int)*WIDTH*WIDTH,cudaMemcpyHostToDevice);
    int numBlocks = WIDTH/BLOCK_WIDTH;
    dim3 grid(numBlocks,numBlocks);
    dim3 block(BLOCK_WIDTH,BLOCK_WIDTH);

    MatMulElementThreadShared<<<grid,block>>>(dA,dB,dC);

    cudaMemcpy(matProd,dC,sizeof(int)*WIDTH*WIDTH,cudaMemcpyDeviceToHost);

    printf("\n==Result==\n");
    printf("------------\n");
    for(int i=0;i<WIDTH;i++)
    {
        for(int j=0;j<WIDTH;j++)
        {
            printf("%6d ",matProd[i*WIDTH+j]);
        }
        printf("\n");
    }

    cudaFree(dA);
    cudaFree(dB);
    cudaFree(dC);
    free(matA);
    free(matB);
    free(matProd);

    return 0;
}