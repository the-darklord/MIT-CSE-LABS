import java.util.Scanner;

class q4
{
    public static void main(String args[])
    {
        int i,j,m,n,p,q;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Number of Rows of Matrix A");
        m=sc.nextInt();
        System.out.println("Enter Number of Columns of Matrix A");
        n=sc.nextInt();
        System.out.println("Enter Number of Rows of Matrix B");
        p=sc.nextInt();
        System.out.println("Enter Number of Columns of Matrix B");
        q=sc.nextInt();
        int A[][]=new int[m][n];
        int B[][]=new int[p][q];

        if(m==p&&n==q)
        {
            for(i=0;i<m;i++)
            {
                for(j=0;j<n;j++)
                {
                    System.out.println("Enter Element "+(i+1)+","+(j+1)+" of Mattix A");
                    A[i][j]=sc.nextInt();
                }
            }
            for(i=0;i<p;i++)
            {
                for(j=0;j<q;j++)
                {
                    System.out.println("Enter Element "+(i+1)+","+(j+1)+" of Mattix B");
                    B[i][j]=sc.nextInt();
                }
            }
            int C[][]=new int[m][n];
            for(i=0;i<m;i++)
            {
                for(j=0;j<n;j++)
                {
                    C[i][j]=A[i][j]+B[i][j];
                }
            }
            System.out.println("Matrix Sum is ");
            for(i=0;i<m;i++)
            {
                for(j=0;j<n;j++)
                {
                    System.out.print(C[i][j]+" ");
                }
                System.out.println("");

            }
        }
        else
        {
            System.out.println("Matrices can't be added");
        }

    }
}