#include "Library.h"
#include <iostream>
#include <limits>

using namespace std;

Library::Library()
{
    maxBooksPerMember = 5;
    loanDuration = 15;
    finePerDay = 10;
    maximumBorrowingFineLimit = 100;
}
int Library::searchBookByID(string bookID)
{
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].getBookID() == bookID)
        {
            return i;
        }
    }

    return -1;
}
vector<int> Library::searchBookByTitle(string title)
{
    vector<int> matchingBooks;

    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].getTitle() == title)
        {
            matchingBooks.push_back(i);
        }
    }

    return matchingBooks;
}
int Library::searchMemberByID(string memberID)
{
    for(int i = 0; i < members.size(); i++)
    {
        if(members[i].getMemberID() == memberID)
        {
            return i;
        }
    }
    return -1;
}
int Library::searchMemberByRollNumber(string rollNumber)
{
    for(int i = 0; i < members.size(); i++)
    {
        if(members[i].getRollNumber() == rollNumber)
        {
            return i;
        }
    }
    return -1;
}
vector<int> Library::searchMemberByName(string name)
{
    vector<int> matchingNames;

    for (int i = 0; i < members.size(); i++)
    {
        if (members[i].getName() == name)
        {
            matchingNames.push_back(i);
        }
    }

    return matchingNames;
}
int Library::searchTransactionByID(string transactionID)
{
    for(int i = 0; i < transactions.size(); i++)
    {
        if(transactions[i].getTransactionID() == transactionID)
        {
            return i;
        }
    }
    return -1;
}
vector<int> Library::searchTransactionByMemberID(string memberID)
{
    vector<int> matchingMemberTransactions;

    for (int i = 0; i < transactions.size(); i++)
    {
        if (transactions[i].getMemberID() == memberID)
        {
            matchingMemberTransactions.push_back(i);
        }
    }

    return matchingMemberTransactions;
}
vector<int> Library::searchTransactionByBookID(string bookID)
{
    vector<int> matchingTransactions;

    for (int i = 0; i < transactions.size(); i++)
    {
        if (transactions[i].getBookID() == bookID)
        {
            matchingTransactions.push_back(i);
        }
    }

    return matchingTransactions;
}
void Library::addBook()
{
    string bookID;
    string title;
    string author;
    string category;
    string publisher;
    string isbn;

    int publicationYear;
    int totalCopies;

    cout << "\n========== Add New Book ==========\n";

    cout << "Enter Book ID: ";
    getline(cin, bookID);

    int index = searchBookByID(bookID);

    if (index != -1)
    {
        cout << "\nBook ID already exists." << endl;
        return;
    }

    cout << "Enter Title: ";
    getline(cin, title);

    cout << "Enter Author: ";
    getline(cin, author);

    cout << "Enter Category: ";
    getline(cin, category);

    cout << "Enter Publisher: ";
    getline(cin, publisher);

    cout << "Enter ISBN: ";
    getline(cin, isbn);

    cout << "Enter Publication Year: ";
    cin >> publicationYear;

    cout << "Enter Total Copies: ";
    cin >> totalCopies;

    Book newBook(bookID,
                 title,
                 author,
                 category,
                 publisher,
                 isbn,
                 publicationYear,
                 totalCopies);

    books.push_back(newBook);

    cout << "\nBook added successfully." << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Library::addBookCopies()
{
    string bookID;
    int newCopies;

    cout << "Enter Book ID: ";
    getline(cin, bookID);

    int index = searchBookByID(bookID);

    if (index == -1)
    {
        cout << "\nBook not found." << endl;
        return;
    }

    books[index].displayBook();

    cout << "Enter Number of New Copies: ";
    cin >> newCopies;

    books[index].addCopies(newCopies);

    cout << "\nCopies added successfully." << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void Library::updateBook()
{
    string bookID;
    string title;
    string author;
    string category;
    string publisher;

    int publicationYear;

    cout << "\n========== Update Book ==========\n";

    cout << "Enter Book ID: ";
    getline(cin, bookID);

    int index = searchBookByID(bookID);

    if (index == -1)
    {
        cout << "\nBook not found." << endl;
        return;
    }

    cout << "\nCurrent Book Information:\n";
    books[index].displayBook();

    cout << "\nEnter New Title: ";
    getline(cin, title);

    cout << "Enter New Author: ";
    getline(cin, author);

    cout << "Enter New Category: ";
    getline(cin, category);

    cout << "Enter New Publisher: ";
    getline(cin, publisher);

    cout << "Enter New Publication Year: ";
    cin >> publicationYear;

    books[index].updateBook(title,
                            author,
                            category,
                            publisher,
                            publicationYear);

    cout << "\nBook information updated successfully." << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void Library::removeBook()
{
    string bookID;
    char choice;

    cout << "\n========== Remove Book ==========\n";

    cout << "Enter Book ID: ";
    getline(cin, bookID);

    int index = searchBookByID(bookID);

    if (index == -1)
    {
        cout << "\nBook not found." << endl;
        return;
    }

    cout << "\nBook Information:\n";
    books[index].displayBook();

    if (books[index].getAvailableCopies() != books[index].getTotalCopies())
    {
        cout << "\nCannot remove book." << endl;
        cout << "Some copies are currently issued." << endl;
        return;
    }

    cout << "\nAre you sure you want to remove this book? (Y/N): ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y')
    {
        books.erase(books.begin() + index);
        cout << "\nBook removed successfully." << endl;
    }
    else
    {
        cout << "\nOperation cancelled." << endl;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void Library::searchBook()
{
    int choice;

    cout << "\n========== Search Book ==========\n";
    cout << "1. Search by Book ID" << endl;
    cout << "2. Search by Title" << endl;
    cout << "3. Back" << endl;

    cout << "\nEnter Choice: ";
    cin >> choice;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (choice)
    {
    case 1:
    {
        string bookID;

        cout << "\nEnter Book ID: ";
        getline(cin, bookID);

        int index = searchBookByID(bookID);

        if (index == -1)
        {
            cout << "\nBook not found." << endl;
        }
        else
        {
            books[index].displayBook();
        }

        break;
    }

    case 2:
    {
        string title;

        cout << "\nEnter Book Title: ";
        getline(cin, title);

        vector<int> matchingBooks = searchBookByTitle(title);

        if (matchingBooks.empty())
        {
            cout << "\nNo books found." << endl;
        }
        else
        {
            cout << "\nFound " << matchingBooks.size()
                 << " matching book(s).\n" << endl;

            for (int i = 0; i < matchingBooks.size(); i++)
            {
                books[matchingBooks[i]].displayBook();
            }
        }

        break;
    }

    case 3:
        return;

    default:
        cout << "\nInvalid choice." << endl;
    }
}
void Library::viewAllBooks()
{
    cout << "\n========== All Books ==========\n";

    if (books.empty())
    {
        cout << "\nNo books available." << endl;
        return;
    }

    for (int i = 0; i < books.size(); i++)
    {
        books[i].displayBook();
    }
}