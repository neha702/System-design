package Design_qsns.Design_qsns_java.Design_library_mgmt_service.models;

public class MailObserver implements IObserver{
    public void notify(String message) {
        System.out.println("Mail Notification: " + message);
    }
}
