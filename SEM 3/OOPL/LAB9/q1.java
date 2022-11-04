class Mult extends Thread
{
    String threadname;
    Thread t;
    int n;
    Mult(String threadname,int n)
    {
        this.threadname=threadname;
        this.n = n;
        t=new Thread(this,this.threadname);
        System.out.println(threadname+" : ");
        t.start();
    }
    public void run()
    {
        try
        {
            for(int i=1;i<=10;i++)
            {
                System.out.println(n+"*"+i+"="+(n*i));
                Thread.sleep(10);
            }
        }
        catch(InterruptedException e)
        {
            System.out.println(threadname+" Interrupted");
        }
        System.out.println("Exiting Child Thread");
    }
}

class Tables
{
    String name;
    int n;
    Tables(String name,int n)
    {
        this.name=name;
        this.n=n;
        new Mult(name,n);
    }
}

class q1
{
    public static void main(String[] args)
    {
        new Tables("five",5);
        new Tables("seven",7);
        try
        {
            Thread.sleep(110);
        }
        catch(InterruptedException e)
        {
            System.out.println("Interrupting Main Thread");
        }
        System.out.println("Exiting Main Thread");
    }
}