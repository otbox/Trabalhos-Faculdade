public class Main {
    public static void main(String[] args) {
        OrderService order = new OrderService();

        order.addProduct(new Product("Notebook", 3000));
        order.addProduct(new Product("Mouse", 150));

        order.processOrder("cliente@email.com");
    }
}
