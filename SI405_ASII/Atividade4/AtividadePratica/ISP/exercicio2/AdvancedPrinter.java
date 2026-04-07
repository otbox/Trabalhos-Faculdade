class AdvancedPrinter implements MultiFunctionDevice {

    public void print(String document) {
        System.out.println("Printing: " + document);
    }

    public void scan(String document) {
        System.out.println("Scanning: " + document);
    }

    public void fax(String document) {
        System.out.println("Faxing: " + document);
    }
}
