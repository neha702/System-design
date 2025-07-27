package Design_qsns.Design_qsns_java.Design_instagram_feed.services;
import Design_qsns.Design_qsns_java.Design_instagram_feed.models.*;

public class InstaSvc {
//Create interfaces from next time to allow for better flexibility for mocking since now instasvc directly depending on sb services
 private FollowSvc followSvc = null;
 private FeedSvc feedSvc = null;
 private LikeSvc likeSvc = null;
 private CommentSvc commentSvc = null;
 private PostSvc postSvc = null;
 private RegistrationSvc registrationSvc = null;
 public static InstaSvc instaSvcInstance = null;

 private InstaSvc() {
     this.registrationSvc = new RegistrationSvc();
     this.followSvc = new FollowSvc(registrationSvc);
     this.postSvc = new PostSvc(registrationSvc);
     this.feedSvc = new FeedSvc(registrationSvc);
     this.likeSvc = new LikeSvc(postSvc , registrationSvc);
     this.commentSvc = new CommentSvc(registrationSvc , postSvc);
 }

 public static InstaSvc getInstance() {
     if (instaSvcInstance == null) {
         synchronized(InstaSvc.class) {
            if(instaSvcInstance == null) {
                instaSvcInstance = new InstaSvc();
            }
        }
    }
    return instaSvcInstance;
 }

 public void register(User u) {
    registrationSvc.register(u);
 }

 public void followUser(User followeeId , User followerId) {
    followSvc.followUser(followeeId , followerId);
 }

 public void unfollowUser(User followeeId , User followerId) {
    followSvc.unfollowUser(followeeId , followerId);
 }

 public void addPost(Post p , User u) {
    postSvc.addPost(p, u);
 }

 public void removePost(Post p , User u) {
    postSvc.removePost(p , u);
 }

 public void viewFeed(User u) {
    feedSvc.viewFeed(u);
 }

 public void likePost(Post p , User u) {
    likeSvc.likePost(p, u);
 }

 public void unlikePost(Post p , User u) {
    likeSvc.unlikePost(p, u);
 }

 public void removeComment(Post p , Comment c) {
    commentSvc.removeComment(p, c);
 }

 public void addComment(Post p , Comment c) {
        commentSvc.addComment(p, c);
 }

 public void viewComments(Post p) {
     postSvc.viewComments(p);
 }

 public void viewLikes(Post p) {
   postSvc.viewLikes(p);
}

}
