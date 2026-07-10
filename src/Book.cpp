#include "Book.h"
#include <iostream>

using namespace std;

Book::Book()
{
    bookID = "";
    title = "";
    author = "";
    category = "";
    publisher = "";
    isbn = "";

    publicationYear = 0;
    totalCopies = 0;
    availableCopies = 0;
}
Book::Book(string bookID,string title,string author,string category,
           string publisher,string isbn,int publicationYear,int totalCopies)
{
    this->bookID = bookID;
    this->title = title;
    this->author = author;
    this->category = category;
    this->publisher = publisher;
    this->isbn = isbn;

    this->publicationYear = publicationYear;
    this->totalCopies = totalCopies;

    this->availableCopies = totalCopies;
}
bool Book::isAvailable()
{
    return availableCopies > 0;
}
void Book::addCopies(int newCopies)
{
    totalCopies += newCopies;
    availableCopies += newCopies;
}
void Book::displayBook()
{
    cout << "----------------------------------------" << endl;
    cout << "Book ID           : " << bookID << endl;
    cout << "Title             : " << title << endl;
    cout << "Author            : " << author << endl;
    cout << "Category          : " << category << endl;
    cout << "Publisher         : " << publisher << endl;
    cout << "ISBN              : " << isbn << endl;
    cout << "Publication Year  : " << publicationYear << endl;
    cout << "Total Copies      : " << totalCopies << endl;
    cout << "Available Copies  : " << availableCopies << endl;
    cout << "----------------------------------------" << endl;
}
void Book::updateBook(string title,
                      string author,
                      string category,
                      string publisher,
                      int publicationYear)
{
    this->title = title;
    this->author = author;
    this->category = category;
    this->publisher = publisher;
    this->publicationYear = publicationYear;
}
void Book::issueBook()
{
    availableCopies--;
}

void Book::returnBook()
{
    availableCopies++;
}