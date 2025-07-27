package Design_qsns.Design_qsns_java.Design_instagram_feed.models;
import java.time.LocalDateTime;

public class Comment {
    private int id;
    private int post_id;
    private String text;
    private User commentedBy;
    LocalDateTime date;
    public Comment(int id, int post_id, String text, User commentedBy) {
        this.id = id;
        this.post_id = post_id;
        this.text = text;
        this.commentedBy = commentedBy;
        this.date = LocalDateTime.now();
    }

    public int getPostId() {
        return post_id;
    }

    public String getCommentText() {
        return text;
    }

    public User getCommentedBy() {
        return commentedBy;
    }  
}
