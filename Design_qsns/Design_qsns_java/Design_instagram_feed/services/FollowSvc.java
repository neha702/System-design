package Design_qsns.Design_qsns_java.Design_instagram_feed.services;
import Design_qsns.Design_qsns_java.Design_instagram_feed.models.User;
import java.util.*;

public class FollowSvc {
    RegistrationSvc registrationSvc = null;
    FollowSvc(RegistrationSvc svc) {
        this.registrationSvc = svc;
    }

    public void followUser(User followeeUser , User followerUser) {
        //users should exist in system to follow/unfollow eachother
        HashSet<User> usersList = registrationSvc.getUsersList();
        if(usersList.contains(followeeUser) == true && usersList.contains(followerUser) == true) {
            followeeUser.addUserToFriendsList(followerUser);
        } else {
            System.out.println("Some user doesnt exist in system, cannot follow");
        }
    }

    public void unfollowUser(User followeeUser , User followerUser) {
        //users should exist in system to follow/unfollow eachother
        HashSet<User> usersList = registrationSvc.getUsersList();
        if(usersList.contains(followeeUser) == true && usersList.contains(followerUser) == true) {
            followeeUser.addUserToFriendsList(followerUser);
        } else {
            System.out.println("Some user doesnt exist in system, cannot unfollow");
        }
    }
}
