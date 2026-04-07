class ClientApp {

    private UserService userService;

    public ClientApp(UserService userService) {
        this.userService = userService;
    }

    public void register(String name) {
        userService.createUser(name);
    }
}
