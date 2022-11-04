import java.util.*;
import java.lang.Math;

public class q2
{
    public static void main(String[] args)
    {
        int a,b,c,d,flag=-1;
        double r1,r2,r,im,delta,ndelta;

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Coefficients a,b,c : ");

        a=sc.nextInt();
        b=sc.nextInt();
        c=sc.nextInt();

        d=b*b - 4*a*c ;
        delta=Math.sqrt(d);
        ndelta=Math.sqrt(-d);

        if(d>0)
        {
            flag=1;
        }
        else if(d==0)
        {
            flag=2;
        }
        else if(d<0)
        {
            flag=3;
        }
        r=(-b)/(2*a);


        switch(flag)
        {
            case 1 :
            {
                r1=(-b+delta)/(2*a);
                r2=(-b-delta)/(2*a);

                System.out.println("The roots are " + r1 + " and "+ r2);
                break;
            }

            case 2 :
            {
                System.out.println("The roots are " + r + " and " + r);
                break;
            }

            case 3 :
            {
                im=ndelta/(2*a);

                System.out.println("The roots are " + r + "+" + im + "i and " + r + "-" + im + "i");
                break;
            }
        }
    }
}