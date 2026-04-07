public class PaymentService {

    public double processPayment(String type, double amount) {

        if (type.equals("CREDIT")) {
            return amount + (amount * 0.05);
        }

        if (type.equals("DEBIT")) {
            return amount + (amount * 0.02);
        }

        if (type.equals("PIX")) {
            return amount;
        }

        return amount;
    }
}
