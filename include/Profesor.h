#ifndef PROFESOR_H
#define PROFESOR_H

#include "Person.h"
#include <string>

class Profesor: public Person
{
private:
    std::string code;
    std::string specialty;
public:
    void setcode(std::string);
    std::string getcode() const;
    void setspecialty(std::string);
    std::string getspecialty() const;
    Profesor(char*,std::string,int,std::string,std::string,std::string,std::string,std::string);
};

#endif