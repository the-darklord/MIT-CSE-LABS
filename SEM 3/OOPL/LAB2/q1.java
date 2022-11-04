import java.util.Scanner;

class q1
{
    public static void main(String args[])
    {
        int i,j,n,temp;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Number of Elements : ");
        n=sc.nextInt();
        int a[]=new int[n];
        for(i=0;i<n;i++)
        {
            System.out.println("Enter Element "+(i+1)+" : ");
            a[i]=sc.nextInt();
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n-i-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }
        System.out.println("Ascending Order is ");
        for(i=0;i<n;i++)
        {
            System.out.println(a[i]);
        }
        System.out.println("Descending Order is ");
        for(i=n-1;i>=0;i--)
        {
            System.out.println(a[i]);
        }
    }
}