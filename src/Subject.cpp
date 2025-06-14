#include <string>
#include "Subject.h"

    void setcode(std::string co)
    {
        code=x;
    }
    std::string getcode() const
    {
        return code;
    }
    void setsubjectname(std::string sname)
    {
        subjectname=sname
    }
    std::string getsubjectname() const
    {
        return subjectname;
    }
    void setsemester(int sem)
    {
        semester=sem;
    }
    int getsemester() const
    {
        return semester;
    }
    void setprof(std::string pro)
    {
        prof=pro;
    }
    std::string getprof() const
    {
        return prof;
    }

    Subject(std::string cod,std::string subname,int sem,std::string pro)
    {
        code=cod;
        subjectname=subname;
        semester=sem;
        prof=pro;
    }










