interface Series
{
    int GetNext(int x);
    void reset();
    void setStart(int x);
    void display();
}
class ByTwos implements Series
{
    int arr[];
    ByTwos(int size)
    {
        arr = new int[size];
    }
    public int GetNext(int x)
    {
        return (x+2);
    }
    public void setStart(int x)
    {
        arr[0]=x;
        for(int i=1;i<arr.length;i++)
        {
            arr[i]=GetNext(arr[i-1]);
        }
    }
    public void reset()
    {
        setStart(0);
    }
    public void display()
    {
        for(int i=0;i<arr.length;i++)
        {
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
}
class q3
{
    public static void main(String[] args)
    {
        ByTwos b1 = new ByTwos(10);
        Series s1;
        s1 = b1;
        s1.setStart(2);
        s1.display();
        s1.reset();
        s1.display();
    }
}