#include "Person.h"
#include "Profesor.h"
#include <string>

void Profesor::setcode(std::string cod)
{
    code=cod;
}

std::string Profesor::getcode() const
{
    return code;
}

void Profesor::setspecialty(std::string spec)
{
    specialty=spec;
}

std::string Profesor::getspecialty() const
{
    return specialty;
}

Profesor::Profesor(char* id,std::string nam,int by,std::string add,std::string phone,std::string em,std::string cod,std::string spec): Person(std::string(id),nam,by,add,phone,em)
{
    code=cod;
    specialty=spec;
}