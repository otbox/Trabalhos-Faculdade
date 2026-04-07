public class Main {

    public static void main(String[] args) {
        OrderProcessor processor = new OrderProcessor(new MySQLDatabase(), new EmailSender());

        processor.processOrder("Pedido #123");
    }
}
