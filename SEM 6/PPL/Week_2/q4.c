#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
    int rank,size,x=atoi(argv[1]);
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Status status;
    if(rank==0)
    {
        MPI_Send(&x,1,MPI_INT,1,1,MPI_COMM_WORLD);
        printf("Sent %d to Process 1\n",x);
        MPI_Recv(&x,1,MPI_INT,size-1,1,MPI_COMM_WORLD,&status);
        printf("Received %d in Process %d\n",x,rank);
    }
    else if(rank==size-1)
    {
        MPI_Recv(&x,1,MPI_INT,rank-1,1,MPI_COMM_WORLD,&status);
        printf("Received %d in process %d\n",x,rank);
        x++;
        MPI_Send(&x,1,MPI_INT,0,1,MPI_COMM_WORLD);
        printf("Sent %d to Process %d\n",x,0);
    }
    else
    {
        MPI_Recv(&x,1,MPI_INT,rank-1,1,MPI_COMM_WORLD,&status);
        printf("Received %d in process %d\n",x,rank);
        x++;
        MPI_Send(&x,1,MPI_INT,rank+1,1,MPI_COMM_WORLD);
        printf("Sent %d to Process %d\n",x,rank+1);
    }
    MPI_Finalize();
    return 0;
}