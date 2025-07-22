package Design_qsns.Design_qsns_java.Design_library_mgmt_service.service;

import Design_qsns.Design_qsns_java.Design_library_mgmt_service.models.*;

public class BookManagementSvc {
    private static BookManagementSvc instance;
    private static BookManager bookManagerInstance;

    public static BookManagementSvc getInstance() {
        if(instance == null) {
            synchronized (BookManagementSvc.class) {
                if(instance == null) {
                    instance = new BookManagementSvc();
                    bookManagerInstance = new BookManager();
                    System.out.println("BookManagementSvc and book manager instance created");
                }
            }
        }
        return instance;
    }

    public static BookManager getBookManager() {
        return bookManagerInstance;
    }

    public void addBook(Book book) {
        bookManagerInstance.addBook(book);
    }

    public void deleteBook(int id) {
        bookManagerInstance.deleteBook(id);
    }

    public void updateBook(int id ,Book book) {
        bookManagerInstance.updateBook(id, book);
    }

    public void register(User u) {
        bookManagerInstance.register(u);
    }

    public void returnBook(int id , User u) { // on returning book only pay the fine amount
        bookManagerInstance.returnBook(id, u);
    }

    public void issueBook(int id , User u) {
        bookManagerInstance.issueBook(id, u);
    }

    public void viewProfile(User u) {
        bookManagerInstance.viewProfile(u);
    }

    public void inspectBooksForNotification() {
        bookManagerInstance.inspectBooksForNotification();
        System.out.println("Notification sent to users having book  with due date");
    }
    
}
