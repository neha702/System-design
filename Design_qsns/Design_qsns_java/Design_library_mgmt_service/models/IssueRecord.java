package Design_qsns.Design_qsns_java.Design_library_mgmt_service.models;

import java.time.LocalDate;

public class IssueRecord {
    private int id;
    private User u;
    private LocalDate issueDate;
    private LocalDate returnDate;
    

    IssueRecord(int id , User u , LocalDate issueDate , LocalDate  returnDate) {
        this.id = id;
        this.u = u;
        this.issueDate = issueDate;
        this.returnDate = returnDate;
    }

    public LocalDate getDueDate() {
        return returnDate;
    }

    public int getBookId() {
        return id;
    }

    public LocalDate getIssueDate() {
        return issueDate;
    }

    public int getId() {
        return id;
    }
}
