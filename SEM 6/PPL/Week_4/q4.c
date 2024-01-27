#include "mpi.h"
#include <stdio.h>
#include<stdlib.h>

void ErrorHandler(int ecode){
    if(ecode != MPI_SUCCESS){
        char error_string[100];
        int len,error_class;
        MPI_Error_class(ecode,&error_class);
        MPI_Error_string(ecode,error_string,&len);
        printf("%d ---- %s\n",ecode,error_string);
        MPI_Error_string(error_class,error_string,&len);
        printf("%d ---- %s\n",error_class,error_string);
    }
}

int main(int argc,char** argv)
{
    int n, rank, size,i,j,error_code;
    int mat[4][4],F[4][4];
    int B[4],C[4];
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Errhandler_set(MPI_COMM_WORLD,MPI_ERRORS_RETURN);
    if (rank == 0)
    {
        printf("Enter the elements of the matrix: ");
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                scanf("%d",&mat[i][j]);
            }
        }
    }
    error_code = MPI_Scatter(mat,4,MPI_INT,B,4,MPI_INT,0,MPI_COMM_WORLD);
    error_code = MPI_Scan(B,C,4,MPI_INT,MPI_SUM,MPI_COMM_WORLD);
    error_code = MPI_Gather(C,4,MPI_INT,F,4,MPI_INT,0,MPI_COMM_WORLD);
    ErrorHandler(error_code);
    if(rank == 0){
        printf("RESULT:\n");
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                printf("%d ",F[i][j]);
            }
            printf("\n");
        }
    }
    MPI_Finalize();
    return 0;
}