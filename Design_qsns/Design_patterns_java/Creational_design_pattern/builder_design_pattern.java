//Builder design pattern is used to create complex objects step by step , example could be a burger with cheese , mayo and leetuce , instead
//of passing all these fields in constructor once we can first create the burger then add the contents one by one to create the whole burger
//Here since we creating product step by step so we can get intermediate product also , and there is a director that would giv ethe sequence in which product 
//needs to be built
package Design_qsns.Design_patterns_java.Creational_design_pattern;

interface Builder {
    House buildRoof();
    House buildWalls();
    House buildFloor();
}

class House {
    public String roof;
    public String walls;
    public String floor;
}

class HouseBuilder implements Builder {
    private House house;
    HouseBuilder(House house) {
        super();
        this.house = house;
    }
    public House buildRoof() {
        System.out.println("Building roof");
        house.roof = "Roof built";
        return house;
    }

    public House buildWalls() {
        System.out.println("Building walls");
        house.walls = "Walls built";
        return house;
    }

    public House buildFloor() {
        System.out.println("Building floor");
        house.floor = "Floor built";
        return house;
    }
}

class Director {
    private Builder houseBuilder;
    Director(Builder houseBuilder) {
        this.houseBuilder = houseBuilder;
    }

    House constructHouse() {
       houseBuilder.buildRoof();
       houseBuilder.buildWalls();
       House house = houseBuilder.buildFloor();
       return house;
    }
}

public class builder_design_pattern {
    public static void main(String[] args) {
        House house1 = new House();
        Builder houseBuilder = new HouseBuilder(house1);
        Director director = new Director(houseBuilder);
        director.constructHouse();

    }
}
