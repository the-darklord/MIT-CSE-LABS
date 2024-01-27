#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

void handler(int eCode)
{
    if(eCode!=MPI_SUCCESS)
    {
        char eString[BUFSIZ];
        int lenOfeString,eClass;
        MPI_Error_class( eCode , &eClass);
        MPI_Error_string(eCode,eString,&lenOfeString);
        printf("%d - %s\n\n",eCode,eString);
        MPI_Error_string(eClass,eString,&lenOfeString);
        printf("%d - %s\n\n",eClass,eString);
    }
}

int main(int argc,char** argv)
{
    int n, rank, size, i,errCode;
    double mypi, pi, h, sum, x;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Errhandler_set(MPI_COMM_WORLD,MPI_ERRORS_RETURN);
    if (rank == 0)
    {
        printf("Enter the number of intervals: (0 quits) ");
        scanf("%d",&n);
        if(n==0)
        {
            exit(1);
        }
    }
    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
    h   = 1.0 / (double) n;
    sum = 0.0;
    for (i = rank + 1; i <= n; i += size)
    {
        x = h * ((double)i - 0.5);
        sum += 4.0 / (1.0 + x*x);
    }
    mypi = h * sum;
    errCode = MPI_Reduce(&mypi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0,MPI_COMM_WORLD);
    handler(errCode);
    if (rank == 0)
    {
        printf("PI is approximately %.3f\n",pi);
    }
    MPI_Finalize();
    return 0;
}