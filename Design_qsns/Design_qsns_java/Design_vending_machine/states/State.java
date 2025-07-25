package Design_qsns.Design_qsns_java.Design_vending_machine.states;

import Design_qsns.Design_qsns_java.Design_vending_machine.models.*;
import Design_qsns.Design_qsns_java.Design_vending_machine.services.VendingMachineSvc;
import Design_qsns.Design_qsns_java.Design_vending_machine.services.VendingSvcManager;

public interface State {
    public boolean insertValue(IDenomination value , User u , VendingMachineSvc instance); // false for not allowed situation
    public Product selectProduct(String productId , VendingMachineSvc instance , VendingSvcManager managerInstance);  //null for not allowed situation or or no product found
    public boolean dispenseProduct(Product product , VendingMachineSvc instance , VendingSvcManager managerInstance); // false for not allowed situation
    public boolean cancelTransaction(User u , VendingMachineSvc instance); // false for not allowed situation
    public int returnChange(Product product , User u , VendingMachineSvc instance); // -1 for  not allowed situation
}
