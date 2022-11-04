#include <stdio.h>

void read(int M[][100],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d",&M[i][j]);
		}
	}
}

void display(int M[][100],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d \t",M[i][j]);
		}
		printf("\n");
	}
}

void product(int A[][100],int B[][100],int C[][100],int m,int n,int q)
{
	int i,j,k;
	for(i=0;i<m;i++)
	{
		for(j=0;j<q;j++)
		{
			C[i][j]=0;
			for(k=0;k<n;k++)
			{
				C[i][j]=C[i][j]+A[i][k]*B[k][j];
			}
		}
	}
}

int main()
{
	int A[100][100],B[100][100],C[100][100],m,n,p,q,i,j;
	printf("Enter No. of Rows and Columns of Matrix A \n");
	scanf("%d%d",&m,&n);
	printf("Enter No. of Rows and Columns of Matrix B \n");
	scanf("%d%d",&p,&q);

	printf("Input Matrix A \n");
	read(A,m,n);
	printf("Input Matrix B \n");
	read(B,p,q);

	printf("\nMatrix A \n");
	display(A,m,n);
	printf(" \nMatrix B \n");
	display(B,p,q);

	if(n==p)
	{
		printf("Product of given Matrices is \n");
		product(A,B,C,m,n,q);
		for(i=0;i<m;i++)
		{
			for(j=0;j<q;j++)
			{
				printf("%d \t",C[i][j]);
			}
			printf("\n");
		}
	}
	else
	{
		printf("Matrices Can't be Multiplied \n");
	}

	return 0;
}