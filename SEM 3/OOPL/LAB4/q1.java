import java.util.*;
class Complex
{
    int a;
    int b;
    Complex()
    {
        a = 10;
        b = 15;
    }
    Complex(int c,int d)
    {
        a = c;
        b = d;
    }
    static void sum(Complex val1,Complex val2,Complex sum)
    {   
        sum.a = val1.a + val2.a;
        sum.b = val1.b + val2.b;
    }
    static void diff(Complex val1,Complex val2,Complex diff)
    {
        diff.a = val1.a - val2.a;
        diff.b = val1.b - val2.b;
    }
    void Display()
    {
        String c="+";
        if(b<0)
        {
            c="-";
        }
        int t=Math.abs(b);
        System.out.println(a+c+"i"+t);
    }
}
class q1
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        Complex c1 = new Complex();
        System.out.println("Enter Values for Complex Number ");
        int re = sc.nextInt();
        int im = sc.nextInt();
        Complex c2 = new Complex(re,im);
        c1.Display();
        c2.Display();
        Complex add = new Complex();
        Complex diffe = new Complex();
        Complex.sum(c1,c2,add);
        Complex.diff(c1,c2,diffe);
        add.Display();
        diffe.Display();
    }
}