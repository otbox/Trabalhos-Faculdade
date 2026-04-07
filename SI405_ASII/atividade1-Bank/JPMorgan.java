import java.util.Currency;
import java.util.Date;

public class JPMorgan implements IBank, IInsuranceCompany {
    public String name, manager, country, address;
    public double balance;
    public Currency currency;

    public JPMorgan(String name, String manager, String country, String address, double balance, String currencyCode) {
        this.name = name;
        this.manager = manager;
        this.country = country;
        this.address = address;
        this.balance = balance;
        this.currency = Currency.getInstance(currencyCode);
    }

    @Override
    public boolean createInsurancePolicy(String name, int age) {
        System.out.println("Life insurance successfully processed!");
        return true;
    }

    @Override
    public boolean createInsurancePolicy(String carModel, int carID, int manufacturedYear) {
        // TODO Auto-generated method stub
        if (manufacturedYear >= 2000) {
            System.out.println("Car insurance successfully processed!");
            return true;
        }
        System.out.println("Unauthorized insurance for the\n" + //
                "car manufactured in the year" + manufacturedYear);
        return false;
    }

    @Override
    public boolean createInsurancePolicy(String passagerName, String origin, String Destination, Date departureDate,
            Date returnDate) {
        System.out.println("Travel insurance successfully processed!");
                return true;
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
        value *= 1.01;
        if (balance < value) {
            System.err.println("Insufficient funds!");
            return false;
            // throw new PoorException();
        }
        balance -= value;
        System.out.println("Amount sucessfully withdrawn.");
        return true;
    }

}
