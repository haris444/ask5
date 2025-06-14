#include "Foititologio.h"
#include <iostream>
#include <fstream>
#include "Person.h"
#include "Student.h"
#include "Profesor.h"
#include "Subject.h"

void newsubject(std::string cod,std::string subname,int sem,std::string pro)
{
   Subject subname(cod,subname,sem,pro);
   SubList.push_front(subname);
   std::fstream f;
   f.open(Subjects.csv,ios::out|ios::app);
   if (!f.is_open())
    {
        throw 1;
    }
    f<<subname.getcode()<<","<<subname.getsubjectname()<<","<<subname.getsemester()<<","<<subname.getprof()<<"\n";


}

void deletesubject(std::string cod,std::string subname)
{
    int flag=0;
    std::fstream f;
    f.open(Subjects.csv,ios::out|ios::trunc);
     if (!f.is_open())
    {
        throw 1;
    }
    f.close();
    f.open(Subjects.csv,ios::out);
     if (!f.is_open())
    {
        throw 1;
    }
    auto it=SubList.begin();
    auto end=SubList.end();
    while (it!=end)
    {

        if(*it.getcode()==cod && *it.getsubjectname()== subname)
        {
            it=SubList.erase(it);
            flag=1;
        }
        else
        {
            f<<*it.getcode()<<","<<*it.getsubjectname()<<","<<*it.getsemester()<<","<<*it.getprof()<<"\n";
            it++;
    }
    if (flag==0)
    {
        throw 3;
    }

}

void editsubject(std::string pro,std::string cod)
{
    int flag=0;
    std::fstream f;
    f.open(Subjects.csv,ios::out|ios::trunc);
     if (!f.is_open())
    {
        throw 1;
    }
    f.close()
    f.open(Subjects.csv,ios::out);
     if (!f.is_open())
    {
        throw 1;
    }
    auto it=SubList.begin();
    auto end=SubList.end();
    while (it!=end)
    {
        if(*it.getcode()==cod)
        {
            *it.setprof(pro);
            f<<*it.getcode()<<","<<*it.getsubjectname()<<","<<*it.getsemester()<<","<<*it.getprof()<<"\n";
            flag=1;
        }
        else
        {
            f<<*it.getcode()<<","<<*it.getsubjectname()<<","<<*it.getsemester()<<","<<*it.getprof()<<"\n";
            it++;
        }
    }
    if (flag==0)
    {
        throw 3;
    }
}


void editsubject(int sem,std::string cod)
{
    int flag=0;
    std::fstream f;
    f.open(Subjects.csv,ios::out|ios::trunc);
     if (!f.is_open())
    {
        throw 1;
    }
    f.close()
    f.open(Subjects.csv,ios::out);
     if (!f.is_open())
    {
        throw 1;
    }
    auto it=SubList.begin();
    auto end=SubList.end();
    while (it!=end)
    {
        if(*it.getcode()==cod)
        {
            *it.setsemester(sem);
            f<<*it.getcode()<<","<<*it.getsubjectname()<<","<<*it.getsemester()<<","<<*it.getprof()<<"\n";
            flag=1;
        }
        else
        {
            f<<*it.getcode()<<","<<*it.getsubjectname()<<","<<*it.getsemester()<<","<<*it.getprof()<<"\n";
            it++;
        }
    }
    if (flag==0)
    {
        throw 3;
    }
}

void newstud(char* id,std::string nam,int by,std::string add,std::string phone,std::string em,int A,int sem)
{
    Student stud1(id,nam,by,add,phone,em,A,sem);
    PerList.push_front(stud1);
    std::fstream f;
    f.open(Members.csv,ios::out|ios::app);
    if (!f.is_open())
     {
         throw 2;
     }
     f<<stud1.getidnum()<<","<<stud1.getname()<<","<<stud1.getbirthyear()<<","<<stud1.getaddress()<<","<<stud1.getphonenum()<<","
      <<stud1.getemail()<<","<<stud1.getAM()<<","<<stud1.getsemester();

}

void newprof(std::string nam,int by,std::string add,std::string phone,std::string em,std::string cod,std::string spec)
{
    Profesor prof1(id,nam,by,add,phone,em,cod,spec);
    PerList.push_front(prof1);
    std::fstream f;
    f.open(Members.csv,ios::out|ios::app);
    if (!f.is_open())
     {
         throw 2;
     }
     f<<prof1.getidnum()<<","<<prof1.getname()<<","<<prof1.getbirthyear()<<","<<prof1.getaddress()<<","<<prof1.getphonenum()<<","
      <<prof1.getemail()<<","<<prof1.getcode()<<","<<prof1.getspecialty();
}


void addsubjecttostudent(int A,std::string subname)
{
    std::fstream f;
    f.open(Members.csv,ios::out|ios::trunc);
     if (!f.is_open())
    {
        throw 2;
    }
    f.close()
    f.open(Members.csv,ios::out);
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
        if(subname==*subit.getsubjectname())
        {
            flag=1;
            break;
        }
        subit++;
    }
    if (flag==0)
    {
        //"Δεν υπάρχει μάθημα με όνομα"
        throw 3;
    }
    auto it=PerList.begin();
    auto end=PerList.end();
    while (it!=end)
    {
        Person *pers=*it;
        Student *p= dynamic cast<Student*> pers;
        if (p!=NULL)
        {
            if (A==p.getAM())
            {
               pers.getsubjects().push_front(subname);
               pers.getgrades().push_front(-1);
               flag1=1;
            }
              f<<pers.getidnum()<<","<<pers.getname()<<","<<pers.getbirthyear()<<","<<pers.getaddress()<<","<<pers.getphonenum()<<","
               <<pers.getemail()<<","<<pers.getAM()<<","<<pers.getsemester();
               auto it1=subjects.begin();
               auto end1=subjects.end();
               auto it2=grades.begin();
               while (it1!=end1!)
               {
                   f<<*it1<<","<<*it2<<"\n";

               }
        }
        else
        {
            f<<pers.getidnum()<<","<<pers.getname()<<","<<pers.getbirthyear()<<","<<pers.getaddress()<<","<<pers.getphonenum()<<","
             <<pers.getemail()<<","<<pers.getcode()<<","<<pers.getspecialty()<<"\n";
        }
        it++;
    }
    if (flag1==0)
    {
        //"Δεν υπάρχει φοιτητής με τον ΑΜ"
        throw 4;
    }

}

