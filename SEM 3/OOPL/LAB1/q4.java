import java.util.Scanner;

public class q4
{
    public static boolean IsPrime(int n)
    {
        int i;
        for(i=2;i<n;i++)
        {
            if(n%i==0)
            {
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Number of primes to display : ");
        int n=sc.nextInt();
        int i=2,count=0;
        System.out.println("Primes are ");
        while(count!=n)
        {
            if(IsPrime(i))
            {
                count++;
                System.out.println(i + " ");
            }
            i++;
        }
    }
}