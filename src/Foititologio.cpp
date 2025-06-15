#include "Foititologio.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Person.h"
#include "Student.h"
#include "Profesor.h"
#include "Subject.h"

void Foititologio::newsubject(std::string cod,std::string subname,int sem,std::string pro)
{
   Subject sub(cod,subname,sem,pro);
   SubList.push_front(sub);
   std::fstream f;
   f.open("data/Subjects.csv",std::ios::out|std::ios::app);
   if (!f.is_open())
    {
        throw 1;
    }
    f<<sub.getcode()<<","<<sub.getsubjectname()<<","<<sub.getsemester()<<","<<sub.getprof()<<"\n";
    f.close();
}

void Foititologio::deletesubject(std::string cod,std::string subname)
{
    int flag=0;
    std::fstream f;
    f.open("data/Subjects.csv",std::ios::out|std::ios::trunc);
     if (!f.is_open())
    {
        throw 1;
    }
    f.close();
    f.open("data/Subjects.csv",std::ios::out);
     if (!f.is_open())
    {
        throw 1;
    }
    auto it=SubList.begin();
    auto end=SubList.end();
    while (it!=end)
    {
        if(it->getcode()==cod && it->getsubjectname()== subname)
        {
            it=SubList.erase(it);
            flag=1;
        }
        else
        {
            f<<it->getcode()<<","<<it->getsubjectname()<<","<<it->getsemester()<<","<<it->getprof()<<"\n";
            it++;
        }
    }
    f.close();
    if (flag==0)
    {
        throw 3;
    }
}

void Foititologio::editsubject(std::string pro,std::string cod)
{
    int flag=0;
    std::fstream f;
    f.open("data/Subjects.csv",std::ios::out|std::ios::trunc);
     if (!f.is_open())
    {
        throw 1;
    }
    f.close();
    f.open("data/Subjects.csv",std::ios::out);
     if (!f.is_open())
    {
        throw 1;
    }
    auto it=SubList.begin();
    auto end=SubList.end();
    while (it!=end)
    {
        if(it->getcode()==cod)
        {
            it->setprof(pro);
            f<<it->getcode()<<","<<it->getsubjectname()<<","<<it->getsemester()<<","<<it->getprof()<<"\n";
            flag=1;
        }
        else
        {
            f<<it->getcode()<<","<<it->getsubjectname()<<","<<it->getsemester()<<","<<it->getprof()<<"\n";
        }
        it++;
    }
    f.close();
    if (flag==0)
    {
        throw 3;
    }
}

void Foititologio::editsubject(int sem,std::string cod)
{
    int flag=0;
    std::fstream f;
    f.open("data/Subjects.csv",std::ios::out|std::ios::trunc);
     if (!f.is_open())
    {
        throw 1;
    }
    f.close();
    f.open("data/Subjects.csv",std::ios::out);
     if (!f.is_open())
    {
        throw 1;
    }
    auto it=SubList.begin();
    auto end=SubList.end();
    while (it!=end)
    {
        if(it->getcode()==cod)
        {
            it->setsemester(sem);
            f<<it->getcode()<<","<<it->getsubjectname()<<","<<it->getsemester()<<","<<it->getprof()<<"\n";
            flag=1;
        }
        else
        {
            f<<it->getcode()<<","<<it->getsubjectname()<<","<<it->getsemester()<<","<<it->getprof()<<"\n";
        }
        it++;
    }
    f.close();
    if (flag==0)
    {
        throw 3;
    }
}

void Foititologio::newstud(char* id,std::string nam,int by,std::string add,std::string phone,std::string em,int A,int sem)
{
    Student* stud1 = new Student(id,nam,by,add,phone,em,A,sem);
    PerList.push_front(stud1);
    std::fstream f;
    f.open("data/Members.csv",std::ios::out|std::ios::app);
    if (!f.is_open())
     {
         throw 2;
     }
     f<<stud1->getidnum()<<","<<stud1->getname()<<","<<stud1->getbirthyear()<<","<<stud1->getaddress()<<","<<stud1->getphonenum()<<","
      <<stud1->getemail()<<","<<stud1->getAM()<<","<<stud1->getsemester()<<"\n";
     f.close();
}

