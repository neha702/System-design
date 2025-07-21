//Strategy design pattern is selecting algorithm based on runtime
package Design_qsns.Design_patterns_java.Behavioral_design_pattern;

interface PaymentStrategy {
    public void pay(int amount);
}

class PaymentByCash implements PaymentStrategy {
    public void pay(int amount) {
        System.out.println("Payment of done with cash of amount: " + amount);
    }
}

class PaymentByCard implements PaymentStrategy {
    public void pay(int amount) {
        System.out.println("Payment of done with card of amount: " + amount);
    }
}

class PaymentService {
    PaymentStrategy paymentStrategy;
    PaymentService(PaymentStrategy paymentStrategy) {
        this.paymentStrategy = paymentStrategy;
    }

    void setPaymentStrategy(PaymentStrategy paymentStrategy) {
        this.paymentStrategy = paymentStrategy;
    }

    void payMoney(int amount) {
        paymentStrategy.pay(amount);
    }
}

public class strategy_design_pattern {
    public static void main(String []args)  {
        PaymentStrategy paymentStrategy1 = new PaymentByCash();
        PaymentService paymentService = new PaymentService(paymentStrategy1);
        paymentService.payMoney(1000);

        PaymentStrategy paymentStrategy2 = new PaymentByCard();
        paymentService.setPaymentStrategy(paymentStrategy2);
        paymentService.payMoney(1500);
    }
}
