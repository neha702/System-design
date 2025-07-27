package Design_qsns.Design_qsns_java.Design_instagram_feed.services;
import Design_qsns.Design_qsns_java.Design_instagram_feed.models.*;
import java.util.*;

public class PostSvc {
    RegistrationSvc registrationSvc = null;
    Map<Integer , Post> postMap;

    PostSvc(RegistrationSvc registrationSvc) {
        postMap = new HashMap<>();
        this.registrationSvc = registrationSvc;
    }

    void addPost(Post p , User u) {
        HashSet<User> usersList = registrationSvc.getUsersList();
        if(usersList.contains(u) == false) {
            System.out.println("User doesn't exist in system, cannot add post");
            return;
        }
        int post_id = p.getPostId();
        String user_id = p.getUser().getUserId();
        if(u.getUserId().equals(user_id) == false) {
            System.out.println("Post user id " + user_id + " does not match with user id " + u.getUserId());
            return;
        }

        if(postMap.containsKey(post_id)) {
            System.out.println("Post already exists with post_id " + post_id);
        } else {
            postMap.put(post_id , p);
            u.addPost(p);
        }
    }

    void removePost(Post p , User u) {
        HashSet<User> usersList = registrationSvc.getUsersList();
        if(usersList.contains(u) == false) {
            System.out.println("User doesn't exist in system, cannot remove post");
            return;
        }

        String user_id = p.getUser().getUserId();
        if(u.getUserId().equals(user_id) == false) {
            System.out.println("Post user id " + user_id + " does not match with user id " + u.getUserId());
            return;
        }
        
        int post_id = p.getPostId();
        if(postMap.containsKey(post_id)) {
            postMap.remove(post_id);
            u.removePost(p);
        } else {
            System.out.println("Post doesn't exist with post_id " + post_id);
        }
    }

    public boolean ifPostExists(int postId) {
        return postMap.containsKey(postId);
    }

    public Post getPostFromId(int postId) {
        if(postMap.containsKey(postId) == true) {
            return postMap.get(postId);
        } else{
            return null;
        }
    }

    public Map<Integer, Post> getPostMap() {
        return postMap;
    }

    public void viewComments(Post p) {
        if(p == null) {
            System.out.println("Post cannot be null");
            return;
        }

        if(postMap.containsKey(p.getPostId()) == false) {
            System.out.println("Post with id " + p.getPostId() + " does not exist, cannot view comments");
            return;
        }

        System.out.println("Showing comments for post with id " + p.getPostId());
        for(Comment c : p.getComments()) {
            System.out.println("Comment by user " + c.getCommentedBy().getUserId() + ": " + c.getCommentText());
        }
    }

    public void viewLikes(Post p) {
        if(p == null) {
            System.out.println("Post cannot be null");
            return;
        }

        if(postMap.containsKey(p.getPostId()) == false) {
            System.out.println("Post with id " + p.getPostId() + " does not exist, cannot view likes");
            return;
        }

        System.out.println("Showing likes for post with id " + p.getPostId());
        for(User u : p.getLikedUsers()) {
            System.out.println("Liked by user id " + u.getUserId());
        }
    }
    
}
