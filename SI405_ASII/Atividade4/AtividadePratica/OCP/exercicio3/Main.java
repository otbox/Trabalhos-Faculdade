public class Main {
    public static void main(String[] args) {

        ShippingService service = new ShippingService();

        System.out.println(service.calculate("SEDEX", 2));
        System.out.println(service.calculate("PAC", 2));
    }
}
