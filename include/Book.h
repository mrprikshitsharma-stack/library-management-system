#ifndef BOOK_H
#define BOOK_H
#include <string>

using namespace std;

class Book
{
private:
    string bookID;
    string title;
    string author;
    string category;
    string publisher;
    string isbn;

    int publicationYear;
    int totalCopies;
    int availableCopies;

public:
    Book();

    Book(string bookID,string title,string author,string category,string publisher,
         string isbn,int publicationYear,int totalCopies);
    
    void displayBook();

    void updateBook(string title,
                string author,
                string category,
                string publisher,
                string isbn,
                int publicationYear,
                int totalCopies);

    bool isAvailable();
    


};

#endif