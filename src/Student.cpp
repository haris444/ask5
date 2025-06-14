#include "Person.h"
#include "Student.h"
#include <string>
#include <list>


    void setAM(int A)
    {
        AM=A;
    }
    int getAM() const
    {
        return AM;
    }
    void setsemester(int sem)
    {
        semester=sem;
    }
    int getsemester() const
    {
        return semester;
    }
    void setsubjects(std::list<std::string> subj)
    {
        subjects=subj;
    }
    std::list<std::string> getsubjects() const
    {
        return subjects;
    }
    void setgrades(std::list<float> grad)
    {
        grades=grad;
    }
    std::list<float> getgrades() const
    {
        return grades;
    }

    Student(char* id,std::string nam,int by,std::string add,std::string phone,std::string em,int A,int sem): Person(id,nam,by,add,phone,em)
    {
        AM=A;
        semester=sem;
    }













