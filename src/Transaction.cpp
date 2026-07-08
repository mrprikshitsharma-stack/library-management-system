#include "Transaction.h"
#include <iostream>

using namespace std;
Transaction::Transaction()
{
    transactionID = "";
    memberID = "";
    bookID = "";

    issueDate = "";
    dueDate = "";
    returnDate = "";

    daysLate = 0;
    fineGenerated = 0;

    status = "";
}
Transaction::Transaction(string transactionID,
                         string memberID,
                         string bookID,
                         string issueDate,
                         string dueDate)
{
    this->transactionID = transactionID;
    this->memberID = memberID;
    this->bookID = bookID;

    this->issueDate = issueDate;
    this->dueDate = dueDate;

    this->returnDate = "";

    this->daysLate = 0;
    this->fineGenerated = 0;

    this->status = "Issued";
}
void Transaction::displayTransaction()
{
    cout << "----------------------------------------" << endl;
    cout << "Transaction ID      : " << transactionID << endl;
    cout << "Member ID           : " << memberID << endl;
    cout << "Book ID             : " << bookID << endl;
    cout << "Issue Date          : " << issueDate << endl;
    cout << "Due Date            : " << dueDate << endl;
    cout << "Return Date         : " << returnDate << endl;
    cout << "Days Late           : " << daysLate << endl;
    cout << "Fine Generated      : Rs. " << fineGenerated << endl;
    cout << "Status              : " << status << endl;
    cout << "----------------------------------------" << endl;
}
void Transaction::markReturned(string returnDate,
                               int daysLate,
                               int fineGenerated)
{
    this->returnDate = returnDate;
    this->daysLate = daysLate;
    this->fineGenerated = fineGenerated;

    this->status = "Returned";
}