void removesubjectfromstudent(int A,std::string subname)
{
    int flag=0;
    int flag1=0;
    std::fstream f;
    f.open(Members.csv,ios::out|ios::trunc);
     if (!f.is_open())
    {
        throw 2;
    }
    f.close()
    f.open(Members.csv,ios::out);
     if (!f.is_open())
    {
        throw 2;
    }
    auto it=PerList.begin();
    auto end=PerList.end();
    while (it!=end)
    {
        Person *pers=*it;
        Student *p= dynamic cast<Student*> pers;
        if (p!=NULL)
        {
            if (A==p.getAM())
            {
                flag1=1;
                auto gradeit=pers.getgrades().begin();
                auto subit=pers.getsubjects().begin();
                auto subend=pers.getsubjects().end();
                while (subit!=subend)
                {
                    if(subname==*subit)
                    {
                        pers.getsubjects().erase(subit);
                        pers.getgrades().erase(gradeit);
                        flag=1;
                    }
                     f<<pers.getidnum()<<","<<pers.getname()<<","<<pers.getbirthyear()<<","<<pers.getaddress()<<","<<pers.getphonenum()<<","
                      <<pers.getemail()<<","<<pers.getAM()<<","<<pers.getsemester();
                     auto it1=subjects.begin();
                     auto end1=subjects.end();
                     auto it2=grades.begin();
                     auto end2=grades.end();
                     while (it1!=end1!)
                     {
                        f<<*it1<<","<<*it2<<"\n";

                     }
                     subit++;
                     gradeit++;
                }
                if (flag==0)
                {
                    //"Ο φοιτητής δεν έχει δηλώσει μάθημα με όνομα"
                    throw 3;
                }

            }
            else
            {
                f<<pers.getidnum()<<","<<pers.getname()<<","<<pers.getbirthyear()<<","<<pers.getaddress()<<","<<pers.getphonenum()<<","
                 <<pers.getemail()<<","<<pers.getcode()<<","<<pers.getspecialty()<<"\n";
            }
        }
        it++;
    }
    if (flag1==0)
    {
        //"Δεν υπάρχει φοιτητής με ΑΜ"
        throw 4;
    }
}



