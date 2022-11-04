import java.util.Scanner;
import java.lang.Math;
class Complex
{
    int a;
    int b;
    void set(int a,int b)
    {
        this.a=a;
        this.b=b;
    }
    public static void sum(Complex val1,Complex val2,Complex sum)
    {   
        sum.a = val1.a + val2.a;
        sum.b = val1.b + val2.b;
    }
    public static void diff(Complex val1,Complex val2,Complex diff)
    {
        diff.a = val1.a - val2.a;
        diff.b = val1.b - val2.b;
    }
    public static void Display(Complex temp)
    {
        String c="+";
        if(temp.b<0)
        {
            c="-";
        }
        int t=Math.abs(temp.b);
        System.out.println(temp.a+c+t+"i");
    }
}
class q1
{
    public static void main(String[] args)
    {
        int a,b,c,d;
        Scanner sc=new Scanner(System.in);
        Complex val1 = new Complex();
        Complex val2 = new Complex();
        Complex sum = new Complex();
        Complex diff = new Complex();
        System.out.println("Enter Real and Imaginary Parts of Complex Number 1 ");
        a=sc.nextInt();
        b=sc.nextInt();
        System.out.println("Enter Real and Imaginary Parts of Complex Number 2 ");
        c=sc.nextInt();
        d=sc.nextInt();
        val1.set(a,b);
        val2.set(c,d);
        System.out.println("First Complex Number is : ");
        val1.Display(val1);
        System.out.println("Second Complex Number is :");
        val2.Display(val2);
        System.out.println("Sum of Given Complex Numbers is :");
        Complex.sum(val1,val2,sum);
        sum.Display(sum);
        System.out.println("Difference of Given Complex Numbers is :");
        Complex.diff(val1,val2,diff);
        diff.Display(diff);
    }    
}