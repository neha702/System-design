//It helps to create families of related objects without creating concrete classes.
package Design_qsns.Design_patterns_java.Creational_design_pattern;

import java.util.*;

interface IFactory { // interface for factory
    ICar createCar();
    IBike createBike();
}

class HyundaiFactory implements IFactory {
    public ICar createCar() {
        return new HyundaiCar();
    }

    public IBike createBike() {
        return new HyundaiBike();
    }
}

class TataFactory implements IFactory {
    public ICar createCar() {
        return new TataCar();
    }

    public IBike createBike() {
        return new TataBike();
    }
}
 
interface ICar { //interface for car
    void show();
}

interface IBike {
    void show();
}

class HyundaiCar implements ICar { //interface for bike
    public void show() {
        System.out.println("Hyundai Car shown");
    }
}

class HyundaiBike implements IBike {
    public void show() {
        System.out.println("Hyundai Bike shown");
    }
}

class TataCar implements ICar {
    public void show() {
        System.out.println("Tata Car shown");
    }
}

class TataBike implements IBike {
    public void show() {
        System.out.println("Tata Bike shown");
    }
}

public class AbstractFactoryDesignPattern {
    private static IFactory createFactory(String factoryType) {
        switch(factoryType) {
            case "Hyundai":
                return new HyundaiFactory();
            case "Tata":
                return new TataFactory();
            default:
                System.out.println("factory doesnt exist of this type");
                return null;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String factoryType = scanner.nextLine();
        IFactory factory = createFactory(factoryType);
        factory.createCar().show();
        factory.createBike().show();
        scanner.close();
    }
}
