#ifndef MEMBER_H
#define MEMBER_H

#include <string>

using namespace std;

class Member
{
private:
    string memberID;
    string rollNumber;
    string name;
    string department;
    string phoneNumber;
    string email;

    int borrowedBookCount;
    int totalFine;

    bool status;

public:
    Member();

    Member(string memberID,
           string rollNumber,
           string name,
           string department,
           string phoneNumber,
           string email);

    Member(string memberID,
       string rollNumber,
       string name,
       string department,
       string phoneNumber,
       string email,
       int borrowedBookCount,
       int totalFine,
       bool status);

    string getMemberID()
    {
        return memberID;
    }

    string getRollNumber()
    {
        return rollNumber;
    }

    string getName()
    {
        return name;
    }
    string getDepartment()
    {
        return department;
    }

    string getPhoneNumber()
    {
        return phoneNumber;
    }

    string getEmail()
    {
        return email;
    }

    int getBorrowedBookCount()
    {
        return borrowedBookCount;
    }

    int getTotalFine()
    {
        return totalFine;
    }

    bool getStatus()
    {
        return status;
    }
    void displayMember();

    void updateMember(string name,
                      string department,
                      string phoneNumber,
                      string email);

    void borrowBook();
    void returnBook();
    void addFine(int amount);
    void payFine(int amount);
    bool hasFine();
};

#endif