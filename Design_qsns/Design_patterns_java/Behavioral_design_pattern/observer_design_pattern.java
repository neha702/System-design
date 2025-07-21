//Observer design pattern is a behavioral design pattern where there is a subject and observer , and any state changes in subject leads to notiification to observers
package Design_qsns.Design_patterns_java.Behavioral_design_pattern;

import java.util.*;

interface ISubscriber { // observer interface
    void notify(String msg);
}
 
class User implements ISubscriber {  // concrete observer
    public void notify(String msg) {
        System.out.println("User notified with message: " + msg);
    }
}

class Group { // subject
    ArrayList<ISubscriber> subscribers;
    Group() {
        subscribers = new ArrayList<>();
    }
    public void subscribe(ISubscriber subscriber) {
        subscribers.add(subscriber);
    }

    public void unsubscribe(ISubscriber subscriber) {
        subscribers.remove(subscriber);
    }

    public void notifyAll(String msg) {
        for(ISubscriber subscriber : subscribers) {
            subscriber.notify(msg);
        }
    }
}

public class observer_design_pattern {
    public static void main(String[] args) {
        Group group = new Group();
        User user1 = new User();
        User user2 = new User();
        group.subscribe(user1);
        group.subscribe(user2);
        //group.unsubscribe(user2);
        group.notifyAll("Welcome to group!");
    }
}