void Foititologio::newprof(char* id,std::string nam,int by,std::string add,std::string phone,std::string em,std::string cod,std::string spec)
{
    Profesor* prof1 = new Profesor(id,nam,by,add,phone,em,cod,spec);
    PerList.push_front(prof1);
    std::fstream f;
    f.open("data/Members.csv",std::ios::out|std::ios::app);
    if (!f.is_open())
     {
         throw 2;
     }
     f<<prof1->getidnum()<<","<<prof1->getname()<<","<<prof1->getbirthyear()<<","<<prof1->getaddress()<<","<<prof1->getphonenum()<<","
      <<prof1->getemail()<<","<<prof1->getcode()<<","<<prof1->getspecialty()<<"\n";
     f.close();
}

void Foititologio::addsubjecttostudent(int A,std::string subname)
{
    std::fstream f;
    f.open("data/Members.csv",std::ios::out|std::ios::trunc);
     if (!f.is_open())
    {
        throw 2;
    }
    f.close();
    f.open("data/Members.csv",std::ios::out);
     if (!f.is_open())
    {
        throw 2;
    }
    int flag=0;
    int flag1=0;
    auto subit=SubList.begin();
    auto subend=SubList.end();
    while (subit!=subend)
    {
        if(subname==subit->getsubjectname())
        {
            flag=1;
            break;
        }
        subit++;
    }
    if (flag==0)
    {
        f.close();
        throw 3;
    }
    auto it=PerList.begin();
    auto end=PerList.end();
    while (it!=end)
    {
        Person *pers=*it;
        Student *p= dynamic_cast<Student*>(pers);
        if (p!=NULL)
        {
            if (A==p->getAM())
            {
               std::list<std::string> subjects = p->getsubjects();
               subjects.push_front(subname);
               p->setsubjects(subjects);
               std::list<float> grades = p->getgrades();
               grades.push_front(-1);
               p->setgrades(grades);
               flag1=1;
            }
            f<<pers->getidnum()<<","<<pers->getname()<<","<<pers->getbirthyear()<<","<<pers->getaddress()<<","<<pers->getphonenum()<<","
             <<pers->getemail()<<","<<p->getAM()<<","<<p->getsemester()<<"\n";
        }
        else
        {
            Profesor *prof = dynamic_cast<Profesor*>(pers);
            f<<pers->getidnum()<<","<<pers->getname()<<","<<pers->getbirthyear()<<","<<pers->getaddress()<<","<<pers->getphonenum()<<","
             <<pers->getemail()<<","<<prof->getcode()<<","<<prof->getspecialty()<<"\n";
        }
        it++;
    }
    f.close();
    if (flag1==0)
    {
        throw 4;
    }
}

void Foititologio::removesubjectfromstudent(int A,std::string subname)
{
    int flag=0;
    int flag1=0;
    std::fstream f;
    f.open("data/Members.csv",std::ios::out|std::ios::trunc);
     if (!f.is_open())
    {
        throw 2;
    }
    f.close();
    f.open("data/Members.csv",std::ios::out);
     if (!f.is_open())
    {
        throw 2;
    }
    auto it=PerList.begin();
    auto end=PerList.end();
    while (it!=end)
    {
        Person *pers=*it;
        Student *p= dynamic_cast<Student*>(pers);
        if (p!=NULL)
        {
            if (A==p->getAM())
            {
                flag1=1;
                std::list<std::string> subjects = p->getsubjects();
                std::list<float> grades = p->getgrades();
                auto gradeit=grades.begin();
                auto subit=subjects.begin();
                auto subend=subjects.end();
                while (subit!=subend)
                {
                    if(subname==*subit)
                    {
                        subjects.erase(subit);
                        grades.erase(gradeit);
                        p->setsubjects(subjects);
                        p->setgrades(grades);
                        flag=1;
                        break;
                    }
                    subit++;
                    gradeit++;
                }
                if (flag==0)
                {
                    f.close();
                    throw 3;
                }
            }
            f<<pers->getidnum()<<","<<pers->getname()<<","<<pers->getbirthyear()<<","<<pers->getaddress()<<","<<pers->getphonenum()<<","
             <<pers->getemail()<<","<<p->getAM()<<","<<p->getsemester()<<"\n";
        }
        else
        {
            Profesor *prof = dynamic_cast<Profesor*>(pers);
            f<<pers->getidnum()<<","<<pers->getname()<<","<<pers->getbirthyear()<<","<<pers->getaddress()<<","<<pers->getphonenum()<<","
             <<pers->getemail()<<","<<prof->getcode()<<","<<prof->getspecialty()<<"\n";
        }
        it++;
    }
    f.close();
    if (flag1==0)
    {
        throw 4;
    }
}

