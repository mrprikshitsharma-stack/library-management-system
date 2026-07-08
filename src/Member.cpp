#include "Member.h"
#include <iostream>

using namespace std;

Member::Member()
{
    memberID = "";
    rollNumber = "";
    name = "";
    department = "";
    phoneNumber = "";
    email = "";

    borrowedBookCount = 0;
    totalFine = 0;
    status = false;
}
Member::Member(string memberID,
               string rollNumber,
               string name,
               string department,
               string phoneNumber,
               string email)
{
    this->memberID = memberID;
    this->rollNumber = rollNumber;
    this->name = name;
    this->department = department;
    this->phoneNumber = phoneNumber;
    this->email = email;

    this->borrowedBookCount = 0;
    this->totalFine = 0;
    this->status = true;
}
bool Member::hasFine()
{
    return totalFine > 0;
}
void Member::displayMember()
{
    cout << "----------------------------------------" << endl;
    cout << "Member ID            : " << memberID << endl;
    cout << "Roll Number          : " << rollNumber << endl;
    cout << "Name                 : " << name << endl;
    cout << "Department           : " << department << endl;
    cout << "Phone Number         : " << phoneNumber << endl;
    cout << "Email                : " << email << endl;
    cout << "Borrowed Books       : " << borrowedBookCount << endl;
    cout << "Total Fine           : Rs. " << totalFine << endl;
    cout << "Status               : ";

    if (status)
    {
        cout << "Active";
    }
    else
    {
        cout << "Inactive";
    }

    cout << endl;
    cout << "----------------------------------------" << endl;
}
void Member::updateMember(string name,
                          string department,
                          string phoneNumber,
                          string email)
{
    this->name = name;
    this->department = department;
    this->phoneNumber = phoneNumber;
    this->email = email;
}