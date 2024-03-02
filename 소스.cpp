//2023111359 �ְ���
#include <iostream>
using namespace std;

class Book {
    char* title;      // å ����
    int price;        // å ����
public:
    Book(const char* title, int price);
    Book(const Book& b);
    ~Book();
    void set(const char* title, int price);
    void show() { cout << title << ' ' << price << "��" << endl; }
};

Book::Book(const char* title, int price) {
    this->title = new char[strlen(title) + 1];
    strcpy(this->title, title);
    this->price = price;
}

Book::Book(const Book& b) {
    this->title = new char[strlen(b.title) + 1];
    strcpy(this->title, b.title);
    this->price = b.price;
}
Book::~Book() { delete[] title; };
void Book::set(const char* title, int price) {
    delete[] this->title;
    this->title = new char[strlen(title) + 1];
    strcpy(this->title, title);
    this->price = price;
}

int main() {
    Book cpp("Power C++", 10000);
    Book java(cpp);
    java.set("Power Java", 12000);
    cpp.show();
    java.show();
}