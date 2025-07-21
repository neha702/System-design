//This design pattern is used to pass a requst to chain of handler, each handler can either process a request or pass to next one in chain
package Design_qsns.Design_patterns_java.Behavioral_design_pattern;

interface ILevelHandler {
    void setNextHandler(ILevelHandler nextHandler);
    void handleRequest(String request);
}

class LevelHandlerOne implements ILevelHandler {
    ILevelHandler nextHandler;
    public void setNextHandler(ILevelHandler nextHandler) {
        this.nextHandler = nextHandler;
    }

    public void handleRequest(String request) {
        if(request.equals("HIGH")) {
            System.out.println("Handling request at level one");
        } else {
            if(nextHandler != null) {
                System.out.println("Passing request to next handler");
                nextHandler.handleRequest(request);
            } else {
                System.out.println("No next handler found to process!");
            }
        }
    }

}

class LevelHandlerTwo implements ILevelHandler {
    ILevelHandler nextHandler;
    public void setNextHandler(ILevelHandler nextHandler) {
        this.nextHandler = nextHandler;
    }

    public void handleRequest(String request) {
        if(request.equals("MEDIUM")) {
            System.out.println("Handling request at level two");
        } else {
            if(nextHandler != null) {
                System.out.println("Passing request to next handler");
                nextHandler.handleRequest(request);
            } else {
                System.out.println("No next handler found to process!");
            }
        }
    }
}

class LevelHandlerThree implements ILevelHandler {
    ILevelHandler nextHandler;
    public void setNextHandler(ILevelHandler nextHandler) {
        this.nextHandler = nextHandler;
    }

    public void handleRequest(String request) {
        if(request.equals("LOW")) {
            System.out.println("Handling request at level three");
        } else {
            if(nextHandler != null) {
                System.out.println("Passing request to next handler");
                nextHandler.handleRequest(request);
            } else {
                System.out.println("No next handler found to process!");
            }
        }
    }
}


public class chain_of_responsibility_design_pattern {
    private static ILevelHandler createChainOfHandler() {
        ILevelHandler levelOneHandler = new LevelHandlerOne();
        ILevelHandler levelTwoHandler = new LevelHandlerTwo();
        ILevelHandler levelThreeHandler = new LevelHandlerThree();
        levelOneHandler.setNextHandler(levelTwoHandler);
        levelTwoHandler.setNextHandler(levelThreeHandler);
        levelThreeHandler.setNextHandler(null);
        return levelOneHandler;
    }

    public static void main(String[] args) {
        ILevelHandler levelHandler = createChainOfHandler();
        levelHandler.handleRequest("LOW");
    }
}
