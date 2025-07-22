//Decorator design pattern comes into picture when we need to add additional functionality without modifying structure
package Design_qsns.Design_patterns_java.Structural_design_pattern;

interface Coffee { // component interface
   public int getCost();
}

class PlainCoffee implements Coffee { // concrete componnet
    public int getCost() {
        return 10;
    }
}

class CappucinoCoffee implements Coffee { // concrete componnet
    public int getCost() {
        return 50;
    }
}

abstract class IDecorator implements Coffee { // decorator interface , made abstract since its never used
    Coffee bcoffee;
    IDecorator(Coffee coffee) {
        this.bcoffee = coffee;
    }
    public int getCost() {
        return bcoffee.getCost();
    }
}

class SugarDecorator extends IDecorator {
    SugarDecorator(Coffee coffee) {
        super(coffee);
    }

    public int getCost() {
        return bcoffee.getCost() + 2; // Rs 2 for sugar decorating
    }
}

class CreamDecorator extends IDecorator {
    CreamDecorator(Coffee coffee) {
        super(coffee);
    }

    public int getCost() {
        return bcoffee.getCost() + 5; // Rs 5 for cream decorating
    }
}



public class DecoratorDesignPattern {
    public static void main(String[] args) {
        Coffee pcoffee = new PlainCoffee();
        System.out.println("Cost of plain coffee: " + pcoffee.getCost());
        Coffee plainCoffeeWithSugar = new SugarDecorator(pcoffee);
        System.out.println("Cost of plain coffee with sugar: " + plainCoffeeWithSugar.getCost());

        Coffee cappucino = new CappucinoCoffee();
        Coffee cappucinoCoffeeWithCream = new CreamDecorator(cappucino);
        System.out.println("Cost of cappucino coffee with cream: " + cappucinoCoffeeWithCream.getCost());
    }
}
