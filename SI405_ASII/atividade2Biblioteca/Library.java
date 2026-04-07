import java.util.ArrayList;
import java.util.List;

public class Library {
    private String name;
    private Manager manager;
    private List<Book> books;
    private List<Map> maps;
    
    private List<Periodical> periodicals;
    private List<User> users;
    
    public Library(String name, Manager manager) {
        this.name = name;
        this.manager = manager;
        this.books = new ArrayList<Book>();
        this.periodicals = new ArrayList<Periodical>();
        this.maps = new ArrayList<Map>();
        this.users = new ArrayList<User>();
    }
    
    public List<Map> getMaps() {
        return maps;
    }
    void registerBook(Book book) {
        books.add(book);
    }
    void registerMap(Map map) {
        maps.add(map);
    }
    void registerPeriodical(Periodical periodical) {
        periodicals.add(periodical);
    }
    void registerUser(User user) {
        users.add(user);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Manager getManager() {
        return manager;
    }
    public void setManager(Manager manager) {
        this.manager = manager;
    }

    public List<Book> getBooks() {
        return books;
    }

    public List<Periodical> getPeriodicals() {
        return periodicals;
    }

    public List<User> getUsers() {
        return users;
    }
    
}
