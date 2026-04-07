public class AlertService {
    private NotificationService notificationService;

    AlertService(NotificationService notificationService) {
        this.notificationService = notificationService;
    }

    public void alert(String message) {
        notificationService.send(message);
    }
}
