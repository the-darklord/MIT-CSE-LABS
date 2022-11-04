class Counter
{
    static int count = 0;
    {
        count++;
    }
    static int showCount()
    {
        return (Counter.count);
    }
}
class q4
{
    public static void main(String[] args)
    {
        Counter c1 = new Counter();
        Counter c2 = new Counter();
        System.out.println("Number of objects are "+Counter.showCount());
    }
}