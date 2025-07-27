package Design_qsns.Design_qsns_java.Design_instagram_feed.services;
import Design_qsns.Design_qsns_java.Design_instagram_feed.models.*;
import Design_qsns.Design_qsns_java.Design_instagram_feed.strategy.IShowFeedStrategy;
import Design_qsns.Design_qsns_java.Design_instagram_feed.strategy.ShowFeedByRecency;
import java.util.*;

public class FeedSvc {
    private IShowFeedStrategy showFeedStrategy = null;
    RegistrationSvc registrationSvc = null;
    public void setStrategy(IShowFeedStrategy strategy) {
        this.showFeedStrategy = strategy;
    }

   FeedSvc(RegistrationSvc registrationSvc) {
    this.registrationSvc = registrationSvc;
    this.showFeedStrategy = new ShowFeedByRecency();
    }
    
    public void viewFeed(User u) {
        HashSet<User> usersList = registrationSvc.getUsersList();
        if(usersList.contains(u) == false) {
            System.out.println("User doesn't exist in system, cannot view feed");
            return;
        }

        if(showFeedStrategy == null) {
            System.out.println("No feed strategy set, cannot view feed");
            return;
        }
        //get all posts of user and their friends
        System.out.println("Viewing feed for user: " + u.getUserId());
        HashSet<Post> userPosts = u.getAllPosts();
        HashSet<User> friendsList = u.getAllFriends();
        ArrayList<Post> feedPosts = new ArrayList<>();

        for(User friend : friendsList) {
            for(Post post : friend.getAllPosts()) {
                feedPosts.add(post);
            }
        }

        feedPosts.addAll(userPosts);
        showFeedStrategy.showFeed(feedPosts);
    }
}
