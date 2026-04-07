import java.util.Random;

public class CreditCard {
    public String ownerName, number;
    public IBank bank;
    public double monthlyIncome, limit, balance;

    public CreditCard(String ownerName, IBank bank, double monthlyIncome) {
        this.ownerName = ownerName;
        this.bank = bank;
        this.monthlyIncome = monthlyIncome;
        this.limit = grantCreditLimit(monthlyIncome);
        this.number = generateCreditCardNumber();
        this.balance = 0;
    }

    public String generateCreditCardNumber() {

        Random rand = new Random();
        String creditCardNumber = (1 + rand.nextInt(9)) + "";

        for (int i = 0; i < 15; i++) {
            creditCardNumber += rand.nextInt(10);
        }

        return creditCardNumber;
    }

    public double grantCreditLimit(double monthlyIncome) {
        return monthlyIncome * 3;
    }
}
