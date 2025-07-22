package Design_qsns.Design_qsns_java.Design_library_mgmt_service.models;

import java.time.LocalDate;
import java.util.*;


public class Book {
    private int id;
    private String name;
    private String author;
    private String genre;
    private int quantity;
    private Map<User , IssueRecord> issuedBooks;
    private ArrayList<IObserver> observers;

    public Book(int id , String name , String author , String genre , int quantity) {
        this.id = id;
        this.name = name;
        this.author = author;
        this.genre = genre;
        this.quantity = quantity;
        this.issuedBooks = new HashMap<>();
        this.observers = new ArrayList<>();
        observers.add(new SMSObserver());
        observers.add(new MailObserver());
    }

    public int getId() {
        return id;
    }

    public String getBookName() {
        return name;
    }

    public void decQuantity() {
        this.quantity--;
    }

    public int getQuantity() {
        return quantity;
    }

    public void incQuantity(int quantity) {
        this.quantity += quantity;
    }

    public IssueRecord issueBook(int id , User u)  {
        if(quantity == 0) {
            return null;
        } else {
            IssueRecord record = new IssueRecord(id , u , LocalDate.now(), LocalDate.now().plusDays(1));
            if(issuedBooks.containsKey(u)) {
               System.err.println("User already has a book issued!");
               return null;
            } else {
                issuedBooks.put(u, record);
            }
            this.quantity--;
            return record;
        }
    }

    public void returnBook(User u)  {
            if(issuedBooks.containsKey(u)) {
                issuedBooks.remove(u);
                this.quantity++;
            } else {
                System.out.println("User has no book issued!");
            }
    } 
    
    public void inspectBooksForNotification() {
        LocalDate currDate = LocalDate.now().plusDays(3);
        for(User u : issuedBooks.keySet()) {
            IssueRecord record = issuedBooks.get(u);
            if(record.getDueDate().isBefore(currDate) || record.getDueDate().isEqual(currDate)) {
                System.out.println("Book " + name + " is overdue for user " + u.getName());
                for(IObserver observer : observers) {
                    observer.notify("User "+ u.getName() + " has an overdue book: " + name);
                }
            }
        }
    }

}
