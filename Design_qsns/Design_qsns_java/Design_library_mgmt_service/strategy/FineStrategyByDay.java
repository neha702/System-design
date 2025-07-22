package Design_qsns.Design_qsns_java.Design_library_mgmt_service.strategy;

public class FineStrategyByDay implements IFineStrategy {
    public long computeFine(long amount , long duration) {
        long fine = amount * (duration);
        System.out.println("Paying fine by day: " + fine);
        return fine;
    }
}
