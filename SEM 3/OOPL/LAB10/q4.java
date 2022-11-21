import java.util.*;

class q4
{
    static void printlist(ArrayList<?> list){
        for (int i=0;i<list.size();i++)
        {
            System.out.print(list.get(i)+"\t");
        }
        System.out.println();
    }
    public static void main(String[] args)
    {
        ArrayList<Integer> list1 = new ArrayList<Integer>();
        ArrayList<Double> list2 = new ArrayList<Double>();
        ArrayList<String> list3 = new ArrayList<String>();   
        list1.add(1);
        list1.add(2);
        list1.add(3);
        list2.add(1.0);
        list2.add(2.0);
        list2.add(3.0);
        list3.add("A");
        list3.add("B");
        list3.add("C");
        System.out.println(list1+"\n"+list2+"\n"+list3+"\n");
        printlist(list1);
        printlist(list2);
        printlist(list3);

    }
}