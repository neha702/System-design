package Design_qsns.Design_qsns_java.Design_vending_machine.services;

import Design_qsns.Design_qsns_java.Design_vending_machine.models.Product;
import java.util.*;

public class ProductService {
    ArrayList<Product> productsList;
    Map<String , Product> productsMap;

    ProductService() {
        productsList = new ArrayList<>();
        productsMap = new HashMap<>();
    }

    public void addProduct(Product product) {
        if(product != null) {
            productsList.add(product);
            productsMap.put(product.getCode() , product);
            System.out.println("Product added with code : " + product.getCode());
        }
    }

    public void removeProduct(Product product) {
        if(product != null) {
            productsList.remove(product);
            productsMap.remove(product.getCode());
            System.out.println("Product remove with code : " + product.getCode());
        }
    }

    public boolean isProductAvailable(String productCode) {
        return productsMap.containsKey(productCode);
    }

    public Product getProduct(String productId) {
        return productsMap.get(productId);
    }
    
}