void editsemesterstudent(int A,int sem)
{
    int flag=0;
    std::fstream f;
    f.open(Members.csv,ios::out|ios::trunc);
     if (!f.is_open())
    {
        throw 2;
    }
    f.close()
    f.open(Members.csv,ios::out);
     if (!f.is_open())
    {
        throw 2;
    }
    auto it=PerList.begin();
    auto end=PerList.end();
    while (it!=end)
    {
        Person *pers=*it;
        Student *p= dynamic cast<Student*> pers;
        if (p!=NULL)
        {
            if (A==p.getAM())
            {
               pers.setsemester(sem);
               flag=1;
            }
            f<<pers.getidnum()<<","<<pers.getname()<<","<<pers.getbirthyear()<<","<<pers.getaddress()<<","<<pers.getphonenum()<<","
             <<pers.getemail()<<","<<pers.getAM()<<","<<pers.getsemester();
            auto it1=subjects.begin();
            auto end1=subjects.end();
            auto it2=grades.begin();
            auto end2=grades.end();
            while (it1!=end1!)
            {
               f<<*it1<<","<<*it2<<"\n";
            }
        }
        else
        {
            f<<pers.getidnum()<<","<<pers.getname()<<","<<pers.getbirthyear()<<","<<pers.getaddress()<<","<<pers.getphonenum()<<","
             <<pers.getemail()<<","<<pers.getcode()<<","<<pers.getspecialty()<<"\n";
        }
        it++
    }
    if (flag==0)
    {
        //"Δεν υπάρχει φοιτητής με ΑΜ"
        throw 3;
    }
}

void editprofesorspec(std::string cod,std::string spec)
{
    int flag=0;
    std::fstream f;
    f.open(Members.csv,ios::out|ios::trunc);
     if (!f.is_open())
    {
        throw 2;
    }
    f.close()
    f.open(Members.csv,ios::out);
     if (!f.is_open())
    {
        throw 2;
    }
    auto it=PerList.begin();
    auto end=PerList.end();
    while (it!=end)
    {
        Person *pers=*it;
        Profesor *p= dynamic cast<Profesor*> pers;
        if (p!=NULL)
        {
            if (cod==p.getcode())
            {
               pers.setspecialty(spec);
               flag=1;
            }
            f<<pers.getidnum()<<","<<pers.getname()<<","<<pers.getbirthyear()<<","<<pers.getaddress()<<","<<pers.getphonenum()<<","
             <<pers.getemail()<<","<<pers.getcode()<<","<<pers.getspecialty()<<"\n";
        }
        else
        {
            f<<pers.getidnum()<<","<<pers.getname()<<","<<pers.getbirthyear()<<","<<pers.getaddress()<<","<<pers.getphonenum()<<","
             <<pers.getemail()<<","<<pers.getAM()<<","<<pers.getsemester();
            auto it1=subjects.begin();
            auto end1=subjects.end();
            auto it2=grades.begin();
            auto end2=grades.end();
            while (it1!=end1!)
            {
               f<<*it1<<","<<*it2<<"\n";
            }
        }
        it++;
    }
    if (flag==0)
    {
        //"Δεν υπάρχει καθηγητής με κωδικό"
        throw 3;
    }

}


