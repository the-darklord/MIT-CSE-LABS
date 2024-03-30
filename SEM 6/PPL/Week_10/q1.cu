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

__global__ void SPMV_CSR(int numRows,int* data,int* colIndex,int* rowPtr,int* x,int* y)
{
    int row = blockIdx.x*blockDim.x + threadIdx.x;
    if(row<numRows)
    {
        int dot = 0;
        int start = rowPtr[row];
        int end = rowPtr[row+1];
        for(int ele=start;ele<end;ele++)
        {
            dot += data[ele]*x[colIndex[ele]];
        }
        y[row] = dot;
    }
}

int main()
{
    int r1,c1,r2,c2;

    printf("Enter Dimensions of Matrix A : \n");
    scanf("%d %d",&r1,&c1);
    r2 = c1;
    c2 = 1;

    int *A = (int*)malloc(r1*c1*sizeof(int));
    int *B = (int*)malloc(r2*c2*sizeof(int));
    int *C = (int*)malloc(r1*c2*sizeof(int));

    printf("Enter Matrix A : \n");
    readMatrix(A,r1,c1);

    printf("\nEnter Matrix B : \n");
    readMatrix(B,r2,c2);

    int *data = (int*)malloc(r1*c1*sizeof(int));
    int *colIndex = (int*)malloc(r1*c1*sizeof(int));
    int *rowPtr = (int*)malloc((r1+1)*sizeof(int));

    int k=0,l=0;
    int cur = -1;

    for(int i=0;i<r1;i++)
    {
        int zeroRow = 1;
        for(int j=0;j<c1;j++)
        {
            if(A[i*c1+j]!=0)
            {
                zeroRow = 0;
                data[l] = A[i*c1+j];
                colIndex[l] = j;
                if(cur!=i)
                {
                    rowPtr[k++] = l;
                    cur = i;
                }
                l++;
            }
        }
        if(zeroRow)
        {
            rowPtr[k++] = l;
        }
    }
    rowPtr[k++] = l;

    int *dData,*dColIndex,*dRowPtr,*dB,*dC;
    cudaMalloc(&dData,l*sizeof(int));
    cudaMalloc(&dColIndex,l*sizeof(int));
    cudaMalloc(&dRowPtr,k*sizeof(int));
    cudaMalloc(&dB,r2*c2*sizeof(int));
    cudaMalloc(&dC,r1*c2*sizeof(int));

    cudaMemcpy(dData,data,l*sizeof(int),cudaMemcpyHostToDevice);
    cudaMemcpy(dColIndex,colIndex,l*sizeof(int),cudaMemcpyHostToDevice);
    cudaMemcpy(dRowPtr,rowPtr,k*sizeof(int),cudaMemcpyHostToDevice);
    cudaMemcpy(dB,B,r2*c2*sizeof(int),cudaMemcpyHostToDevice);
    SPMV_CSR<<<1,r1>>>(r1,dData,dColIndex,dRowPtr,dB,dC);
    cudaMemcpy(C,dC,r1*c2*sizeof(int),cudaMemcpyDeviceToHost);

    printf("Resultant Matrix : \n");
    printMatrix(C,r1,c2);

    cudaFree(dData);
    cudaFree(dColIndex);
    cudaFree(dRowPtr);
    cudaFree(dB);
    cudaFree(dC);

    return 0;
}