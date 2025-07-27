package Design_qsns.Design_qsns_java.Design_instagram_feed.models;

import java.util.HashSet;

public class User {
    private String name;
    private String user_id;
    private String surname;
    private HashSet<User>friendsList; 
    private HashSet<Post>posts;
    private HashSet<Post>likedPosts;
    private HashSet<Post>commentedPosts;

    public User(String name , String user_id, String surname) {
        this.name = name;
        this.user_id = user_id;
        this.surname = surname;
        this.friendsList = new HashSet<>();
        this.posts = new HashSet<>();
        this.likedPosts = new HashSet<>();
        this.commentedPosts = new HashSet<>();
    }

    public String getUserId() {
        return user_id;
    }

    public void addPost(Post p) {
        if(posts.contains(p) == true) {
            System.out.println("Post already exist with post id: " + p.getPostId());
        } else {
            posts.add(p);
            System.out.println("Post added to user profile with post id: " + p.getPostId());
        }
    }

    public void removePost(Post p) {
        if(posts.contains(p) == true) {
            posts.remove(p);
            System.out.println("Post removed from user profile with post id: " + p.getPostId());
        } else {
            System.out.println("Post doesn't exist to be removed from user profile with postid: " + p.getPostId());
        }
    }

    public void addUserToFriendsList(User u) {
        if(friendsList.contains(u) == true) {
            System.out.println("User already exists in friends list");
        } else {
            friendsList.add(u);
            System.out.println("User added to friends list successfully");
        }
    }

    public void removeUserToFriendsList(User u) {
        if(friendsList.contains(u) == true) {
            friendsList.remove(u);
            System.out.println("User removed from friends list successfully");
        } else {
            System.out.println("User doesn't exist in friends list to be removed");
        }
    }

    public void addToLikedPosts(Post p) {
        likedPosts.add(p);
        System.out.println("Post with post id: " + p.getPostId() + " liked successfully");
    }

    public void removeFromLikedPosts(Post p) {
        likedPosts.remove(p);
        System.out.println("Post with post id: " + p.getPostId() + " unliked successfully");
    }

    public void addToCommentedPosts(Post p) {
        commentedPosts.add(p);
        System.out.println("Comment on post with post id: " + p.getPostId() + " added successfully");
    }

    public void removeFromCommentedPosts(Post p) {
        commentedPosts.remove(p);
        System.out.println("Comment on post with post id: " + p.getPostId() + " removed successfully");
    }

    public HashSet<Post> getAllPosts() {
        return posts;
    }

    public HashSet<User> getAllFriends() {
        return friendsList;
    }
}
