#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
    int rank,size;
    int* x;
    int l;
    int buf[100];
    int cap=100;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Status status;
    if(rank==0)
    {
        x = (int*)malloc((size-1)*sizeof(int));
        for(int i=0;i<size-1;i++)
        {
            printf("Enter element %d : \t",i+1);
            scanf("%d",&x[i]);
        }
        MPI_Buffer_attach(buf,cap);
        for(int i=0;i<size-1;i++)
        {
            MPI_Bsend(&x[i],1,MPI_INT,i+1,1,MPI_COMM_WORLD);
        }
        MPI_Buffer_detach(buf,&cap);
    }
    else if(rank%2==0)
    {
        MPI_Recv(&l,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
        printf("Received %d in process %d\n",l,rank);
        printf("Square of %d is %d\n",l,l*l);
    }
    else if(rank%2==1)
    {
        MPI_Recv(&l,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
        printf("Received %d in process %d\n",l,rank);
        printf("Cube of %d is %d\n",l,l*l*l);
    }
    MPI_Finalize();
    return 0;
}