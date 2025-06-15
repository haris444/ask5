#ifndef STUDENT_H
#define STUDENT_H

#include <list>
#include "Person.h"
#include <string>

class Student: public Person
{
private:
    int AM;
    int semester;
    std::list<std::string> subjects;
    std::list<float> grades;
public:
    void setAM(int);
    int getAM() const;
    void setsemester(int);
    int getsemester() const;
    void setsubjects(std::list<std::string>);
    std::list<std::string> getsubjects() const;
    void setgrades(std::list<float>);
    std::list<float> getgrades() const;
    Student(char*,std::string,int,std::string,std::string,std::string,int,int);
};

#endif