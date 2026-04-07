import java.util.List;

class ReportService {

    public void generateReport(List<String> data, String format) {

        // processamento
        StringBuilder processedData = new StringBuilder();
        for (String item : data) {
            processedData.append(item.toUpperCase()).append("\n");
        }

        String result;

        // formatação
        if (format.equals("PDF")) {
            result = "PDF REPORT\n" + processedData;
        } else if (format.equals("CSV")) {
            result = "CSV REPORT\n" + processedData.toString().replace("\n", ",");
        } else {
            result = processedData.toString();
        }

        // saída
        System.out.println("Gerando relatório...");
        System.out.println(result);

        // "salvamento"
        System.out.println("Salvando relatório no disco...");
    }
}
