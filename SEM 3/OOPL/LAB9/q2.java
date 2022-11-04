import java.util.*;
class Matrix implements Runnable
{
    String threadname;
    int n,sum=0;
    Thread t;
    int[] arr;
    Matrix(String threadname,int n,int[] arr)
    {
        this.threadname=threadname;
        this.n=n;
        this.arr=arr;
        t = new Thread(this,this.threadname);
        t.start();
    }
    public void run()
    {
        try
        {
            for(int i=0;i<n;i++)
            {
                sum+=arr[i];
                Thread.sleep(100);
            }
        }
        catch(InterruptedException e)
        {
            System.out.println(threadname+" Interrupted");
        }
    }
    int getsum()
    {
        return sum;
    }
}

class q2
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter n : ");
        int n = sc.nextInt();
        int[][] mat = new int[n][n];
        Matrix[] t = new Matrix[n];
        int sum=0;
        System.out.println("Enter Elements of Matrix : ");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                System.out.println("Enter Elements"+(i+1)+","+(j+1));
                mat[i][j]=sc.nextInt();
            }
        }
        for(int i=0;i<n;i++)
        {
            String rn="row"+Integer.toString(i);
            t[i]=new Matrix(rn,n,mat[i]);
        }
        try
        {
            Thread.sleep(500);
            for(int i=0;i<n;i++)
            {
                System.out.println("Row"+(i+1)+" Sum is "+t[i].getsum());
                sum+=t[i].getsum();
            }
        }
        catch(InterruptedException e)
        {
            System.out.println("Interrupting Main Thread");
        }
        System.out.println("Complete Sum is "+sum+"\nExiting Main Thread");
    }
}