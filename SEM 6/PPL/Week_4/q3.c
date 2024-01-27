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

int findOcc(int* arr,int n,int key)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            count++;
        }
    }
    return count;
}

int main(int argc, char *argv[])
{
    int rank,size,i,errCode,row,col,count,key,countSum;
    int* A;
    int* B;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Errhandler_set(MPI_COMM_WORLD,MPI_ERRORS_RETURN);
    if(rank==0)
    {
        printf("Enter Row Size : \n");
        scanf("%d",&col);
        row = size;
        printf("Enter Matrix : \n");
        A = (int*)malloc(row*col*sizeof(int));
        for(int i=0;i<row*col;i++)
        {
            scanf("%d",&A[i]);
        }
        printf("Enter Key to Search : \t");
        scanf("%d",&key);
    }
    B = (int*)malloc(col*sizeof(int));
    MPI_Bcast(&col,1,MPI_INT,0,MPI_COMM_WORLD);
    MPI_Bcast(&key,1,MPI_INT,0,MPI_COMM_WORLD);
    MPI_Scatter(A,col,MPI_INT,B,col,MPI_INT,0,MPI_COMM_WORLD);
    count=findOcc(B,col,key);
    printf("Occurences in Row %d = %d\n",rank+1,count);
    errCode = MPI_Scan(&count,&countSum,1,MPI_INT,MPI_SUM,MPI_COMM_WORLD);
    handler(errCode);
    if(rank==size-1)
    {
        printf("Total No. of Occurences = %d\n",countSum);
    }
    MPI_Finalize();
    return 0;
}