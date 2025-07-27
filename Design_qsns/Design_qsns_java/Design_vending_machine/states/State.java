package Design_qsns.Design_qsns_java.Design_vending_machine.states;

import Design_qsns.Design_qsns_java.Design_vending_machine.models.*;
import Design_qsns.Design_qsns_java.Design_vending_machine.services.*;

public interface State {
    public boolean insertValue(IDenomination value , User u , BalanceService balanceService , StateService stateSvc); // false for not allowed situation
    public Product selectProduct(String productId , ProductService productSvc , StateService stateSvc , BalanceService balanceService);  //null for not allowed situation or or no product found
    public boolean dispenseProduct(Product product , BalanceService balanceService , StateService stateSvc , ProductService productSvc); // false for not allowed situation
    public boolean cancelTransaction(User u , BalanceService balanceService , StateService stateSvc); // false for not allowed situation
    public int returnChange(Product product , User u , BalanceService balanceService, StateService stateSvc); // -1 for  not allowed situation
}
