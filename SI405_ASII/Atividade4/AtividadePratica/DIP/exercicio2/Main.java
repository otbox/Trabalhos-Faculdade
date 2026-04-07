public class Main {

    public static void main(String[] args) {

        AlertService service = new AlertService(new EmailService());

        service.alert("Sistema fora do ar!");
    }
}
