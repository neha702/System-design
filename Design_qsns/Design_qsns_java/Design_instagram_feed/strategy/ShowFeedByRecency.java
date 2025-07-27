package Design_qsns.Design_qsns_java.Design_instagram_feed.strategy;
import Design_qsns.Design_qsns_java.Design_instagram_feed.models.*;
import java.util.ArrayList;
import java.util.Collections;

public class ShowFeedByRecency implements IShowFeedStrategy{
    public void showFeed(ArrayList<Post>posts) {
        //Show posts in descending order of time
        Collections.sort(posts, (a, b) -> b.date.toString().compareTo(a.date.toString()));
        for(Post p : posts) {
            User u = p.getUser();
            System.out.println("Post with post id: " + p.getPostId() + " by user id: " + p.getUser().getUserId() + " at date: " + p.date);
        }
    }
}
