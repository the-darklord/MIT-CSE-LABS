#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char toLower(char c)
{
    if(c>='A' && c<='Z')
    {
        c += 32;
    }
    return c;
}

int countNonVowels(char* str)
{
    int sum=0;
    char c;
    for(int i=0;i<strlen(str);i++)
    {
        c = str[i];
        c = toLower(c);
        if(c!='a' && c!='e' && c!='i' && c!='o' && c!='u')
        {
            sum++;
        }
    }
    printf("%d\n",sum);
}

int main(int argc,char** argv)
{
    int rank,size,N,i,M,count,sum=0;
    char str[100];
    char B[100];
    int C[10];
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    if(rank==0)
    {
        N = size;
        printf("Enter a String : \t");
        scanf("%s",str);
        if(strlen(str)%N!=0)
        {
            printf("Incorrect String Length\n");
            exit(EXIT_FAILURE);
        }
        M = strlen(str)/N;
    }
    MPI_Bcast(&M,1,MPI_INT,0,MPI_COMM_WORLD);
    MPI_Scatter(str,M,MPI_CHAR,B,M,MPI_CHAR,0,MPI_COMM_WORLD);
    count = countNonVowels(B);
    MPI_Gather(&count,1,MPI_INT,C,1,MPI_INT,0,MPI_COMM_WORLD);
    if(rank==0)
    {
        for(i=0;i<N;i++)
        {
            sum += C[i];
            printf("Non Vowel Count %d : %d\n",i+1,C[i]);
        }
        printf("Overall Count : %d\n",sum);        
    }
    MPI_Finalize();
    return 0;
}