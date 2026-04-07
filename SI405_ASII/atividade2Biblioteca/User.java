import java.util.Date;

public class User extends Person {
    private int userId;
    private String address;

    public User(String firstname, String lastName, Date dateOfBirth, int userId, String address) {
        super(firstname, lastName, dateOfBirth);
        this.userId = userId;
        this.address = address;
    }

    public int getUserId() {
        return userId;
    }

    public void setUserId(int userId) {
        this.userId = userId;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    
    
}
