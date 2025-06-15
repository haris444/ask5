#ifndef PERSON_H
#define PERSON_H

#include <string>
class Person
{
private:
     char *idnum;
     std::string name;
     int birthyear;
     std::string address;
     std::string phonenum;
     std::string email;
public:
     char* getidnum() const;
     void setidnum(char*);
     std::string getname() const;
     void setname(std::string);
     int getbirthyear() const;
     void setbirthyear(int);
     std::string getaddress() const;
     void setaddress(std::string);
     std::string getphonenum() const;
     void setphonenum(std::string);
     std::string getemail() const;
     void setemail(std::string);
     int calcage() const;
     virtual ~Person();
     Person(const Person&);
     Person(std::string,std::string,int,std::string,std::string,std::string);
     Person(std::string,std::string,int);
};

#endif