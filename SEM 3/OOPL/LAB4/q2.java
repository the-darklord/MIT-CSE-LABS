import java.util.*;
class Time
{
    int hh;
    int mm;
    int ss;
    Time()
    {
        hh=12;
        mm=10;
        ss=50;
    }
    Time(int h,int m,int s)
    {
        hh=h;
        mm=m;
        ss=s;
    }
    void Display()
    {
        System.out.println(hh+":"+mm+":"+ss);
    }
    static void Add(Time time1,Time time2,Time add)
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
    static void Sub(Time time1,Time time2,Time sub)
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
    static void Compare(Time time1,Time time2)
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
        Scanner sc = new Scanner(System.in);
        Time t1 = new Time();
        System.out.println("Enter values for time ");
        Time t2 = new Time(sc.nextInt(),sc.nextInt(),sc.nextInt());
        t1.Display();
        t2.Display();
        Time add = new Time(),subb=new Time();
        Time.Add(t1,t2,add);
        Time.Sub(t1,t2,subb);
        add.Display();
        subb.Display();
        Time.Compare(t1,t2);
    }
}