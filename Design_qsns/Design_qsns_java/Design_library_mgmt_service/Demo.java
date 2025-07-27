package Design_qsns.Design_qsns_java.Design_library_mgmt_service;

import Design_qsns.Design_qsns_java.Design_library_mgmt_service.models.*;
import Design_qsns.Design_qsns_java.Design_library_mgmt_service.service.*;
/*
 Requirements:
 1. A library management system that allows users to register, view their profile, issue books, and return books.
 2. A user should be registered to system to view their profile , issue books(if exist) and return book only if he has taken or book exists.
 3  Admin can add , remove or update books.
 4. Admin can inspect all books taken by users in interval of time and send notification to users who have taken books with due date and fine.
 5. While returning book , user need to pay fine if any.
 6. There can be different strategies for fine calculation and payment methods.
 */

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
