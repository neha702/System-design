#ifndef FILE_H
#define FILE_H
#include <iostream>
#include "fileSystemNode.h"
using namespace std;

class File : public FileSystemNode{
    string extension;
    string content;
public:
    File(string name) : FileSystemNode(name , 100){
        this->extension = extractExtension(name);
    } 
    string getFileContent() {
        return content;
    }

    void setFileContent(string content) {
        this->content = content;
    }

    string extractExtension(string filePath) {
        int lastInd = filePath.rfind('.');
        return filePath.substr(lastInd + 1);
    }

    bool isFile() {
        return true;
    }

    void display(int depth) {
        cout << "File: " << getName() << endl;
    }

};

#endif // FILE_H