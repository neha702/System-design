package Design_qsns.Design_qsns_java.Design_instagram_feed;

import Design_qsns.Design_qsns_java.Design_instagram_feed.models.*;
import Design_qsns.Design_qsns_java.Design_instagram_feed.services.InstaSvc;

public class Demo {
    public static void main(String []args) {
        InstaSvc instaService = InstaSvc.getInstance();

        User u1 = new User("Neha" , "optimist.2001" , "Das");
        User u2 = new User("Rohan" , "rohan.2000" , "Sharma");

        Post p1 = new Post(1 , u1 , "Hello World!");
        Post p2 = new Post(2 , u2 , "Learning Java is fun!");
        Post p3 = new Post(3 , u1 , "How beautiful is life!");

        instaService.register(u1);
        instaService.register(u2);

        instaService.addPost(p1, u1);
        instaService.addPost(p2, u2);
        instaService.addPost(p3, u1);

        instaService.followUser(u1, u2);

        instaService.viewFeed(u1);


        Comment c1 = new Comment(1 , 1 , "Great post!" , u2);
        Comment c2 = new Comment(2 , 1 , "Love u guys!" , u1);
        instaService.addComment(p1, c1);
        instaService.addComment(p1, c2);
        instaService.addComment(p3, c2);
        instaService.removeComment(p1, c2);
        instaService.likePost(p1, u2);
        instaService.unlikePost(p1, u2);

        instaService.viewComments(p1);
        instaService.viewLikes(p1);
    }
}
