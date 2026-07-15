#include <iostream>
#include <limits>

#include "Library.h"

using namespace std;

void bookMenu(Library &library);
void memberMenu(Library &library);
void transactionMenu(Library &library);

void bookMenu(Library &library)
{
    int choice;

    do
    {
        cout << "\n========== Book Management ==========\n";
        cout << "1. Add Book" << endl;
        cout << "2. Add Book Copies" << endl;
        cout << "3. Update Book" << endl;
        cout << "4. Remove Book" << endl;
        cout << "5. Search Book" << endl;
        cout << "6. View All Books" << endl;
        cout << "7. Back" << endl;

        cout << "\nEnter Choice: ";
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
            library.addBook();
            break;

        case 2:
            library.addBookCopies();
            break;

        case 3:
            library.updateBook();
            break;

        case 4:
            library.removeBook();
            break;

        case 5:
            library.searchBook();
            break;

        case 6:
            library.viewAllBooks();
            break;

        case 7:
            return;

        default:
            cout << "\nInvalid Choice." << endl;
        }

    } while (choice != 7);
}

void memberMenu(Library &library)
{
    int choice;

    do
    {
        cout << "\n========== Member Management ==========\n";
        cout << "1. Register Member" << endl;
        cout << "2. Update Member" << endl;
        cout << "3. Remove Member" << endl;
        cout << "4. Search Member" << endl;
        cout << "5. View All Members" << endl;
        cout << "6. Back" << endl;

        cout << "\nEnter Choice: ";
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
            library.registerMember();
            break;

        case 2:
            library.updateMember();
            break;

        case 3:
            library.removeMember();
            break;

        case 4:
            library.searchMember();
            break;

        case 5:
            library.viewAllMembers();
            break;

        case 6:
            return;

        default:
            cout << "\nInvalid Choice." << endl;
        }

    } while (choice != 6);
}

void transactionMenu(Library &library)
{
    int choice;

    do
    {
        cout << "\n========== Transaction Management ==========\n";
        cout << "1. Issue Book" << endl;
        cout << "2. Return Book" << endl;
        cout << "3. Pay Fine" << endl;
        cout << "4. View Transaction History" << endl;
        cout << "5. Back" << endl;

        cout << "\nEnter Choice: ";
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
            library.issueBook();
            break;

        case 2:
            library.returnBook();
            break;

        case 3:
            library.payFine();
            break;

        case 4:
            library.viewTransactionHistory();
            break;

        case 5:
            return;

        default:
            cout << "\nInvalid Choice." << endl;
        }

    } while (choice != 5);
}

int main()
{
    Library library;

    library.loadData();

    int choice;

    do
    {
        cout << "\n==========================================" << endl;
        cout << "      LIBRARY MANAGEMENT SYSTEM" << endl;
        cout << "==========================================" << endl;

        cout << "1. Book Management" << endl;
        cout << "2. Member Management" << endl;
        cout << "3. Transaction Management" << endl;
        cout << "4. Reports" << endl;
        cout << "5. Save Data" << endl;
        cout << "6. Exit" << endl;

        cout << "\nEnter Choice: ";
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch(choice)
        {
        case 1:
            bookMenu(library);
            break;

        case 2:
            memberMenu(library);
            break;

        case 3:
            transactionMenu(library);
            break;

        case 4:
            library.generateReports();
            break;

        case 5:
            library.saveData();
            break;

        case 6:
            library.saveData();
            cout << "\nThank you for using the Library Management System." << endl;
            break;

        default:
            cout << "\nInvalid Choice." << endl;
        }

    } while(choice != 6);

    return 0;
}

