class MySQLRepository implements Repository {

    public void save(String data) {
        System.out.println("Saving to MySQL: " + data);
    }
}
