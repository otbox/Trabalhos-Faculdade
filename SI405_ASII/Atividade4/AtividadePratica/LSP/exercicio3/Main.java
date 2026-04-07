public class Main {

    public static void processWithdraw(Account account, double amount) {
        account.withdraw(amount);
    }

    public static void main(String[] args) {

        Account acc1 = new Account(2000);
        Account acc2 = new SavingsAccount(2000);

        processWithdraw(acc1, 1500);
        processWithdraw(acc2, 1500);
    }
}
