package Design_qsns.Design_qsns_java.Design_instagram_feed.services;
import Design_qsns.Design_qsns_java.Design_instagram_feed.models.*;
import java.util.HashSet;
import java.util.Map;

public class CommentSvc {
    RegistrationSvc registrationSvc = null;
    PostSvc postSvc = null;
    HashSet<Comment> commentsList = null;
    CommentSvc(RegistrationSvc registrationSvc , PostSvc postSvc) {
        this.registrationSvc = registrationSvc;
        this.postSvc = postSvc;
        commentsList = new HashSet<>();
    }
    public void addComment(Post p , Comment c) {
        if(p == null || c==null) {
            System.out.println("Post or Comment cannot be null");
            return;
        } 

        if(commentsList.contains(c)) {
            System.out.println("Comment already exists, cannot add comment on post");
            return;
        }

        User u = p.getUser();
        HashSet<User> usersList = registrationSvc.getUsersList();
        if(usersList.contains(u) == false) {
            System.out.println("User doesn't exist in system, cannot comment on it!");
            return;
        }

        if(c.getPostId() != p.getPostId()) {
            System.out.println("Comment post id does not match with post id, cannot comment on post");
            return;
        }

        Map<Integer , Post> postMap = postSvc.getPostMap();
        if(postMap == null) {
            System.out.println("Post map is empty, cannot comment on post");
            return;
        }

        if(postMap.containsKey(p.getPostId()) == false) {
            System.out.println("Post with id " + p.getPostId() + " does not exist, cannot comment on post");
            return;
        }

        p.addComment(c);
        System.out.println("Comment added successfully by user " + c.getCommentedBy().getUserId() + " on post " + p.getPostId());
    } 

    public void removeComment(Post p , Comment c) {
        if(p == null || c==null) {
            System.out.println("Post or Comment cannot be null");
            return;
        } 

        if(commentsList.contains(c)) {
            System.out.println("Comment already exists, cannot uncomment on post");
            return;
        }

        User u = p.getUser();
        HashSet<User> usersList = registrationSvc.getUsersList();
        if(usersList.contains(u) == false) {
            System.out.println("User doesn't exist in system, cannot remove comment on it!");
            return;
        }

        Map<Integer , Post> postMap = postSvc.getPostMap();
        if(postMap == null) {
            System.out.println("Post map is empty, cannot uncomment on post");
            return;
        }

        if(postMap.containsKey(p.getPostId()) == false) {
            System.out.println("Post with id " + p.getPostId() + " does not exist, cannot uncomment on post");
            return;
        }
        p.removeComment(c);
        System.out.println("Comment removed successfully by user " + c.getCommentedBy().getUserId() + " on post " + p.getPostId());
    } 
}
