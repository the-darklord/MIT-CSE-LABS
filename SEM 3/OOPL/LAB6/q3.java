abstract class Figure
{
    int a,b,c;
    abstract void area();
}
class Rectangle extends Figure
{
    Rectangle(int a,int b)
    {
        this.a = a;
        this.b = b;
    }
    void area()
    {
        System.out.println("Rectangle Area : "+(a*b));
    }
}
class Triangle extends Figure
{
    Triangle(int a,int b,int c)
    {
        this.a = a;
        this.b = b;
        this.c = c;
    }
    void area()
    {
        int s = (a+b+c)/2;
        double res = Math.sqrt(s*(s-a)*(s-b)*(s-c));
        System.out.println("Triangle Area : "+res);
    }
}
class Square extends Figure
{
    Square(int a)
    {
        this.a = a;
    }
    void area()
    {
        System.out.println("Square Area : "+(a*a));
    }
}
class q3
{
    public static void main(String[] args)
    {
        Figure f1;
        Rectangle r1 = new Rectangle(5,4);
        f1 = r1;
        f1.area();
        Triangle t1 = new Triangle(3,4,5);
        f1 = t1;
        f1.area();
        Square s1 = new Square(6);
        f1 = s1;
        f1.area();
    }
}