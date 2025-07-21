//"Command pattern lets you wrap a request (or action) as an object, so you can store it, pass it around, delay it, or undo it later."
package Design_qsns.Design_patterns_java.Behavioral_design_pattern;
import java.util.*;

class AirConditioner { // receiver
    public void turnOn() {
        System.out.println("Turn on the AC");
    }

    public void turnOff() {
        System.out.println("Turn off the AC");
    }
}

interface ICommand { // command interface
    void execute();
    void undo();
}

class TurnOnCommand implements ICommand { // concrete commands
    AirConditioner ac;
    TurnOnCommand(AirConditioner ac) {
        this.ac = ac;
    }
    public void execute() {
        ac.turnOn();
    }

    public void undo() {
      ac.turnOff();  
    }
}

class TurnOffCommand implements ICommand {
    AirConditioner ac;
    TurnOffCommand(AirConditioner ac) {
        this.ac = ac;
    }
    public void execute() {
        ac.turnOff();
    }

    public void undo() {
      ac.turnOn();  
    }
}

class Remote { // invoker
    Stack<ICommand> commandHistory;
    ICommand command;
    Remote() {
        this.commandHistory = new Stack<>();
    }

    public void setCommand(ICommand command) {
        this.command = command;
        commandHistory.push(command);
    }

    public void pressButton() {
        command.execute();
    } 
    
    public void undo() {
        if(!commandHistory.isEmpty()) {
            ICommand topCommand = commandHistory.peek();
            topCommand.undo();
            commandHistory.pop();
        } else {
            System.out.println("No commands to undo");
        }
    }
}

public class command_design_pattern {
    public static void main(String[] args) {
       AirConditioner ac = new AirConditioner(); // receiver is created
       Remote remote = new Remote(); //remote that is invoker is created
       ICommand command_on = new TurnOnCommand(ac); // command created for turn on that takes ac on which to pass the command
       ICommand command_off = new TurnOffCommand(ac);
       remote.setCommand(command_on); // now button decided for remote , and once button decided command is set
       remote.pressButton();    //once button pressed , set command is executed
       remote.setCommand(command_off);
       remote.pressButton();
       remote.undo();   // this helps to undo just the last command
       remote.undo();
    }
}
