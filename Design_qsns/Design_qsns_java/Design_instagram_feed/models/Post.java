package Design_qsns.Design_qsns_java.Design_instagram_feed.models;

import java.time.LocalDateTime;
import java.util.*;

public class Post {
    private int id;
    private User u;
    private ArrayList<Comment>comments;
    private ArrayList<User>likes;
    private String data;
    public LocalDateTime date;

    public Post(int id, User u , String data) {
        this.id = id;
        this.u = u;
        this.date = LocalDateTime.now();
        this.data = data;
        this.comments = new ArrayList<>();
        this.likes = new ArrayList<>();
    }

    public ArrayList<Comment> getComments() {
        return comments;
    }

    public ArrayList<User> getLikedUsers() {
        return likes;
    }

    public int getPostId() {
        return id;
    }

    public void addLike(User u) {
        likes.add(u);
    } 

    public void removeLike(User u) {
        likes.remove(u);
    } 

    public void addComment(Comment c) {
        comments.add(c);
    } 

    public void removeComment(Comment c) {
        comments.remove(c);
    }
    
    public User getUser() {
        return u;
    }

    public String getData() {
        return data;
    }
}
