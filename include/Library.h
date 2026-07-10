#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>

#include "Book.h"
#include "Member.h"
#include "Transaction.h"

using namespace std;

class Library
{
private:
    vector<Book> books;
    vector<Member> members;
    vector<Transaction> transactions;

    int maxBooksPerMember;
    int loanDuration;
    int finePerDay;
    int maximumBorrowingFineLimit;

public:
    Library();

    // Book Management
    void addBook();
    void addBookCopies();
    void removeBook();
    void updateBook();
    void searchBook();
    void viewAllBooks();

    // Member Management
    void registerMember();
    void deactivateMember();
    void updateMember();
    void viewAllMembers();

    // Transaction Management
    void issueBook();
    void returnBook();
    void payFine();
    void viewTransactionHistory();

    // Reports
    void generateReports();

    // Search Functions
    int searchBookByID(string bookID);
    vector<int> searchBookByTitle(string title);

    int searchMemberByID(string memberID);
    int searchMemberByRollNumber(string rollNumber);
    vector<int> searchMemberByName(string name);

    int searchTransactionByID(string transactionID);
    vector<int> searchTransactionByMemberID(string memberID);
    vector<int> searchTransactionByBookID(string bookID);

    // File Handling
    void loadData();
    void saveData();
};

#endif