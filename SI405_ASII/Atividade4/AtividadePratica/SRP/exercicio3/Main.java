public class Main {
    public static void main(String[] args) {

        UserService service = new UserService();

        service.registerUser(new User("Jo", "email-invalido"));
        service.registerUser(new User("Maria", "maria@email.com"));
    }
}
