import java.util.ArrayList;
import java.util.List;

public class OrderService {

    private List<Product> products = new ArrayList<>();

    public void addProduct(Product product) {
        products.add(product);
    }

    public void processOrder(String customerEmail) {
        double total = 0;

        // cálculo
        for (Product p : products) {
            total += p.getPrice();
        }

        System.out.println("Total do pedido: " + total);

        // "persistência"
        System.out.println("Salvando pedido no banco de dados...");
        for (Product p : products) {
            System.out.println("Produto salvo: " + p.getName());
        }

        // "envio de email"
        System.out.println("Enviando email para: " + customerEmail);
        System.out.println("Resumo do pedido:");
        for (Product p : products) {
            System.out.println("- " + p.getName());
        }
    }
}