void Foititologio::editsemesterstudent(int A,int sem)
{
    int flag=0;
    std::fstream f;
    f.open("data/Members.csv",std::ios::out|std::ios::trunc);
     if (!f.is_open())
    {
        throw 2;
    }
    f.close();
    f.open("data/Members.csv",std::ios::out);
     if (!f.is_open())
    {
        throw 2;
    }
    auto it=PerList.begin();
    auto end=PerList.end();
    while (it!=end)
    {
        Person *pers=*it;
        Student *p= dynamic_cast<Student*>(pers);
        if (p!=NULL)
        {
            if (A==p->getAM())
            {
               p->setsemester(sem);
               flag=1;
            }
            f<<pers->getidnum()<<","<<pers->getname()<<","<<pers->getbirthyear()<<","<<pers->getaddress()<<","<<pers->getphonenum()<<","
             <<pers->getemail()<<","<<p->getAM()<<","<<p->getsemester()<<"\n";
        }
        else
        {
            Profesor *prof = dynamic_cast<Profesor*>(pers);
            f<<pers->getidnum()<<","<<pers->getname()<<","<<pers->getbirthyear()<<","<<pers->getaddress()<<","<<pers->getphonenum()<<","
             <<pers->getemail()<<","<<prof->getcode()<<","<<prof->getspecialty()<<"\n";
        }
        it++;
    }
    f.close();
    if (flag==0)
    {
        throw 3;
    }
}

void Foititologio::editprofesorspec(std::string cod,std::string spec)
{
    int flag=0;
    std::fstream f;
    f.open("data/Members.csv",std::ios::out|std::ios::trunc);
     if (!f.is_open())
    {
        throw 2;
    }
    f.close();
    f.open("data/Members.csv",std::ios::out);
     if (!f.is_open())
    {
        throw 2;
    }
    auto it=PerList.begin();
    auto end=PerList.end();
    while (it!=end)
    {
        Person *pers=*it;
        Profesor *p= dynamic_cast<Profesor*>(pers);
        if (p!=NULL)
        {
            if (cod==p->getcode())
            {
               p->setspecialty(spec);
               flag=1;
            }
            f<<pers->getidnum()<<","<<pers->getname()<<","<<pers->getbirthyear()<<","<<pers->getaddress()<<","<<pers->getphonenum()<<","
             <<pers->getemail()<<","<<p->getcode()<<","<<p->getspecialty()<<"\n";
        }
        else
        {
            Student *stud = dynamic_cast<Student*>(pers);
            f<<pers->getidnum()<<","<<pers->getname()<<","<<pers->getbirthyear()<<","<<pers->getaddress()<<","<<pers->getphonenum()<<","
             <<pers->getemail()<<","<<stud->getAM()<<","<<stud->getsemester()<<"\n";
        }
        it++;
    }
    f.close();
    if (flag==0)
    {
        throw 3;
    }
}

