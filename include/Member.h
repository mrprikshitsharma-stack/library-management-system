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

    void displayMember();

    void updateMember(string name,
                      string department,
                      string phoneNumber,
                      string email);

    bool hasFine();
};

#endif