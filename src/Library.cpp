#include "Library.h"
#include <iostream>
#include <limits>
#include <sstream>
#include <iomanip>
#include <fstream>

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

void Library::registerMember()
{
    string memberID;
    string rollNumber;
    string name;
    string department;
    string phoneNumber;
    string email;

    cout << "\n========== Register Member ==========\n";

    cout << "Enter Member ID: ";
    getline(cin, memberID);

    int index = searchMemberByID(memberID);

    if (index != -1)
    {
        cout << "\nMember ID already exists." << endl;
        return;
    }

    cout << "Enter Roll Number: ";
    getline(cin, rollNumber);

    index = searchMemberByRollNumber(rollNumber);

    if (index != -1)
    {
        cout << "\nRoll Number already exists." << endl;
        return;
    }

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Department: ";
    getline(cin, department);

    cout << "Enter Phone Number: ";
    getline(cin, phoneNumber);

    cout << "Enter Email: ";
    getline(cin, email);

    Member newMember(memberID,
                     rollNumber,
                     name,
                     department,
                     phoneNumber,
                     email);

    members.push_back(newMember);

    cout << "\nMember registered successfully." << endl;
}
void Library::updateMember()
{
    string memberID;
    string name;
    string department;
    string phoneNumber;
    string email;

    cout << "\n========== Update Member ==========\n";

    cout << "Enter Member ID: ";
    getline(cin, memberID);

    int index = searchMemberByID(memberID);

    if (index == -1)
    {
        cout << "\nMember not found." << endl;
        return;
    }

    cout << "\nCurrent Member Information:\n";
    members[index].displayMember();

    cout << "\nEnter New Name: ";
    getline(cin, name);

    cout << "Enter New Department: ";
    getline(cin, department);

    cout << "Enter New Phone Number: ";
    getline(cin, phoneNumber);

    cout << "Enter New Email: ";
    getline(cin, email);

    members[index].updateMember(name,
                                department,
                                phoneNumber,
                                email);

    cout << "\nMember information updated successfully." << endl;
}

