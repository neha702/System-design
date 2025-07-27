package Design_qsns.Design_qsns_java.Design_vending_machine.services;

import Design_qsns.Design_qsns_java.Design_vending_machine.models.*;

public class VendingMachineSvc {
    private static VendingMachineSvc vendingMachineInstance = null;
    private ProductService productSvcInstance = null;
    private BalanceService balanceSvcInstance = null;
    private StateService stateSvcInstance = null;

    private VendingMachineSvc() {
        productSvcInstance = new ProductService();
        balanceSvcInstance = new BalanceService();
        stateSvcInstance = new StateService(productSvcInstance , balanceSvcInstance);
    }

    public ProductService getProductServiceInstance() {
        return productSvcInstance;
    }

    public StateService getStateServiceInstance() {
        return stateSvcInstance;
    }

    public static VendingMachineSvc getInstance() {
        if(vendingMachineInstance == null) {
            synchronized (VendingMachineSvc.class) {
                if(vendingMachineInstance == null) {
                    vendingMachineInstance = new VendingMachineSvc();
                }
            }
        }
        return vendingMachineInstance;
    }

    public boolean insertDenomination(int amount , String denominationString , User u) {
       return stateSvcInstance.insertDenomination(amount, denominationString, u);
    }

    public Product selectProduct(String productId) {
        return stateSvcInstance.selectProduct(productId);
    }

    public boolean dispenseProduct(Product product) {
        return stateSvcInstance.dispenseProduct(product);
    }

    public int dispenseChange(Product product , User u) {
        return stateSvcInstance.dispenseChange(product , u);
    }

    public boolean cancelTransaction(User u) {
        return stateSvcInstance.cancelTransaction(u);
    }

    public void viewBalances(User u) {
        balanceSvcInstance.viewBalances(u);
    }
}
