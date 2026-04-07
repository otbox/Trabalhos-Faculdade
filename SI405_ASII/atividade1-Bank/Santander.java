import java.util.Currency;

public class Santander implements IBank {
    public String name, manager, country, address;
    public double balance;
    public Currency currency;
    
    public Santander(String name, String manager, String country, String address, double balance, String currencyCode) {
        this.name = name;
        this.manager = manager;
        this.country = country;
        this.address = address;
        this.balance = balance;
        this.currency = Currency.getInstance(currencyCode);
    }

    @Override
    public double deposit(double value) {
        if (value < 0) {
            throw new IllegalArgumentException("Must be than 0");
        }
        balance += value;
        return balance;
    }

    @Override
    public boolean withdraw(double value) {
        if (balance < value) {
            System.err.println("Insufficient funds!");
            return false;
            // throw new PoorException();
        }
        balance -= value;
        System.out.println("Amount sucessfully withdrawn.");
        return true;
    }
    
    // public class PoorException extends Exception {
    //     public PoorException () {
    //         super("Insuficient balance, you poor");
    //     } 
    // }
}
