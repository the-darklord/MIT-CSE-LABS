#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

double power(int x,int r)
{
    double val = 1;
    for(int i=0;i<r;i++)
    {
        val *= x;
    }
    return val;
}

int main(int argc,char* argv[])
{
    int x=atoi(argv[1]),rank,size;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    printf("Power of %d , %d is %f\n",x,rank,power(x,rank));
    MPI_Finalize();
    return 0;
}