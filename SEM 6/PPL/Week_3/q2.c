#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

float avg(int arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum += arr[i];
    }
    return ((float)sum/(float)n);
}

float avg1(float arr[],int n)
{
    float sum=0;
    for(int i=0;i<n;i++)
    {
        sum += arr[i];
    }
    return ((float)sum/(float)n);
}

int main(int argc,char** argv)
{
    int rank,size,N,M,i;
    int *A;
    int *B;
    float C[size];
    float c;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    if(rank==0)
    {
        N = size;
        printf("Enter M : \t");
        scanf("%d",&M);
        A = (int*)malloc(N*M*sizeof(int));
        printf("Enter %d Values : \n",N*M);
        for(i=0;i<N*M;i++)
        {
            scanf("%d",&A[i]);
        }
    }
    B = (int*)malloc(M*sizeof(int));
    MPI_Bcast(&M,1,MPI_INT,0,MPI_COMM_WORLD);
    MPI_Scatter(A,M,MPI_INT,B,M,MPI_INT,0,MPI_COMM_WORLD);
    c = avg(B,M);
    MPI_Gather(&c,1,MPI_FLOAT,C,1,MPI_FLOAT,0,MPI_COMM_WORLD);
    if(rank==0)
    {
        c = avg1(C,N);
        for(i=0;i<N;i++)
        {
            printf("Avg %d : %f\n",i+1,C[i]);
        }
        printf("Overall Avg : %f\n",c);        
    }
    MPI_Finalize();
    return 0;
}