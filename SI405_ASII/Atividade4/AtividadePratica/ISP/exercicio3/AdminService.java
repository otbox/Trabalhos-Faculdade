class AdminService implements UserService {

    public void createUser(String name) {
        System.out.println("User created: " + name);
    }

    public void deleteUser(String name) {
        System.out.println("User deleted: " + name);
    }

    public void generateReport() {
        System.out.println("Generating report...");
    }

    public void sendEmail(String email) {
        System.out.println("Sending email to: " + email);
    }
}
