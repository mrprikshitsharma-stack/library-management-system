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

    Book(string bookID,
     string title,
     string author,
     string category,
     string publisher,
     string isbn,
     int publicationYear,
     int totalCopies,
     int availableCopies);
    
    string getBookID()
    {
        return bookID;
    }

    string getTitle()
    {
        return title;
    }

    int getAvailableCopies()
    {
        return availableCopies;
    }

    int getTotalCopies()
    {
        return totalCopies;
    }
    string getAuthor()
    {
        return author;
    }

    string getCategory()
    {
        return category;
    }

    string getPublisher()
    {
        return publisher;
    }

    string getISBN()
    {
        return isbn;
    }

    int getPublicationYear()
    {
        return publicationYear;
    }
    void displayBook();

    void updateBook(string title,
                string author,
                string category,
                string publisher,
                int publicationYear);
    void addCopies(int newCopies);
    void issueBook();
    void returnBook();
    bool isAvailable();
    


};

#endif