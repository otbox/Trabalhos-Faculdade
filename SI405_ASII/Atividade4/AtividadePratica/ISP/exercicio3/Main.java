public class Main {

    public static void main(String[] args) {

        UserService service = new AdminService();

        ClientApp app = new ClientApp(service);

        app.register("João");
    }
}
