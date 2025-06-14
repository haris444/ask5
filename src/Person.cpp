#include "Person.h"
#include <string>
#include <iostream>
#include <cstring>

char* Person::getidnum() const 
{
    return idnum;
}

void Person::setidnum(char *num)
{
    idnum= new char[strlen(num)+1];
    strcpy(idnum, num);
}

std::string Person::getname() const 
{
    return name;
}

void Person::setname(std::string nam)
{
    name=nam;
}

int Person::getbirthyear() const  
{
    return birthyear;
}

void Person::setbirthyear(int by)
{
    birthyear=by;
}

std::string Person::getaddress() const 
{
    return address;
}

void Person::setaddress(std::string addr)
{
    address=addr;
}

std::string Person::getphonenum() const  
{
    return phonenum;
}

void Person::setphonenum(std::string phonum)
{
    phonenum=phonum;
}

std::string Person::getemail() const
{
    return email;
}

void Person::setemail(std::string em)
{
    email=em;
}

int Person::calcage() const 
{
    int age;
    age=2025-birthyear;
    return age;
}

Person::~Person()
{
    delete[] idnum;
}

Person::Person(const Person &x)
{
    idnum=new char[strlen(x.getidnum())+1];
    strcpy(idnum, x.getidnum());
    name=x.getname();
    birthyear=x.getbirthyear();
    address=x.getaddress();
    phonenum=x.getphonenum();
    email=x.getemail();
}

Person::Person(std::string num,std::string nam,int by,std::string addr,std::string phonum,std::string em)
{
    idnum= new char[num.length()+1];
    strcpy(idnum, num.c_str());
    name=nam;
    birthyear=by;
    address=addr;
    phonenum=phonum;
    email=em;
}

Person::Person(std::string num,std::string nam,int by)
{
    idnum= new char[num.length()+1];
    strcpy(idnum, num.c_str());
    name=nam;
	birthyear=by;
    address="άγνωστο";
    phonenum="άγνωστο";
	email="άγνωστο";
}