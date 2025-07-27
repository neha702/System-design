package Design_qsns.Design_qsns_java.Design_instagram_feed.services;

import Design_qsns.Design_qsns_java.Design_instagram_feed.models.*;
import java.util.*;

public class LikeSvc {
    RegistrationSvc registrationSvc = null;
    PostSvc postSvc = null;
    LikeSvc(PostSvc postSvc , RegistrationSvc registrationSvc) {
        this.postSvc = postSvc;
        this.registrationSvc = registrationSvc;
    }

    public void likePost(Post p , User u) {
        Map<Integer , Post> postMap = postSvc.getPostMap();
        if(postMap == null) {
            System.out.println("Post map is empty, cannot like post");
            return;
        }

        if(postMap.containsKey(p.getPostId()) == false) {
            System.out.println("Post with id " + p.getPostId() + " does not exist, cannot like post");
            return;
        }
        if(p == null) {
            System.out.println("Post cannot be null");
            return;
        }

        HashSet<User> usersList = registrationSvc.getUsersList();
        if(usersList.contains(u) == false) {
            System.out.println("User doesn't exist in system, cannot like post");
            return;
        }

        int post_id = p.getPostId();
        if(postSvc.ifPostExists(post_id )== false) {
            System.out.println("Post doesnt exist to be liked");
            return;
        } 

        p.addLike(u);
        u.addToLikedPosts(p);
    }

    public void unlikePost(Post p , User u) {
        HashSet<User> usersList = registrationSvc.getUsersList();
        if(usersList.contains(u) == false) {
            System.out.println("User doesn't exist in system, cannot unlike post");
            return;
        }

        if(p == null) {
            System.out.println("Post cannot be null");
            return;
        }

        Map<Integer , Post> postMap = postSvc.getPostMap();
        if(postMap == null) {
            System.out.println("Post map is empty, cannot unlike post");
            return;
        }

        if(postMap.containsKey(p.getPostId()) == false) {
            System.out.println("Post with id " + p.getPostId() + " does not exist, cannot unlike post");
            return;
        }

        int post_id = p.getPostId();
        if(postSvc.ifPostExists(post_id )== false) {
            System.out.println("Post doesnt exist to be unliked");
            return;
        } 

        p.removeLike(u);
        u.removeFromLikedPosts(p);
    }
}
