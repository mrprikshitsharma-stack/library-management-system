#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

using namespace std;

class Transaction
{
private:
    string transactionID;
    string memberID;
    string bookID;

    string issueDate;
    string dueDate;
    string returnDate;

    int daysLate;
    int fineGenerated;

    string status;

public:
    Transaction();

    Transaction(string transactionID,
                string memberID,
                string bookID,
                string issueDate,
                string dueDate);

    void displayTransaction();

    void markReturned(string returnDate,
                      int daysLate,
                      int fineGenerated);
};

#endif