#include "../bitsStd.h"
using namespace std;

class DocumentState {
public:
virtual void showState() = 0;
};

class Draft : public DocumentState {
public:
void showState() {
    cout << "Document is in draft state. Ready to be written." << endl;
}    
};

class Moderation : public DocumentState {
public:
void showState() {
    cout << "Document is in moderation state. Awaiting to be published." << endl;
}    
};

class Published : public DocumentState {
public:
void showState() {
    cout << "Document is in published state. Document is visible to all." << endl;
}    
};

class Document {
DocumentState* docState;
public:
Document() {
    docState = new Draft();

}

void showState() {
    docState->showState();
}

 void setState(DocumentState* state) {
    docState = state;
 }
};


int main() {
Document* document = new Document();
document->showState();

DocumentState* ModerationState = new Moderation();
document->setState(ModerationState);
document->showState();

DocumentState* PublishedState =  new Published();
document->setState(PublishedState);
document->showState();
}