void Foititologio::deletestud(int A)
{
    int flag=0;
    std::fstream f;
    f.open("data/Members.csv",std::ios::out|std::ios::trunc);
     if (!f.is_open())
    {
        throw 2;
    }
    f.close();
    f.open("data/Members.csv",std::ios::out);
     if (!f.is_open())
    {
        throw 2;
    }
    auto it=PerList.begin();
    auto end=PerList.end();
    while (it!=end)
    {
        Person *pers=*it;
        Student *p= dynamic_cast<Student*>(pers);
        if (p!=NULL)
        {
            if (A==p->getAM())
            {
                delete pers;
                it = PerList.erase(it);
                flag=1;
                continue;
            }
            f<<pers->getidnum()<<","<<pers->getname()<<","<<pers->getbirthyear()<<","<<pers->getaddress()<<","<<pers->getphonenum()<<","
             <<pers->getemail()<<","<<p->getAM()<<","<<p->getsemester()<<"\n";
        }
        else
        {
            Profesor *prof = dynamic_cast<Profesor*>(pers);
            f<<pers->getidnum()<<","<<pers->getname()<<","<<pers->getbirthyear()<<","<<pers->getaddress()<<","<<pers->getphonenum()<<","
             <<pers->getemail()<<","<<prof->getcode()<<","<<prof->getspecialty()<<"\n";
        }
        it++;
    }
    f.close();
    if (flag==0)
    {
        throw 3;
    }
}

void Foititologio::deleteprof(std::string cod)
{
    int flag=0;
    std::fstream f;
    f.open("data/Members.csv",std::ios::out|std::ios::trunc);
     if (!f.is_open())
    {
        throw 2;
    }
    f.close();
    f.open("data/Members.csv",std::ios::out);
     if (!f.is_open())
    {
        throw 2;
    }
    auto it=PerList.begin();
    auto end=PerList.end();
    while (it!=end)
    {
        Person *pers=*it;
        Profesor *p= dynamic_cast<Profesor*>(pers);
        if (p!=NULL)
        {
            if (cod==p->getcode())
            {
                delete pers;
                it = PerList.erase(it);
                flag=1;
                continue;
            }
            f<<pers->getidnum()<<","<<pers->getname()<<","<<pers->getbirthyear()<<","<<pers->getaddress()<<","<<pers->getphonenum()<<","
             <<pers->getemail()<<","<<p->getcode()<<","<<p->getspecialty()<<"\n";
        }
        else
        {
            Student *stud = dynamic_cast<Student*>(pers);
            f<<pers->getidnum()<<","<<pers->getname()<<","<<pers->getbirthyear()<<","<<pers->getaddress()<<","<<pers->getphonenum()<<","
             <<pers->getemail()<<","<<stud->getAM()<<","<<stud->getsemester()<<"\n";
        }
        it++;
    }
    f.close();
    if (flag==0)
    {
        throw 3;
    }
}

void Foititologio::editemail(char *id,std::string em)
{
    int flag=0;
    std::fstream f;
    f.open("data/Members.csv",std::ios::out|std::ios::trunc);
     if (!f.is_open())
    {
        throw 2;
    }
    f.close();
    f.open("data/Members.csv",std::ios::out);
     if (!f.is_open())
    {
        throw 2;
    }
    auto it=PerList.begin();
    auto end=PerList.end();
    while (it!=end)
    {
        Person *pers=*it;
        if (std::string(id)==std::string(pers->getidnum()))
        {
            pers->setemail(em);
            flag=1;
        }
        Profesor *p= dynamic_cast<Profesor*>(pers);
        if (p!=NULL)
        {
            f<<pers->getidnum()<<","<<pers->getname()<<","<<pers->getbirthyear()<<","<<pers->getaddress()<<","<<pers->getphonenum()<<","
             <<pers->getemail()<<","<<p->getcode()<<","<<p->getspecialty()<<"\n";
        }
        else
        {
            Student *stud = dynamic_cast<Student*>(pers);
            f<<pers->getidnum()<<","<<pers->getname()<<","<<pers->getbirthyear()<<","<<pers->getaddress()<<","<<pers->getphonenum()<<","
             <<pers->getemail()<<","<<stud->getAM()<<","<<stud->getsemester()<<"\n";
        }
        it++;
    }
    f.close();
    if (flag==0)
    {
        throw 3;
    }
}

void Foititologio::sendemailprof()
{
    std::cout<<"Έχει σταλεί email σε όλους τους καθηγητές"<<std::endl;
}

