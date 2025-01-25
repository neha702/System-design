#include "../bitsStd.h"
using namespace std;

class Book{
int id;
string name;
string author;
public:
Book(int id , string name , string author) {
    this->id = id;
    this->name = name;
    this->author = author;
}

void display() {
    cout << this->name << " is displayed!" << endl;
}
};

class IIterator { // iterator interface
public:
virtual bool hasNext() = 0;
virtual Book* next() = 0;
};
 
class ICollection { // collection
public:
virtual IIterator* createIterator() = 0;
};

class BookIterator : public IIterator{ // iterator of a type (suppose for tree)
vector<Book*>books;
int ind = 0; // we need to keep track of index
public:
BookIterator(vector<Book*>books) {
    this->books = books;
}

bool hasNext() {
    return ind < books.size();
}

Book* next() {
    if(this->hasNext()) {
        return books[ind++];
    }
}
};


class Library : public ICollection { // collection type like stack
vector<Book*>books;
public:
Library(vector<Book*> books) {
    this->books = books;
}

IIterator* createIterator() {
    return new BookIterator(books);
}
};


int main() {
    Book* book1 = new Book(1 , "Robinhood" , "Arthur");
    Book* book2 = new Book(2, "Guliver" , "Ross");

    vector<Book*> books;
    books.push_back(book1);
    books.push_back(book2);

    Library* library = new Library(books);
    BookIterator* bookIterator = new BookIterator(books);

    while(bookIterator->hasNext()) {
        Book* book = bookIterator->next();
        book->display();
    }
}