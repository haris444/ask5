#include <string>
class Subject
{
private:
    std::string code;
    std::string subjectname;
    int semester;
    std::string prof;
public:
    void setcode(std::string);
    std::string getcode() const;
    void setsubjectname(std::string);
    std::string getsubjectname() const;
    void setsemester(int);
    int getsemester() const;
    void setprof(std::string);
    std::string getprof() const;
    Subject(std::string ,std::string ,int ,std::string );

};
