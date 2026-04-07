class SMSService implements NotificationService {

    public void send(String message) {
        System.out.println("Sending SMS: " + message);
    }
}
