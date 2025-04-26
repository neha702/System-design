#include "../../bitsStd.h"
#include "fileSystemService.h"
using namespace std;

int main() {
    FileSystemService* fileSystemService = FileSystemService::getInstance();
    if(!fileSystemService->createPath("/document/lld")) {
        cout << "Path couldn't be created" << endl;
    }

    if(!fileSystemService->createPath("/document/lld/design_patterns/structural_dp.java")) {
        cout << "Path couldn't be created" << endl;
    }

    if(!fileSystemService->setFileContent("/document/lld/design_patterns/structural_dp.java" , "abcd")) {
         cout << "Couldn't set content" << endl;
    }
    
    if(!fileSystemService->createPath("/document/lld/design_patterns/behavioural_dp.java")) {
        cout << "Path couldn't be created" << endl;
    }

    if(!fileSystemService->setFileContent("/document/lld/design_patterns/behavioural_dp.java" , "defg")) {
         cout << "Couldn't set content" << endl;
    }

    if(!fileSystemService->createPath("/document/lld/design_patterns/creational_dp.java")) {
        cout << "Path couldn't be created" << endl;
    }

    if(!fileSystemService->setFileContent("/document/lld/design_patterns/creational_dp.java" , "hijk")) {
        cout << "Couldn't set content" << endl;
    }
    
    cout << fileSystemService->getFileContent("/document/lld/design_patterns/creational_dp.java") << endl;

    cout << endl;

    fileSystemService->display();

    cout << endl;

    if(!fileSystemService->deletePath("/document/lld/design_patterns/creational_dp.java")) {
        cout << "File couldn't be deleted" << endl;
    }

    cout << endl;

    fileSystemService->display();

    cout << endl;

    if(!fileSystemService->deletePath("/document/lld/design_patterns")) {
        cout << "Folder couldn't be deleted" << endl;
    }

    cout << endl;

    fileSystemService->display();

    cout << endl;

}