//factory pattern is where we dont need to call constructors directly, client doesnt need to worry about concrete classes for that 
//and can call the factory to create object instead
package Design_qsns.Design_patterns_java.Creational_design_pattern;

class ShapeFactory {
    public Shape createShape(String shapeType) {
        switch(shapeType) {
            case "CIRCLE": Shape circle = new Circle();
                            return circle;
            case "SQUARE": Shape square = new Square();
                            return square;
            default : System.out.println("Shape not found!");
                      return null;
                            
        }
    }
}

interface Shape {
    void draw();
}

class Circle implements Shape {
    public void draw() {
        System.out.println("Drawing circle");
    }
}

class Square implements Shape {
    public void draw() {
        System.out.println("Drawing square");
    }
}

public class factory_design_pattern {
    public static void main(String[] args){
        ShapeFactory shapeFactory = new ShapeFactory();
        Shape shape = shapeFactory.createShape("SQUARE");
        if(shape != null)
            shape.draw();
    }
}
