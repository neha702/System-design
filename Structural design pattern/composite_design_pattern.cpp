#include "../bitsStd.h"
using namespace std;

class FileSystem { //component interface
public:
virtual void ls() = 0;
};

class File : public FileSystem { //concrete leaf class
string name;
public:
File(string name) {
    this->name = name;
}

void ls() {
    cout << "Listing file " << name << endl;
}

};

class Directory : public FileSystem { //concrete composite class
string name;
vector<FileSystem*> children;
public:
Directory(string dirName) {
    this->name = dirName;
}

void add(FileSystem* child) {
    children.push_back(child);
}

void ls() {
    cout << "Listing directory " << this->name << endl;
    for(auto it : children) {
        it->ls();
    }
}
};


int main() {
    File* file1 = new File("file1.txt");
    File* file2 = new File("file1.txt");
    Directory* dir1 = new Directory("dir1");
    dir1->add(file1);
    dir1->add(file2);
    dir1->ls();
    Directory* dir2 = new Directory("dir2");
    dir2->add(dir1);
    dir2->add(new File("file3.txt"));
    dir2->ls();
}