import java.util.Random;

public class MasterCard extends CreditCard {
        public MasterCard(String ownerName, IBank bank, double monthlyIncome) {
        super(ownerName, bank, monthlyIncome);

    }

    @Override
    public String generateCreditCardNumber() {
        Random rand = new Random();
        String creditCardNumber = "5";
        for (int i = 0; i < 15; i++) {
            creditCardNumber += rand.nextInt(9) + 1;
        }

        return creditCardNumber;
    }

    @Override
    public double grantCreditLimit(double monthlyIncome) {
        return monthlyIncome * 2.5;
    }

}
