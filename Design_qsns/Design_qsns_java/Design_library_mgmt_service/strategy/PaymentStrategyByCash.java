package Design_qsns.Design_qsns_java.Design_library_mgmt_service.strategy;

public class PaymentStrategyByCash implements IPaymentStrategy {
    public void pay(long amount) {
        System.out.println("Payment made by cash: " + amount);
    }   
}
