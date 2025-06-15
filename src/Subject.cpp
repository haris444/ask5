#include <string>
#include "Subject.h"

void Subject::setcode(std::string co)
{
    code=co;
}

std::string Subject::getcode() const
{
    return code;
}

void Subject::setsubjectname(std::string sname)
{
    subjectname=sname;
}

std::string Subject::getsubjectname() const
{
    return subjectname;
}

void Subject::setsemester(int sem)
{
    semester=sem;
}

int Subject::getsemester() const
{
    return semester;
}

void Subject::setprof(std::string pro)
{
    prof=pro;
}

std::string Subject::getprof() const
{
    return prof;
}

Subject::Subject(std::string cod,std::string subname,int sem,std::string pro)
{
    code=cod;
    subjectname=subname;
    semester=sem;
    prof=pro;
}