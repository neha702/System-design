package Design_qsns.Design_qsns_java.Design_library_mgmt_service.strategy;

public class FineStrategyByHour {
        public long computeFine(long amount , long duration) {
            long fine = amount * (duration*24);
            System.out.println("Paying fine by hour: " + fine);
            return fine;
        }
}
