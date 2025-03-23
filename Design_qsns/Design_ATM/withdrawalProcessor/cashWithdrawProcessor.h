#ifndef CASHWITHDRAWPROCESSOR_H
#define CASHWITHDRAWPROCESSOR_H
#include "../card.h"

class CashWithDrawProcessor {
protected:
CashWithDrawProcessor* nextProcessor;
public:
CashWithDrawProcessor(CashWithDrawProcessor* nextProcessor) {
    this->nextProcessor = nextProcessor;
}

virtual bool withdrawCash(int amount , Card* card) = 0;
};

#endif // CASHWITHDRAWPROCESSOR_H