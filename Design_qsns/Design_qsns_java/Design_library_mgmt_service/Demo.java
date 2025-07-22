package Design_qsns.Design_qsns_java.Design_library_mgmt_service;

import Design_qsns.Design_qsns_java.Design_library_mgmt_service.models.*;
import Design_qsns.Design_qsns_java.Design_library_mgmt_service.service.*;

public class Demo{
    public static void main(String []args) {
        BookManagementSvc bookManagementSvc = BookManagementSvc.getInstance();
        Book book1 = new Book(1 , "Goosebumps" , "R.L. Stine", "Horror", 2);
        Book book2 = new Book(2 , "Ramayana" , "Valmiki", "Mythological", 1);
        bookManagementSvc.addBook(book1);
        bookManagementSvc.addBook(book2);

        User u1 = new User(1 , "Neha" , "neha.ds.702@gmail.com");
        User u2 = new User(2 , "Pratik" , "pratik.ds.702@gmail.com");
        bookManagementSvc.register(u1);
        bookManagementSvc.register(u2);
        bookManagementSvc.issueBook(1, u1);
        bookManagementSvc.issueBook(2, u1);
        bookManagementSvc.returnBook(1, u1);
        bookManagementSvc.issueBook(1, u2);
        bookManagementSvc.viewProfile(u1);

        bookManagementSvc.inspectBooksForNotification();
    }
}