void deletestud(int A)
{
    int flag=0;
    std::fstream f;
    f.open(Members.csv,ios::out|ios::trunc);
     if (!f.is_open())
    {
        throw 2;
    }
    f.close()
    f.open(Members.csv,ios::out);
     if (!f.is_open())
    {
        throw 2;
    }
    auto it=PerList.begin();
    auto end=PerList.end();
    while (it!=end)
    {
        Person *pers=*it;
        Student *p= dynamic cast<Student*> pers;
        if (p!=NULL)
        {
            if (A==p.getAM())
            {
                PerList.erase(it);
                flag=1;
                continue;
            }
            f<<pers.getidnum()<<","<<pers.getname()<<","<<pers.getbirthyear()<<","<<pers.getaddress()<<","<<pers.getphonenum()<<","
             <<pers.getemail()<<","<<pers.getAM()<<","<<pers.getsemester();
            auto it1=subjects.begin();
            auto end1=subjects.end();
            auto it2=grades.begin();
            auto end2=grades.end();
            while (it1!=end1!)
            {
               f<<*it1<<","<<*it2<<"\n";
            }
        }
        else
        {
            f<<pers.getidnum()<<","<<pers.getname()<<","<<pers.getbirthyear()<<","<<pers.getaddress()<<","<<pers.getphonenum()<<","
             <<pers.getemail()<<","<<pers.getcode()<<","<<pers.getspecialty()<<"\n";
        }
        it++;
    }
    if (flag==0)
    {
        //"Δεν υπάρχει φοιτητής με ΑΜ"
        throw 3;
    }
}


void deleteprof(std::string cod)
{
    flag=0;
    std::fstream f;
    f.open(Members.csv,ios::out|ios::trunc);
     if (!f.is_open())
    {
        throw 2;
    }
    f.close()
    f.open(Members.csv,ios::out);
     if (!f.is_open())
    {
        throw 2;
    }
    auto it=PerList.begin();
    auto end=PerList.end();
    while (it!=end)
    {
        Person *pers=*it;
        Profesor *p= dynamic cast<Profesor*> pers;
        if (p!=NULL)
        {
            if (cod==p.getcode())
            {
                PerList.erase(it);
                flag=1;
                continue;
            }
            f<<pers.getidnum()<<","<<pers.getname()<<","<<pers.getbirthyear()<<","<<pers.getaddress()<<","<<pers.getphonenum()<<","
             <<pers.getemail()<<","<<pers.getcode()<<","<<pers.getspecialty()<<"\n";
        }
        else
        {
            f<<pers.getidnum()<<","<<pers.getname()<<","<<pers.getbirthyear()<<","<<pers.getaddress()<<","<<pers.getphonenum()<<","
             <<pers.getemail()<<","<<pers.getAM()<<","<<pers.getsemester();
            auto it1=subjects.begin();
            auto end1=subjects.end();
            auto it2=grades.begin();
            auto end2=grades.end();
            while (it1!=end1!)
            {
               f<<*it1<<","<<*it2<<"\n";
            }
        }
        it++;
    }
    if (flag==0)
    {
        //"Δεν υπάρχει καθηγητής με κωδικό"
        throw 3;
    }
}




void editemail(char *id,std::string em)
{
    flag=0;
    std::fstream f;
    f.open(Members.csv,ios::out|ios::trunc);
     if (!f.is_open())
    {
        throw 2;
    }
    f.close()
    f.open(Members.csv,ios::out);
     if (!f.is_open())
    {
        throw 2;
    }
    auto it=PerList.begin();
    auto end=PerList.end();
    while (it!=end)
    {
        Person *pers=*it;
        if (*id==p.getidnum())
            {
                pers.setemail(em);
                flag=1;
            }
        Profesor *p= dynamic cast<Profesor*> pers;
        if (p!=NULL)
        {
            f<<pers.getidnum()<<","<<pers.getname()<<","<<pers.getbirthyear()<<","<<pers.getaddress()<<","<<pers.getphonenum()<<","
             <<pers.getemail()<<","<<pers.getcode()<<","<<pers.getspecialty()<<"\n";
        }
        else
        {
            f<<pers.getidnum()<<","<<pers.getname()<<","<<pers.getbirthyear()<<","<<pers.getaddress()<<","<<pers.getphonenum()<<","
             <<pers.getemail()<<","<<pers.getAM()<<","<<pers.getsemester();
            auto it1=subjects.begin();
            auto end1=subjects.end();
            auto it2=grades.begin();
            auto end2=grades.end();
            while (it1!=end1!)
            {
               f<<*it1<<","<<*it2<<"\n";
            }
        }

        it++;
    }
    if (flag==0)
    {
        //"Δεν υπάρχει μέλος του τμήματος με αριθμό ταυτότητας"
        throw 3;
    }
}


