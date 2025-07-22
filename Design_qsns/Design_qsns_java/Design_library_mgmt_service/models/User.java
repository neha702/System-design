package Design_qsns.Design_qsns_java.Design_library_mgmt_service.models;
import java.util.*;

public class User {
    private int id;
    private String name;
    private String email;
    private ArrayList<IssueRecord> issueRecords;
    public User(int id , String name , String email) {
        this.id = id;
        this.name = name;
        this.email = email;
        this.issueRecords = new ArrayList<>();
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public String getEmail() {
        return email;
    }

    public void addIssueRecord(IssueRecord record) {
        issueRecords.add(record);
    }

    public void removeIssueRecord(IssueRecord record) {
        issueRecords.remove(record);
    }

    public ArrayList<IssueRecord> getIssueRecords() {
        return issueRecords;
    }
}
