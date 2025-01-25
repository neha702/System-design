#include "../bitsStd.h"
using namespace std;

class Colleague {
public:
virtual void placeBid(int amount) = 0;
virtual void receiveNotification(int amount) = 0;
virtual string getName() = 0;
};

class AuctionMediator {
public:
virtual void addBidder(Colleague* bidder) = 0;
virtual void placeBid(Colleague* bidder ,int amount) = 0;
};

class Auction : public AuctionMediator {
vector<Colleague*>colleagues;
public:
void addBidder(Colleague* bidder) {
    colleagues.push_back(bidder);
}

void placeBid(Colleague* bidder , int amount){
cout << "Bidder " << bidder->getName() << " has bidded  amount" << amount << endl;
for(Colleague* colleague : colleagues) {
    if(colleague->getName() != bidder->getName()) {
        colleague->receiveNotification(amount);
    }
}
}
};

class Bidder : public Colleague {
AuctionMediator* auctionMediator;
string name;
public:
Bidder(string name , AuctionMediator* auctionMediator) {
    this->name = name;
    this->auctionMediator = auctionMediator;
    auctionMediator->addBidder(this);
}

string getName() {
    return this->name;
}

void placeBid(int amount) {
    auctionMediator->placeBid(this , amount);
}

void receiveNotification(int amount) {
    cout << "Bidder " << name << " has received notification that someone bidded of amount " << amount << endl;
}
};

int main() {
    AuctionMediator* auctionMediator = new Auction();
    Colleague* bidder1 = new Bidder("bidder1" , auctionMediator);
    Colleague* bidder2 = new Bidder("bidder2" , auctionMediator);
    Colleague* bidder3 = new Bidder("bidder3" , auctionMediator);
 
    bidder1->placeBid(10);
    bidder2->placeBid(20);

}