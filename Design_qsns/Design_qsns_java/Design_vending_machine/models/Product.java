package Design_qsns.Design_qsns_java.Design_vending_machine.models;

public class Product {
    String code;
    int price;
    String name;
    int quantity;

    public Product(String code , int price , String name , int quantity) {
        this.code = code;
        this.price = price;
        this.name = name;
        this.quantity = quantity;
    }

    public int getQuantity() {
        return quantity;
    }

    public void setQuantity(int quantity) {
        this.quantity -= quantity;
    }

     public String getCode() {
        return code;
    }

    public int getPrice() {
        return price;
    }
}