void sendemailprof()
{
    cout<<"Έχει σταλεί email σε όλους τους καθηγητές"<<endl;
}

void sendemailstud()
{
    cout<<"Έχει σταλεί email σε όλους τους φοιτητές"<<endl;
}

void gradestudent(int A,std::string subname,float grad)
{
    int flag=0;
    int flag1=0;
    std::fstream f;
    f.open(Members.csv,ios::out|ios::trunc);
     if (!f.is_open())
    {
        throw 2;
    }
    f.close()
    f.open(Members.csv,ios::out);
     if (!f.is_open())
    {
        throw 2;
    }
    auto it=PerList.begin();
    auto end=PerList.end();
    while (it!=end)
    {
        Person *pers=*it;
        Student *p= dynamic cast<Student*> pers;
        if (p!=NULL)
        {
            if (A==p.getAM())
            {
                flag1=1;
                auto subit=pers.getsubjects().begin();
                auto subend=pers.getsubjects().end();
                while (subit!=subend)
                {
                    if(subname==*subit)
                    {
                        pers.getgrades().insert(subit,grad);
                        flag=1;
                    }
                    subit++;
                }
                if (flag==0)
                {
                    //"Ο φοιτητής δεν έχει δηλώσει μάθημα με όνομα"
                    throw 3;
                }
            }
            f<<pers.getidnum()<<","<<pers.getname()<<","<<pers.getbirthyear()<<","<<pers.getaddress()<<","<<pers.getphonenum()<<","
             <<pers.getemail()<<","<<pers.getAM()<<","<<pers.getsemester();
            auto it1=subjects.begin();
            auto end1=subjects.end();
            auto it2=grades.begin();
            auto end2=grades.end();
            while (it1!=end1!)
            {
               f<<*it1<<","<<*it2<<"\n";
            }

        }
        else
        {
           f<<pers.getidnum()<<","<<pers.getname()<<","<<pers.getbirthyear()<<","<<pers.getaddress()<<","<<pers.getphonenum()<<","
            <<pers.getemail()<<","<<pers.getcode()<<","<<pers.getspecialty()<<"\n";
        }
        it++;
    }
     if (flag1==0)
    {
        //"Δεν υπάρχει φοιτητής με ΑΜ"
        throw 4;
    }
}



void init()
{
    std::fstream f;
    vector<std::string> subvect;
    vector<std::string> persvect;
    std::string field;
    std::string line;
    std::string line1;
    std::string field1;
    f.open(Subjects.csv,ios::in);
    if (!f.is_open())
    {
        throw 1;
    }
    while(!f.eof())
    {
        getline(f,line);
        std::stringstream ss(line);
        while (std::getline(ss,field,","))
        {
            subvect.push_back(field);
        }
        int sem=std::stoi(subvect[2]);
        Subject subname(subvect[0],subvect[1],sem,subvect[3]);
        SubList.push_front(subname);
        if(f.eof())
        {
            break;
        }
    }
    f.close();
    f.open(Members.csv,ios::in);
    if (!f.is_open())
    {
        throw 2;
    }
    while(!f.eof())
    {
        getline(f,line1);
        std::stringstream ss1(line1);
        while (std::getline(ss,field1,","))
        {
            persvect.push_back(field1);
        }
        cont char *id=persvect[0].c_str;
        int by=std::stoi(persvect[2]);
        try
        {
            int A= std::stoi(persvect[6]);
            int sem= std::stoi(persvect[7]);
            Student stu(*id,persvect[1],by,persvect[3],persvect[4],persvect[5],A,sem);
            PerList.push_front(stu);
        }
        catch(const std::invalid_argument& e)
        {
            Profesor pro(*id,persvect[1],by,persvect[3],persvect[4],persvect[5],persvect[6],persvect[7]);
            PerList.push_front(pro);
        }
        if(f.eof())
        {
            break;
        }
    }
    f.close();
}
