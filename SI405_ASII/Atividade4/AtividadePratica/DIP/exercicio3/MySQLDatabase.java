class MySQLDatabase implements Repository{

    public void save(String data) {
        System.out.println("Saving in MySQL: " + data);
    }
}
