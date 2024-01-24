#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char** argv)
{
    int rank,size,N,i,M,l=0;
    char str1[100];
    char str2[100];
    char B1[100];
    char B2[100];
    char C[200];
    char concat[100];
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    if(rank==0)
    {
        N = size;
        printf("Enter String 1 : \t");
        scanf("%s",str1);
        printf("Enter String 2 : \t");
        scanf("%s",str2);
        if(strlen(str1)!=strlen(str2) && strlen(str1)%N!=0)
        {
            printf("Incorrect String Input\n");
            exit(EXIT_FAILURE);
        }
        M = strlen(str1)/N;
    }
    MPI_Bcast(&M,1,MPI_INT,0,MPI_COMM_WORLD);
    MPI_Scatter(str1,M,MPI_CHAR,B1,M,MPI_CHAR,0,MPI_COMM_WORLD);
    MPI_Scatter(str2,M,MPI_CHAR,B2,M,MPI_CHAR,0,MPI_COMM_WORLD);
    l=0;
    for(i=0;i<M;i++)
    {
        concat[l++] = B1[i];
        concat[l++] = B2[i];
    }
    MPI_Gather(concat,2*M,MPI_CHAR,C,2*M,MPI_CHAR,0,MPI_COMM_WORLD);
    if(rank==0)
    {
        printf("Resultant String : %s\n",C);        
    }
    MPI_Finalize();
    return 0;
}