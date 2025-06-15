#ifndef FOITITOLOGIO_H
#define FOITITOLOGIO_H

#include "Person.h"
#include "Student.h"
#include "Profesor.h"
#include "Subject.h"
#include <list>
#include <string>

class Foititologio
{
private:
    std::list<Subject> SubList;
    std::list<Person*> PerList;
public:
    void newsubject(std::string,std::string ,int,std::string);
    void editsubject(std::string,std::string);
    void editsubject(int,std::string);
    void deletesubject(std::string,std::string);
    void newstud(char*,std::string,int,std::string,std::string,std::string,int,int);
    void newprof(char*,std::string,int,std::string,std::string,std::string,std::string,std::string);
    void addsubjecttostudent(int,std::string);
    void removesubjectfromstudent(int,std::string);
    void editsemesterstudent(int,int);
    void editprofesorspec(std::string,std::string);
    void deletestud(int);
    void deleteprof(std::string);
    void editemail(char*,std::string);
    void sendemailprof();
    void sendemailstud();
    void gradestudent(int,std::string,float);
    void init();
    ~Foititologio();
};

#endif