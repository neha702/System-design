package Design_qsns.Design_qsns_java.Design_vending_machine.models;

public class User {
    String name;
    int id;
    int balance;

    public User(String name , int id ) {
        this.name = name;
        this.id = id;
        System.out.println("User created with name: " + name);
    }

    public void setBalance(int balance) {
        this.balance += balance;
        System.out.println("Current balance of user " + name + ": " + this.balance);
    }

    public int getBalance() {
        return balance;
    }
}
