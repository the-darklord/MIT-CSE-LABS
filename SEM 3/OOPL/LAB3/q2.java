import java.util.Scanner;
class Time
{
 int hh,mm,ss;
 void set(int hh,int mm,int ss)
 {
    this.hh=hh;
    this.mm=mm;
    this.ss=ss;
 }
 public void Display()
 {
    System.out.print(+hh+":"+mm+":"+ss);
 }
 public static void Add(Time time1,Time time2,Time add)
 {
    add.hh = time1.hh + time2.hh;
    add.mm = time1.mm + time2.mm;
    add.ss = time1.ss + time2.ss;
    if(add.ss>=60)
    {
        add.mm = add.mm + 1;
        add.ss = add.ss - 60;
    }
    if(add.mm>=60)
    {
        add.hh = add.hh + 1;
        add.mm = add.mm - 60;
    }
 }
 public static void Sub(Time time1,Time time2,Time sub)
 {
    if(time1.hh<time2.hh)
    {
        System.out.println("Times can't be Subtracted");
    }
    else
    {
    sub.hh = time1.hh - time2.hh;
    }
    if(time1.mm<time2.mm)
    { 
        sub.hh = sub.hh - 1;
        sub.mm = time1.mm - time2.mm + 60;
    }
    else
    {
    sub.mm = time1.mm - time2.mm;
    }
    if(time1.ss<time2.ss)
    {
        sub.mm = sub.mm - 1;
        sub.ss = time1.ss - time2.ss + 60;
    }
    else
    {
    sub.ss = time1.ss - time2.ss;
    }
 }
 public static void Compare(Time time1,Time time2)
 {
    int flag=0;
    if(time1.hh>time2.hh)
    {
        flag=3;
    }
    else if (time1.hh<time2.hh)
    {
        flag=2;
    }
    else if(time1.hh==time2.hh)
    {
        if(time1.mm<time2.mm)
        {
            flag=2;
        }
        else if(time1.mm>time2.mm)
        {
            flag=3;
        }
        else if(time1.mm==time2.mm)
        {
            if(time1.ss<time2.ss)
            {
                flag=2;
            }
            else if(time1.ss>time2.ss)
            {
                flag=3;
            }
            else if(time1.ss==time2.ss)
            {
                flag=1;
            }
        }
    }
    System.out.println("");
    if(flag==1)
    {
        System.out.println("Time1 = Time2");
    }
    else if(flag==2)
    {
        System.out.println("Time1 < Time2");
    }
    else if(flag==3)
    {
        System.out.println("Time1 > Time2");
    }
 }
}
class q2
{
    public static void main(String[] args)
    {
        int h1,h2,m1,m2,s1,s2;
        Scanner sc = new Scanner(System.in);
        System.out.println("For Time 1 : ");
        System.out.println("Enter Hours (<24) : ");
        h1=sc.nextInt();
        System.out.println("Enter Minutes (<60) : ");
        m1=sc.nextInt();
        System.out.println("Enter Seconds (<60) : ");
        s1=sc.nextInt();
        System.out.println("For Time 2 : ");
        System.out.println("Enter Hours (<24) : ");
        h2=sc.nextInt();
        System.out.println("Enter Minutes (<60) : ");
        m2=sc.nextInt();
        System.out.println("Enter Seconds (<60) : ");
        s2=sc.nextInt();
        Time time1 = new Time() , time2 = new Time(),add = new Time(),sub = new Time();
        System.out.println("");
        System.out.print("Time 1 is : ");
        time1.set(h1,m1,s1);
        time1.Display();
        System.out.println("");
        System.out.print("Time 2 is : ");
        time2.set(h2,m2,s2);
        time2.Display();
        Time.Add(time1,time2,add);
        System.out.println("");
        System.out.print("Added Time is : ");
        add.Display();
        Time.Sub(time1,time2,sub);
        System.out.println("");
        System.out.print("Substracted Time is : ");
        sub.Display();
        Time.Compare(time1,time2);
    }
}