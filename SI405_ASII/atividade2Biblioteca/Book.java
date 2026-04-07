public class Book implements ILibraryArtifact {
    private String title;
    private Author author;
    private int publicationYear;
    private int available;
    private String genre;
    
    public Book(String title, Author author, int publicationYear, int available, String genre) {
        this.title = title;
        this.author = author;
        this.publicationYear = publicationYear;
        this.available = available;
        this.genre = genre;
    }
    
    public String getGenre() {
        return genre;
    }

    

    public void setGenre(String genre) {
        this.genre = genre;
    }
    @Override
    public String getTitle() {
        return title;
    }
    
    @Override
    public Author getAuthor() {
        return author;
    }
    
    @Override
    public int getPublicationYear() {
        return publicationYear;
    }

    @Override
    public boolean isAvailableForLoan() {
       if (available >= 1) {
            return true;
       }
       return false;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public void setAuthor(Author author) {
        this.author = author;
    }

    public void setPublicationYear(int publicationYear) {
        this.publicationYear = publicationYear;
    }

    public int getAvailable() {
        return available;
    }

    public void setAvailable(int available) {
        this.available = available;
    }
    
}
