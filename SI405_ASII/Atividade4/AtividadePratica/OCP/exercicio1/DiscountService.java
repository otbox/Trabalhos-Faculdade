public class DiscountService {

    public double applyDiscount(String type, double value) {

        if (type.equals("BLACK_FRIDAY")) {
            return value * 0.8;
        } else if (type.equals("VIP")) {
            return value * 0.7;
        } else if (type.equals("NATAL")) {
            return value * 0.9;
        }

        return value;
    }
}
