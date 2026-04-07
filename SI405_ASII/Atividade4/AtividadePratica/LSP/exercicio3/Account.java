class Account {

    protected double balance;

    public Account(double balance) {
        this.balance = balance;
    }

    public void withdraw(double amount) {

        if (amount <= balance) {
            balance -= amount;
            System.out.println("Saque realizado");
        } else {
            System.out.println("Saldo insuficiente");
        }
    }

    public double getBalance() {
        return balance;
    }
}
