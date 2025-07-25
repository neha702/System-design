package Design_qsns.Design_qsns_java.Design_vending_machine.factory;

import Design_qsns.Design_qsns_java.Design_vending_machine.models.*;

public class CreateDenominationFactory {
    public IDenomination createDenominationFactory(int amount , String denominationString) {
        if(denominationString == "COIN") {
            return new Coin(amount);
        } else if(denominationString == "NOTE") {
            return new Note(amount);
        } else {
            System.out.println("Invalid denomination type");
            return null;
        }
    }
}