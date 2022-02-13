#ifndef MEMBER_H
#define MEMBER_H
#include <string>

using namespace std;

class Member
{
    private:
    //date of birth
    //first name
    //last name
    //date of marriage? (if applicable)
    string DOB;
    string firstName;
    string lastName;
    //"dd/mm/yyyy"
    string marriageDate;
    public:
    Member();
    Member(string, string, string, string);//married
    Member(string, string, string);//not married
    string getDOB();
    string getFirstname();
    string getLastName();
    string getMarriageDate();
};


#endif