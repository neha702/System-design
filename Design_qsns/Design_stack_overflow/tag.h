#ifndef TAG_H
#define TAG_H
#include <string>
#include <iostream>
using namespace std;

class Tag {
string tag;
string description;
public:
Tag(string tag , string desc) {
    this->tag = tag;
    this->description = desc;
    cout << "New tag of " << tag << " added!" << endl;
}

string getTagName() {
    return tag;
}
};

class ScienceFictionTag : public Tag {
public:
ScienceFictionTag(string desc) : Tag("ScienceFiction" , desc){}
};

class SportsTag : public Tag {
public:
SportsTag(string desc) : Tag("Sports" , desc){}
};

class EntertainmentTag : public Tag {
public:
EntertainmentTag(string desc) : Tag("Entertainment" , desc){}
};

#endif // TAG_H