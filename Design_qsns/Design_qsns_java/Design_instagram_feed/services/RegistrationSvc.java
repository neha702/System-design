package Design_qsns.Design_qsns_java.Design_instagram_feed.services;
import Design_qsns.Design_qsns_java.Design_instagram_feed.models.User;
import java.util.*;

public class RegistrationSvc {
    HashSet<User> users;

    RegistrationSvc() {
        this.users = new HashSet<>();
    }

    public void register(User u) {
        if(users.contains(u) == true) {
            System.out.println("User already exists with user_id " + u.getUserId());
            return;
        }
        users.add(u);
        System.out.println("User registered successfully with user_id " + u.getUserId());
    }

    public HashSet<User> getUsersList() {
        return users;
    }
}
