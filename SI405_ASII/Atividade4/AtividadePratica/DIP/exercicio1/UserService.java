public class UserService {

    private Repository repository = new MySQLRepository();

    public void register(String name) {
        repository.save(name);
    }
}
