import java.util.Scanner;

public class q3
{
    public static double fact(int n)
    {
        if(n<=1)
        {
            return 1;
        }
        else
        {
            return n*fact(n-1);
        }
    }
    public static void main (String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int n,r;
        n=sc.nextInt();
        r=sc.nextInt();
        double ncr;

        ncr=fact(n)/(fact(n-r)*fact(r));

        System.out.println("nCr is " + ncr);

    }
}