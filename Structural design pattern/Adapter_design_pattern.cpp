#include "../bitsStd.h"
using namespace std;

class XMLData{
string xmlData;
public:
    XMLData(string data) {
        xmlData = data;
    }

    string getXMLData() {
        return xmlData;
    }
};

class Tool{
string data;
public:
    Tool(){};
    Tool(string jsonData) {
        data = jsonData; 
    }
    virtual void analyseData() {  //the way I can override
        cout << "Analytics tool is analyzing data" << data << endl;
    }
};

class Client{
public:
    void processData(Tool* tool) {
        tool->analyseData();
    }
};

class Adapter: public Tool{
XMLData* xmlData;
public:
    Adapter(XMLData* xmldata) {
        xmlData = xmldata;
    }

    void analyseData() { //override
        cout << "Converting XML Data to Json Data" << endl;
        Tool::analyseData(); //Call parent's function
    }

};

int main() {
string inputData;
cin >> inputData;
XMLData* xMLData = new XMLData(inputData);
Tool* tool = new Adapter(xMLData);
Client* c = new Client();
c->processData(tool);
//Our tool expects json data, but we have xml data , but we can't just change the tool as client would be expecting tool type (we want to support all types of data through one tool) so instead
//we create another derived class of tool that would take xml data and convert to json data that the client would be able to use, so e just create object of derived class of tool.
}