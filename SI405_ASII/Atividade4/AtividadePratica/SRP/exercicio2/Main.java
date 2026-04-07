import java.util.Arrays;

public class Main {
    public static void main(String[] args) {

        ReportService reportService = new ReportService();

        reportService.generateReport(
                Arrays.asList("item1", "item2", "item3"),
                "PDF"
        );
    }
}