void Foititologio::sendemailstud()
{
    std::cout<<"Έχει σταλεί email σε όλους τους φοιτητές"<<std::endl;
}

void Foititologio::gradestudent(int A,std::string subname,float grad)
{
    int flag=0;
    int flag1=0;
    std::fstream f;
    f.open("data/Members.csv",std::ios::out|std::ios::trunc);
     if (!f.is_open())
    {
        throw 2;
    }
    f.close();
    f.open("data/Members.csv",std::ios::out);
     if (!f.is_open())
    {
        throw 2;
    }
    auto it=PerList.begin();
    auto end=PerList.end();
    while (it!=end)
    {
        Person *pers=*it;
        Student *p= dynamic_cast<Student*>(pers);
        if (p!=NULL)
        {
            if (A==p->getAM())
            {
                flag1=1;
                std::list<std::string> subjects = p->getsubjects();
                std::list<float> grades = p->getgrades();
                auto subit=subjects.begin();
                auto subend=subjects.end();
                auto gradeit=grades.begin();
                while (subit!=subend)
                {
                    if(subname==*subit)
                    {
                        *gradeit = grad;
                        p->setgrades(grades);
                        flag=1;
                        break;
                    }
                    subit++;
                    gradeit++;
                }
                if (flag==0)
                {
                    f.close();
                    throw 3;
                }
            }
            f<<pers->getidnum()<<","<<pers->getname()<<","<<pers->getbirthyear()<<","<<pers->getaddress()<<","<<pers->getphonenum()<<","
             <<pers->getemail()<<","<<p->getAM()<<","<<p->getsemester()<<"\n";
        }
        else
        {
            Profesor *prof = dynamic_cast<Profesor*>(pers);
            f<<pers->getidnum()<<","<<pers->getname()<<","<<pers->getbirthyear()<<","<<pers->getaddress()<<","<<pers->getphonenum()<<","
             <<pers->getemail()<<","<<prof->getcode()<<","<<prof->getspecialty()<<"\n";
        }
        it++;
    }
    f.close();
     if (flag1==0)
    {
        throw 4;
    }
}

void Foititologio::init()
{
    std::fstream f;
    std::vector<std::string> subvect;
    std::vector<std::string> persvect;
    std::string field;
    std::string line;
    std::string line1;
    std::string field1;

    f.open("data/Subjects.csv",std::ios::in);
    if (!f.is_open())
    {
        throw 1;
    }
    while(!f.eof())
    {
        getline(f,line);
        if(line.empty()) break;
        subvect.clear();
        std::stringstream ss(line);
        while (std::getline(ss,field,','))
        {
            subvect.push_back(field);
        }
        if(subvect.size() >= 4)
        {
            int sem=std::stoi(subvect[2]);
            Subject sub(subvect[0],subvect[1],sem,subvect[3]);
            SubList.push_front(sub);
        }
    }
    f.close();

    f.open("data/Members.csv",std::ios::in);
    if (!f.is_open())
    {
        throw 2;
    }
    while(!f.eof())
    {
        getline(f,line1);
        if(line1.empty()) break;
        persvect.clear();
        std::stringstream ss1(line1);
        while (std::getline(ss1,field1,','))
        {
            persvect.push_back(field1);
        }
        if(persvect.size() >= 7)
        {
            const char *id=persvect[0].c_str();
            int by=std::stoi(persvect[2]);
            try
            {
                int A= std::stoi(persvect[6]);
                int sem= std::stoi(persvect[7]);
                Student* stu = new Student(const_cast<char*>(id),persvect[1],by,persvect[3],persvect[4],persvect[5],A,sem);
                PerList.push_front(stu);
            }
            catch(const std::invalid_argument& e)
            {
                Profesor* pro = new Profesor(const_cast<char*>(id),persvect[1],by,persvect[3],persvect[4],persvect[5],persvect[6],persvect[7]);
                PerList.push_front(pro);
            }
        }
    }
    f.close();
}

Foititologio::~Foititologio()
{
    for(auto pers : PerList)
    {
        delete pers;
    }
}