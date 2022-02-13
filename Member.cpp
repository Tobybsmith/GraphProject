#include "Member.h"


Member::Member()
{
    //do nothing
}

Member::Member(string d, string f, string l, string m)
{
    DOB = d;
    firstName = f;
    lastName = l;
    marriageDate = m;
}

Member::Member(string d, string f, string l)
{
    DOB = d;
    firstName = f;
    lastName = l;
}

string Member::getDOB()
{
    return DOB;
}

string Member::getFirstname()
{
    return firstName;
}

string Member::getLastName()
{
    return lastName;
}

string Member::getMarriageDate()
{
    return marriageDate;
}