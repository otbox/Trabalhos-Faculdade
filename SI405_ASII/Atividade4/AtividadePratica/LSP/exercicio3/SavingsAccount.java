class SavingsAccount extends Account {

    public SavingsAccount(double balance) {
        super(balance);
    }

    @Override
    public void withdraw(double amount) {

        if (amount > 1000) {
            System.out.println("Limite excedido para poupança");
            return;
        }

        super.withdraw(amount);
    }
}
