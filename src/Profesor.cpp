#include "Person.h"
#include "Profesor.h"
#include <string>

    void setcode(std::string cod)
    {
        code=cod;
    }
    std::string getcode() const
    {
        return code;
    }
    void setspecialty(std::string spec)
    {
        specialty=spec;
    }
    std::string getspecialty() const
    {
        return specialty;
    }

    Profesor(char* id,std::string nam,int by,std::string add,std::string phone,std::string em,std::string cod,std::string spec): Person(id,nam,by,add,phone,em)
    {
        code=cod;
        specialty=spec;
    }
