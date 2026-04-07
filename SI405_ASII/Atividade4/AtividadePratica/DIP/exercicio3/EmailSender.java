class EmailSender implements NotificationService {

    public void send(String message) {
        System.out.println("Sending email: " + message);
    }
}
