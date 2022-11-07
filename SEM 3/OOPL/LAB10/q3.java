import java.util.*;

class List<T>
{
    LinkedList<T> list;
    List()
    {
        list = new LinkedList<T>();
    }
    void IL(T ele)
    {
        list.addLast(ele);
    }
    void IF(T ele)
    {
        list.addFirst(ele);
    }
    T DL()
    {
        return list.removeLast();
    }
    T DF()
    {
        return list.removeFirst();
    }
    void Display()
    {
        for(T i:list)
        {
            System.out.print(i + " ");
        }
        System.out.println();
    }
}
class q3
{
    public static void main(String[] args)
    {
        List<Integer> l1 = new List<Integer>();
        List<Double> l2  =new List<Double>();
        l1.IL(3);
        l1.IL(4);
        l1.IF(1);
        l1.Display();
        l2.IL(1.5);
        l2.IL(2.5);
        l2.IF(3.5);
        l2.Display();
        System.out.println("Deleted Last Element : ");
        System.out.println("L1 : "+l1.DL()+"\nL2 : "+l2.DL());
        l1.Display();
        l2.Display();
    }
}