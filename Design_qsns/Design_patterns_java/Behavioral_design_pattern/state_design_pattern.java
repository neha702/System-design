//State design pattern is used to change behaviour of an object when its internal state changes
package Design_qsns.Design_patterns_java.Behavioral_design_pattern;


interface State{
    void pressButton(FanService fanService);
}

class OffState implements State {
    public void pressButton(FanService fanService) {
        System.out.println("Turning the device to low state");
        fanService.setState(new LowState());


    }
}

class LowState implements State {
    public void pressButton(FanService fanService) {
        System.out.println("Turning the device to medium state");
        fanService.setState(new MediumState());
    }
}

class MediumState implements State {
    public void pressButton(FanService fanService) {
        System.out.println("Turning the device to high state");
        fanService.setState(new HighState());
    }
}

class HighState implements State {
    public void pressButton(FanService fanService) {
        System.out.println("Turning the device to off state");
        fanService.setState(new OffState());
    }
}

class FanService {
    State state;
    FanService() {
        this.state = new OffState();
    }

    public void setState(State state) {
        this.state = state;
    }

    public void pressButton() {
        state.pressButton(this);
    }
}

public class state_design_pattern {
    public static void main(String []args) {
        FanService fan = new FanService();
        fan.pressButton(); //Transition to low state
        fan.pressButton(); //Transition to medium state
        fan.pressButton(); //Transition to high state
        fan.pressButton(); //Transition to off state
    } 
}
