package Design_qsns.Design_qsns_java.Design_library_mgmt_service.service;

import Design_qsns.Design_qsns_java.Design_library_mgmt_service.models.*;
import Design_qsns.Design_qsns_java.Design_library_mgmt_service.strategy.*;
import java.time.LocalDate;
import java.time.temporal.ChronoUnit;
import java.util.*;

public class BookManager {
    private Map<Integer , Book> booksMap;
    private Map<Integer, User> userMap;
    private Map<String , Book> bookByNameMap;
    IFineStrategy fineStrategy;
    IPaymentStrategy paymentStrategy;

    BookManager() {
        this.booksMap = new HashMap<>();
        this.userMap = new HashMap<>();
        this.bookByNameMap = new HashMap<>();
        fineStrategy = new FineStrategyByDay();
        paymentStrategy = new PaymentStrategyByCash();
    }

    public void setStrategy(IFineStrategy strategy) {
        this.fineStrategy = strategy;
    }

    public void addBook(Book book) {
        if(booksMap.containsKey(book.getId())) {
            System.out.println("Book already exists!");
            return;
        }
        booksMap.put(book.getId() , book);
        bookByNameMap.put(book.getBookName() , book);
        System.out.println("Book added: " + book.getBookName());
    }

    public void refillBookQuantity(int id , int quantity) {
        if(!booksMap.containsKey(id)) {
            System.out.println("Book not found, so can't be refilled!");
            return;
        }

        Book book = booksMap.get(id);
        book.incQuantity(quantity);
    }

    public void deleteBook(int id) {
        if(!booksMap.containsKey(id)) {
            System.out.println("Book not found!");
            return;
        }
        
        Book book = booksMap.get(id);
        book.decQuantity();
        if(book.getQuantity() == 0) {
            booksMap.remove(book);
            System.out.println("Book deleted: " + book.getBookName());
        } else {
            System.out.println("Book quantity reduced: " + book.getBookName()); 
        }
    }

    public void updateBook(int id , Book book) {
        booksMap.put(id , book);
        System.out.println("Book updated: "+ book.getBookName());
    }

    public void register(User u) {
        if(userMap.containsKey(u.getId())) {
            System.out.println("User already exists!");
        } else {
            System.out.println("User registered: " + u.getName());
            userMap.put(u.getId() , u);
        }
    }

    public void issueBook(int id , User u) {
        //check if user exist in db
        if(!userMap.containsKey(u.getId())) {
            System.out.println("User doesn't exist!");
            return;
        }
        if(!booksMap.containsKey(id)) {
            System.out.println("Book not found!");
            return;
        } else {
            Book book = booksMap.get(id);
            IssueRecord record = book.issueBook(id ,u);
            if(record == null) {
                System.out.println("Book not available");
                return;
            }
            u.addIssueRecord(record);
            System.out.println("Book issued: " + book.getBookName());
        }
    }

    public void viewProfile(User u) {
        System.out.println("User name: " + u.getName() + " , User id: " + u.getId() + " , User email " + u.getEmail() );
        System.out.println("Issued books are: ");
        ArrayList<IssueRecord> records = u.getIssueRecords();
        for(IssueRecord record : records) {
            System.out.println("Book id: " + record.getBookId());
        }
    }

    public void returnBook(int id , User u) {
        //check if user exist in db
        if(!userMap.containsKey(u.getId())) {
            System.out.println("User doesn't exist!");
            return;
        }
        if(!booksMap.containsKey(id)) {
            System.out.println("Book not found!");
            return;
        } else {
            Book book = booksMap.get(id);
            book.returnBook(u);
            ArrayList<IssueRecord> records = u.getIssueRecords();
            if(records.size() > 0) {
                    for(IssueRecord record : records) {
                        if(record.getId() == id) {
                            u.removeIssueRecord(record);
                            long days = ChronoUnit.DAYS.between(record.getDueDate(), LocalDate.now().plusDays(15)); 
                            System.out.println("Days: " + days);
                            long fine = fineStrategy.computeFine(5 , days);
                            paymentStrategy.pay(fine);
                            break;
                        }
                    }
                System.out.println("Book returned: " + book.getBookName());
            } else {
                System.out.println("Book was never issued to be returned");
            }
        }
    }

    public void inspectBooksForNotification() {
        for(int bookId : booksMap.keySet()) {
            Book book = booksMap.get(bookId);
            book.inspectBooksForNotification();
        }
    }
}