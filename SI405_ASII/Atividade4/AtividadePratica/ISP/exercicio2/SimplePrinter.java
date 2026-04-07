class SimplePrinter implements MultiFunctionDevice {

    public void print(String document) {
        System.out.println("Printing: " + document);
    }

    public void scan(String document) {
        throw new UnsupportedOperationException("Scan not supported");
    }

    public void fax(String document) {
        throw new UnsupportedOperationException("Fax not supported");
    }
}
