public class Main {
    public static void main(String[] args) {

        DiscountService service = new DiscountService();

        double result = service.applyDiscount("BLACK_FRIDAY", 100);

        System.out.println("Total com desconto: " + result);
    }
}
