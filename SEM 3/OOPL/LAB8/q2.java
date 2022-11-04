import java.util.*;
class DateException extends Exception
{
    void InvalidDayException()
    {
        System.out.println("Invalid Day");
    }
    void InvalidMonthException()
    {
        System.out.println("Invalid Month");
    }
}
class CurrentDate
{
    int day,month,year;
    void createDate(int day,int month,int year)
    {
        this.day=day;
        this.month=month;
        this.year=year;
    }
    void Display() throws DateException
    {
        if(day<1||day>31||month<1||month>12)
        {
            throw new DateException();
        }
        else
        {
            System.out.println(day+"/"+month+"/"+year);
        }
    }
}
class q2
{
    public static void main(String[] args)
    {
        CurrentDate c1 = new CurrentDate();
        c1.createDate(25, 9, 2003);
        try
        {
            c1.Display();
        }
        catch(DateException d1)
        {
            if(c1.day<1||c1.day>31)
            {
                d1.InvalidDayException();
            }
            if(c1.month<1||c1.month>12)
            {
                d1.InvalidMonthException();
            }
        }
    }
}