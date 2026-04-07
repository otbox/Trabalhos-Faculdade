public class ShippingService {

    public double calculate(String type, double weight) {

        if (type.equals("SEDEX")) {
            return weight * 10;
        }

        if (type.equals("PAC")) {
            return weight * 5;
        }

        return 0;
    }
}
