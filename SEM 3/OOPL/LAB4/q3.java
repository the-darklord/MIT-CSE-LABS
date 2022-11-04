import java.util.*;

class Bank_Account
{
    String account_name;
    long account_number;
    String account_type;
    double account_balance;
    static double rate = 11.5;
    Bank_Account()
    {
        Random r1 = new Random();
        account_name = "Dark Lord";
        account_number = Math.abs(r1.nextLong());
        account_type = "SB";
        account_balance = 1000000;
    }
    Bank_Account(String name , String type , double balance)
    {
        Random r1 = new Random();
        account_name =name;
        account_number = Math.abs(r1.nextLong());
        account_type = type;
        account_balance  =balance;
    }
    void Display()
    {
        System.out.println("Name is "+account_name+"\n"+"Account Number is "+account_number+"\n"+"Account Type is "+account_type+"\n"+"Account Balance is "+account_balance+"\n");
    }
    void Deposit(double amount)
    {
        account_balance += amount;
    }
    void Withdraw(double amount)
    {
        if(amount>account_balance)
        {
            account_balance -= 100;
        }
        else
        {
            account_balance -= amount;
        }
    }
    static void Interest()
    {
        System.out.println("Interest is "+rate);
    }
}
class q3
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        Bank_Account b1 = new Bank_Account();
        System.out.println("Enter account name , type , balance ");
        Bank_Account b2 = new Bank_Account(sc.next(),sc.next(),sc.nextDouble());
        b1.Display();
        b2.Display();
        b2.Withdraw(10000);
        b2.Display();
        b2.Deposit(1000);
        b2.Display();
        Bank_Account.Interest();
    }
}