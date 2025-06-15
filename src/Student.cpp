#include "Person.h"
#include "Student.h"
#include <string>
#include <list>

void Student::setAM(int A)
{
    AM=A;
}

int Student::getAM() const
{
    return AM;
}

void Student::setsemester(int sem)
{
    semester=sem;
}

int Student::getsemester() const
{
    return semester;
}

void Student::setsubjects(std::list<std::string> subj)
{
    subjects=subj;
}

std::list<std::string> Student::getsubjects() const
{
    return subjects;
}

void Student::setgrades(std::list<float> grad)
{
    grades=grad;
}

std::list<float> Student::getgrades() const
{
    return grades;
}

Student::Student(char* id,std::string nam,int by,std::string add,std::string phone,std::string em,int A,int sem): Person(std::string(id),nam,by,add,phone,em)
{
    AM=A;
    semester=sem;
}