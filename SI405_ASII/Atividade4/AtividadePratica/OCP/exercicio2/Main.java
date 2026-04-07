public class Main {
    public static void main(String[] args) {

        PaymentService service = new PaymentService();

        System.out.println(service.processPayment("CREDIT", 100));
        System.out.println(service.processPayment("PIX", 100));
    }
}
