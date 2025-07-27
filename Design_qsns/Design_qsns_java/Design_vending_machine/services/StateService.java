package Design_qsns.Design_qsns_java.Design_vending_machine.services;

import Design_qsns.Design_qsns_java.Design_vending_machine.factory.CreateDenominationFactory;
import Design_qsns.Design_qsns_java.Design_vending_machine.models.*;
import Design_qsns.Design_qsns_java.Design_vending_machine.states.*;

public class StateService {
    private CreateDenominationFactory denominationFactory = null;
    private State state = null;
    //Use interfaces for them
    private ProductService productSvc = null;
    private BalanceService balanceSvc= null;
    
    StateService(ProductService productSvc , BalanceService balanceService) {
        denominationFactory = new CreateDenominationFactory();
        state = new IdleState();
        balanceSvc = balanceService;
        productSvc = productSvc;
    }

    public void setState(State newState) {
        state = newState;
    }

    public boolean insertDenomination(int amount , String denominationString , User u) {
        IDenomination denomination = denominationFactory.createDenominationFactory(amount, denominationString);
        if(denomination == null) {
            return false;
        }
        return state.insertValue(denomination , u , balanceSvc , this);
    }

    public Product selectProduct(String productId) {
        return state.selectProduct(productId , productSvc , this , balanceSvc);
    }

    public boolean dispenseProduct(Product product) {
        return state.dispenseProduct(product , balanceSvc , this , productSvc);
    }

    public int dispenseChange(Product product , User u) {
        return state.returnChange(product ,u , balanceSvc , this);
    }

    public boolean cancelTransaction(User u) {
        return state.cancelTransaction(u ,balanceSvc , this);
    }
}