import java.util.ArrayList;
import java.util.List;

public class UserService {

    private List<User> database = new ArrayList<>();

    public void registerUser(User user) {

        if (user.getEmail() == null || !user.getEmail().contains("@")) {
            System.out.println("Email inválido!");
            return;
        }

        if (user.getName().length() < 3) {
            System.out.println("Nome inválido!");
            return;
        }

        System.out.println("Salvando usuário no banco...");
        database.add(user);

        System.out.println("Enviando email de boas-vindas para: " + user.getEmail());
    }
}
