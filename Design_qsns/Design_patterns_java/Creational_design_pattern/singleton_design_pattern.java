//singleton design pattern => creates one instance of class and global  access point to that instance
package Design_qsns.Design_patterns_java.Creational_design_pattern;

class Logger {
    private static Logger loggerInstance;
    private Logger () {
        System.out.println("Logger is created!"); // this private constructor that would be called through static method
    }

    public static Logger getInstance() {
        if(loggerInstance == null) { // checks if logger instance is null then only we create a new instance
            synchronized(Logger.class) { // synchronized makes sure only one thread can go inside at a time there
                if(loggerInstance == null) { // This check is needed suppose T1 is inside the synchronized block and T2 waiting out , when T1 is done T2 will still think instance is null and will create another logger instace so we have this check
                    loggerInstance = new Logger();
                }
            }
        }
        return loggerInstance;
    }

    void log(String message) {
        System.out.println("Log: " + message);
    }
}

public class singleton_design_pattern {
    public static void main(String []args) {
        Logger logger = Logger.getInstance(); // Static methods accessed as className.method
        logger.log("Logger is working fine!");
    }
}
