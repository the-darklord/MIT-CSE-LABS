#include "mpi.h"
#include <stdio.h>

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

int main(int argc, char *argv[])
{
    int rank,size,fact=1,factSum,i,errCode;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Errhandler_set(MPI_COMM_WORLD,MPI_ERRORS_RETURN);
    for(i=1;i<=rank+1;i++)
    {
        fact *= i;
    }
    errCode = MPI_Scan(&fact,factSum,1,MPI_INT,MPI_SUM,MPI_COMM_WORLD);
    handler(errCode);
    if(rank==size-1)
    {
        printf("Sum of factorials = %d\n",factSum);
    }
    MPI_Finalize();
    return 0;
}