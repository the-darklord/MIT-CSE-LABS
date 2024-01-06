#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
    int rank,size;
    int a=atoi(argv[1]),b=atoi(argv[2]);
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    switch(rank)
    {
        case 0:
        {
            printf("Addition : %d\n",a+b);
            break;
        }
        case 1:
        {
            printf("Difference : %d\n",a-b);
            break;
        }
        case 2:
        {
            printf("Product : %d\n",a*b);
            break;
        }
        case 3:
        {
            printf("Quotient : %d\n",a/b);
            break;
        }
    }
    MPI_Finalize();
    return 0;
}