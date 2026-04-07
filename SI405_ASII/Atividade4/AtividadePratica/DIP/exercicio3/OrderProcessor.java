public class OrderProcessor {

    private Repository database = new MySQLDatabase();
    private NotificationService sender = new EmailSender();

    OrderProcessor(Repository database, NotificationService sender) {
        this.sender = sender;
        this.database = database;
    }
    public void processOrder(String order) {

        System.out.println("Processing order: " + order);

        database.save(order);

        sender.send("Order processed: " + order);
    }
}
