import java.util.Scanner;

public class q1
{
    static int Largest(int a,int b,int c)
    {
        int large;
        large=(a>b?(a>c?a:c):(b>c?b:c));
        return large;
    }

    public static void main(String[] args)
    {
        int a,b,c;

        Scanner sc=new Scanner(System.in);

        a=sc.nextInt();
        b=sc.nextInt();
        c=sc.nextInt();

        int large=Largest(a,b,c);
        System.out.println(large + " is Largest");
    }
}