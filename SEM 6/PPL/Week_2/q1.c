#include "mpi.h"
#include <stdio.h>
#include <string.h>

void toggle(char* x,int n)
{
    for(int i=0;i<n;i++)
    {
        if(x[i]>='A' && x[i]<='Z')
        {
            x[i] += 32;
        }
        else if(x[i]>='a' && x[i]<='z')
        {
            x[i] -= 32;
        }
    }
}

int main(int argc,char* argv[])
{
    int rank,size;
    char x[20];
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Status status;
    if(rank==0)
    {
        printf("Enter a word in Master Process :");
        scanf("%s",x);
        MPI_Ssend(&x,20,MPI_CHAR,1,1,MPI_COMM_WORLD);
        printf("Sent %s from process 0\n",x);
        MPI_Recv(&x,20,MPI_CHAR,1,1,MPI_COMM_WORLD,&status);
        printf("Received %s in process 0\n",x);
    }
    else
    {
        MPI_Recv(&x,20,MPI_CHAR,0,1,MPI_COMM_WORLD,&status);
        printf("Received %s in process 1\n",x);
        toggle(x,strlen(x));
        MPI_Ssend(&x,20,MPI_CHAR,0,1,MPI_COMM_WORLD);
        printf("Sent %s from process 1\n",x);
    }
    MPI_Finalize();
    return 0;
}