void Library::removeMember()
{
    string memberID;
    char choice;

    cout << "\n========== Remove Member ==========\n";

    cout << "Enter Member ID: ";
    getline(cin, memberID);

    int index = searchMemberByID(memberID);

    if (index == -1)
    {
        cout << "\nMember not found." << endl;
        return;
    }

    cout << "\nMember Information:\n";
    members[index].displayMember();

    if (members[index].getBorrowedBookCount() > 0)
    {
        cout << "\nCannot remove member." << endl;
        cout << "Member has borrowed books." << endl;
        return;
    }

    if (members[index].getTotalFine() > 0)
    {
        cout << "\nCannot remove member." << endl;
        cout << "Outstanding fine exists." << endl;
        return;
    }

    cout << "\nAre you sure you want to remove this member? (Y/N): ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y')
    {
        members.erase(members.begin() + index);
        cout << "\nMember removed successfully." << endl;
    }
    else
    {
        cout << "\nOperation cancelled." << endl;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Library::searchMember()
{
    int choice;

    cout << "\n========== Search Member ==========\n";
    cout << "1. Search by Member ID" << endl;
    cout << "2. Search by Roll Number" << endl;
    cout << "3. Search by Name" << endl;
    cout << "4. Back" << endl;

    cout << "\nEnter Choice: ";
    cin >> choice;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (choice)
    {
    case 1:
    {
        string memberID;

        cout << "\nEnter Member ID: ";
        getline(cin, memberID);

        int index = searchMemberByID(memberID);

        if (index == -1)
        {
            cout << "\nMember not found." << endl;
        }
        else
        {
            members[index].displayMember();
        }

        break;
    }

    case 2:
    {
        string rollNumber;

        cout << "\nEnter Roll Number: ";
        getline(cin, rollNumber);

        int index = searchMemberByRollNumber(rollNumber);

        if (index == -1)
        {
            cout << "\nMember not found." << endl;
        }
        else
        {
            members[index].displayMember();
        }

        break;
    }

    case 3:
    {
        string name;

        cout << "\nEnter Name: ";
        getline(cin, name);

        vector<int> matchingMembers = searchMemberByName(name);

        if (matchingMembers.empty())
        {
            cout << "\nNo members found." << endl;
        }
        else
        {
            cout << "\nFound " << matchingMembers.size()
                 << " matching member(s).\n" << endl;

            for (int i = 0; i < matchingMembers.size(); i++)
            {
                members[matchingMembers[i]].displayMember();
            }
        }

        break;
    }

    case 4:
        return;

    default:
        cout << "\nInvalid choice." << endl;
    }
}
void Library::viewAllMembers()
{
    cout << "\n========== All Members ==========\n";

    if (members.empty())
    {
        cout << "\nNo members available." << endl;
        return;
    }

    for (int i = 0; i < members.size(); i++)
    {
        members[i].displayMember();
    }
}

void Library::issueBook()
{
    string rollNumber;

    cout << "\n========== Issue Book ==========\n";

    cout << "Enter Roll Number: ";
    getline(cin, rollNumber);

    int memberIndex = searchMemberByRollNumber(rollNumber);

    if (memberIndex == -1)
    {
        cout << "\nMember not found." << endl;
        return;
    }

    cout << "\nMember Information:\n";
    members[memberIndex].displayMember();

    if (!members[memberIndex].getStatus())
    {
        cout << "\nMember is inactive." << endl;
        return;
    }

    if (members[memberIndex].getBorrowedBookCount() >= maxBooksPerMember)
    {
        cout << "\nBorrow limit reached." << endl;
        return;
    }

    if (members[memberIndex].getTotalFine() >= maximumBorrowingFineLimit)
    {
        cout << "\nTotal fine exceeds borrowing limit." << endl;
        return;
    }

    string bookID;

    cout << "\nEnter Book ID: ";
    getline(cin, bookID);

    int bookIndex = searchBookByID(bookID);

    if (bookIndex == -1)
    {
        cout << "\nBook not found." << endl;
        return;
    }

    cout << "\nBook Information:\n";
    books[bookIndex].displayBook();

    if (!books[bookIndex].isAvailable())
    {
        cout << "\nNo copies available." << endl;
        return;
    }

    string issueDate;
    string dueDate;

    stringstream ss;

    ss << "T"
        << setw(3)
        << setfill('0')
        << transactions.size() + 1;

    string transactionID = ss.str();
    cout << "\nTransaction ID : " << transactionID << endl;

    cout << "\nEnter Issue Date: ";
    getline(cin, issueDate);

    cout << "Enter Due Date: ";
    getline(cin, dueDate);
    Transaction newTransaction(transactionID,
                           members[memberIndex].getMemberID(),
                           bookID,
                           issueDate,
                           dueDate);

    books[bookIndex].issueBook();

    members[memberIndex].borrowBook();

    transactions.push_back(newTransaction);

    cout << "\nBook issued successfully." << endl;
}
int Library::searchActiveTransaction(string memberID,
                                     string bookID)
{
    for (int i = 0; i < transactions.size(); i++)
    {
        if (transactions[i].getMemberID() == memberID &&
            transactions[i].getBookID() == bookID &&
            transactions[i].getStatus() == "Issued")
        {
            return i;
        }
    }

    return -1;
}
void Library::returnBook()
{
    string rollNumber;

    cout << "\n========== Return Book ==========\n";

    cout << "Enter Roll Number: ";
    getline(cin, rollNumber);

    int memberIndex = searchMemberByRollNumber(rollNumber);

    if (memberIndex == -1)
    {
        cout << "\nMember not found." << endl;
        return;
    }

    cout << "\nMember Information:\n";
    members[memberIndex].displayMember();
        string bookID;

    cout << "\nEnter Book ID: ";
    getline(cin, bookID);

    int bookIndex = searchBookByID(bookID);

    if (bookIndex == -1)
    {
        cout << "\nBook not found." << endl;
        return;
    }

    cout << "\nBook Information:\n";
    books[bookIndex].displayBook();
        int transactionIndex = searchActiveTransaction(
                                members[memberIndex].getMemberID(),
                                bookID);

    if (transactionIndex == -1)
    {
        cout << "\nNo active transaction found." << endl;
        return;
    }

    cout << "\nTransaction Information:\n";
    transactions[transactionIndex].displayTransaction();

    string returnDate;
    int daysLate;
    int fine;

    cout << "\nEnter Return Date: ";
    getline(cin, returnDate);

    cout << "Enter Days Late: ";
    cin >> daysLate;

    fine = daysLate * finePerDay;

    transactions[transactionIndex].markReturned(returnDate,
                                                daysLate,
                                                fine);

    books[bookIndex].returnBook();

    members[memberIndex].returnBook();

    if (fine > 0)
    {
        members[memberIndex].addFine(fine);
    }

    cout << "\nBook returned successfully." << endl;

    if (fine > 0)
    {
        cout << "Fine Generated : Rs. " << fine << endl;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

}

void Library::payFine()
{
    string rollNumber;
    int amount;

    cout << "\n========== Pay Fine ==========\n";

    cout << "Enter Roll Number: ";
    getline(cin, rollNumber);

    int memberIndex = searchMemberByRollNumber(rollNumber);

    if (memberIndex == -1)
    {
        cout << "\nMember not found." << endl;
        return;
    }

    cout << "\nMember Information:\n";
    members[memberIndex].displayMember();

    if (!members[memberIndex].hasFine())
    {
        cout << "\nNo current fine." << endl;
        return;
    }

    cout << "\nEnter Amount Paid: ";
    cin >> amount;

    if (amount > members[memberIndex].getTotalFine())
    {
        cout << "\nInvalid payment amount." << endl;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    members[memberIndex].payFine(amount);

    cout << "\nFine paid successfully." << endl;

    cout << "\nUpdated Member Information:\n";
    members[memberIndex].displayMember();

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void Library::viewTransactionHistory()
{
    int choice;

    cout << "\n========== Transaction History ==========\n";
    cout << "1. View All Transactions" << endl;
    cout << "2. Search by Member" << endl;
    cout << "3. Search by Book" << endl;
    cout << "4. Back" << endl;

    cout << "\nEnter Choice: ";
    cin >> choice;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (choice)
    {
    case 1:
    {
        if (transactions.empty())
        {
            cout << "\nNo transactions available." << endl;
            break;
        }

        for (int i = 0; i < transactions.size(); i++)
        {
            transactions[i].displayTransaction();
        }

        break;
    }

    case 2:
    {
        string rollNumber;

        cout << "\nEnter Roll Number: ";
        getline(cin, rollNumber);

        int memberIndex = searchMemberByRollNumber(rollNumber);

        if (memberIndex == -1)
        {
            cout << "\nMember not found." << endl;
            break;
        }

        vector<int> memberTransactions =
            searchTransactionByMemberID(
                members[memberIndex].getMemberID());

        if (memberTransactions.empty())
        {
            cout << "\nNo transactions found." << endl;
            break;
        }

        cout << "\nFound "
             << memberTransactions.size()
             << " transaction(s).\n" << endl;

        for (int i = 0; i < memberTransactions.size(); i++)
        {
            transactions[memberTransactions[i]].displayTransaction();
        }

        break;
    }

    case 3:
    {
        string bookID;

        cout << "\nEnter Book ID: ";
        getline(cin, bookID);

        int bookIndex = searchBookByID(bookID);

        if (bookIndex == -1)
        {
            cout << "\nBook not found." << endl;
            break;
        }

        vector<int> bookTransactions =
            searchTransactionByBookID(bookID);

        if (bookTransactions.empty())
        {
            cout << "\nNo transactions found." << endl;
            break;
        }

        cout << "\nFound "
             << bookTransactions.size()
             << " transaction(s).\n" << endl;

        for (int i = 0; i < bookTransactions.size(); i++)
        {
            transactions[bookTransactions[i]].displayTransaction();
        }

        break;
    }

    case 4:
        return;

    default:
        cout << "\nInvalid choice." << endl;
    }
}

void Library::saveData()
{
    // Save Books
    ofstream bookFile("data/books.txt");

    for (int i = 0; i < books.size(); i++)
    {
        bookFile << books[i].getBookID() << "|"
                 << books[i].getTitle() << "|"
                 << books[i].getAuthor() << "|"
                 << books[i].getCategory() << "|"
                 << books[i].getPublisher() << "|"
                 << books[i].getISBN() << "|"
                 << books[i].getPublicationYear() << "|"
                 << books[i].getTotalCopies() << "|"
                 << books[i].getAvailableCopies()
                 << endl;
    }

    bookFile.close();

    // Save Members
    ofstream memberFile("data/members.txt");

    for (int i = 0; i < members.size(); i++)
    {
        memberFile << members[i].getMemberID() << "|"
                   << members[i].getRollNumber() << "|"
                   << members[i].getName() << "|"
                   << members[i].getDepartment() << "|"
                   << members[i].getPhoneNumber() << "|"
                   << members[i].getEmail() << "|"
                   << members[i].getBorrowedBookCount() << "|"
                   << members[i].getTotalFine() << "|"
                   << members[i].getStatus()
                   << endl;
    }

    memberFile.close();

    // Save Transactions
    ofstream transactionFile("data/transactions.txt");

    for (int i = 0; i < transactions.size(); i++)
    {
        transactionFile << transactions[i].getTransactionID() << "|"
                        << transactions[i].getMemberID() << "|"
                        << transactions[i].getBookID() << "|"
                        << transactions[i].getIssueDate() << "|"
                        << transactions[i].getDueDate() << "|"
                        << transactions[i].getReturnDate() << "|"
                        << transactions[i].getDaysLate() << "|"
                        << transactions[i].getFineGenerated() << "|"
                        << transactions[i].getStatus()
                        << endl;
    }

    transactionFile.close();

    cout << "\nData saved successfully." << endl;
}
vector<string> split(string line, char delimiter)
{
    vector<string> tokens;

    string token;

    stringstream ss(line);

    while (getline(ss, token, delimiter))
    {
        tokens.push_back(token);
    }

    return tokens;
}
void Library::loadData()
{
    books.clear();
    members.clear();
    transactions.clear();

    ifstream bookFile("data/books.txt");

    string line;

    while (getline(bookFile, line))
    {
        vector<string> data = split(line, '|');
        Book book(
            data[0],
            data[1],
            data[2],
            data[3],
            data[4],
            data[5],
            stoi(data[6]),
            stoi(data[7]),
            stoi(data[8])
        );

        books.push_back(book);
    }

    bookFile.close();

    ifstream memberFile("data/members.txt");

    while (getline(memberFile, line))
    {
        vector<string> data = split(line, '|');

        Member member(
            data[0],
            data[1],
            data[2],
            data[3],
            data[4],
            data[5],
            stoi(data[6]),
            stoi(data[7]),
            stoi(data[8])
        );

        members.push_back(member);
    }

    memberFile.close();

    ifstream transactionFile("data/transactions.txt");

    while (getline(transactionFile, line))
    {
        vector<string> data = split(line, '|');

        Transaction transaction(
            data[0],
            data[1],
            data[2],
            data[3],
            data[4],
            data[5],
            stoi(data[6]),
            stoi(data[7]),
            data[8]
        );

        transactions.push_back(transaction);
    }

    transactionFile.close();

    cout << "\nData loaded successfully." << endl;
}

void Library::generateReports()
{
    int choice;

    cout << "\n========== Reports ==========\n";
    cout << "1. Total Books" << endl;
    cout << "2. Total Members" << endl;
    cout << "3. Currently Issued Books" << endl;
    cout << "4. Members With Current Fine" << endl;
    cout << "5. Total Transactions" << endl;
    cout << "6. Back" << endl;

    cout << "\nEnter Choice: ";
    cin >> choice;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch(choice)
    {
    case 1:
    {
        cout << "\nTotal Books : "
             << books.size()
             << endl;
        break;
    }

    case 2:
    {
        cout << "\nTotal Members : "
             << members.size()
             << endl;
        break;
    }

    case 3:
    {
        int issuedBooks = 0;

        for(int i = 0; i < books.size(); i++)
        {
            issuedBooks += books[i].getTotalCopies()
                         - books[i].getAvailableCopies();
        }

        cout << "\nCurrently Issued Books : "
             << issuedBooks
             << endl;

        break;
    }

    case 4:
    {
        int count = 0;

        for(int i = 0; i < members.size(); i++)
        {
            if(members[i].getTotalFine() > 0)
            {
                count++;
            }
        }

        cout << "\nMembers With Current Fine : "
             << count
             << endl;

        break;
    }

    case 5:
    {
        cout << "\nTotal Transactions : "
             << transactions.size()
             << endl;

        break;
    }

    case 6:
        return;

    default:
        cout << "\nInvalid choice." << endl;
    }
}