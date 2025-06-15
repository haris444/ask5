#include <string>
#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Profesor.h"
#include "Subject.h"
#include "Foititologio.h"
#include <fstream>

int main()
{
    Foititologio foit;
    try
    {
        foit.init();
    }
    catch(int ex)
    {
        if (ex==1)
        {
            std::cout<<"Αποτυχία ανοίγματος λίστας μαθημάτων"<<"\n";
        }
        else
        {
             std::cout<<"Αποτυχία ανοίγματος λίστας μελών τμήματος"<<"\n";
        }
        exit(-1);
    }
    try
    {
    foit.newsubject("1321P33","Digital Design",2,"Παναγιώτης Γιαννακόπουλος");
    }
    catch(int ex1)
    {
        std::cout<<"Αποτυχία ανοίγματος λίστας μαθημάτων";
        exit(-1);
    }
    try
    {
    foit.newstud(const_cast<char*>("AM654321"),"Κώστας Δημητρίου",1999,"Ερμού 9","6913579112","kosdim@gmail.com",18390007,10);
    }
    catch(int ex2)
    {
        std::cout<<"Αποτυχία ανοίγματος λίστας μελών";
        exit(-1);
    }
    try
    {
    foit.newprof(const_cast<char*>("AO31331"),"Παναγιώτης Γιαννακόπουλος",1972,"Ποσειδώνος 33","6900136948","panosgian@hotmail.com","390D0124","Digital Design");
    }
    catch(int ex3)
    {
        std::cout<<"Αποτυχία ανοίγματος λίστας μελών";
        exit(-1);
    }
    foit.sendemailprof();
    foit.sendemailstud();

    try
    {
        foit.addsubjecttostudent(18390007,"Digital Design");
    }
    catch(int ex4)
    {
        if (ex4==2)
        {
            std::cout<<"Αποτυχία ανοίγματος λίστας μελών";
            exit(-1);
        }
        else if(ex4==3)
        {
            std::cout<<"Δεν υπάρχει μάθημα με το όνομα που δώθηκε"<<"\n"<<"Δεν έγιναν αλλαγές"<<"\n";
        }
        else
        {
            std::cout<<"Δεν υπάρχει φοιτητής με τον ΑΜ που δώθηκε"<<"\n"<<"Δεν έγιναν αλλαγές"<<"\n";
        }
    }

    try
    {
        foit.editsubject("Βαγγέλης Παπαδόπουλος","1321P33");
    }
    catch(int ex5)
    {
        if (ex5==1)
        {
            std::cout<<"Αποτυχία ανοίγματος λίστας μαθημάτων";
            exit(-1);
        }
        else
        {
           std::cout<<"Δεν υπάρχει μάθημα με τον κωδικό που δώθηκε"<<"\n"<<"Δεν έγιναν αλλαγές"<<"\n";
        }
    }
    try
    {
        foit.editsubject(3,"1321P33");
    }
    catch(int ex5)
    {
        if (ex5==1)
        {
            std::cout<<"Αποτυχία ανοίγματος λίστας μαθημάτων";
            exit(-1);
        }
        else
        {
           std::cout<<"Δεν υπάρχει μάθημα με τον κωδικό που δώθηκε"<<"\n"<<"Δεν έγιναν αλλαγές"<<"\n";
        }
    }

    try
    {
        foit.deletesubject("4321P12","Programming");
    }
    catch(int ex6)
    {
        if (ex6==1)
        {
            std::cout<<"Αποτυχία ανοίγματος λίστας μαθημάτων";
            exit(-1);
        }
        else
        {
           std::cout<<"Δεν υπάρχει μάθημα με τον κωδικό που δώθηκε"<<"\n"<<"Δεν έγιναν αλλαγές"<<"\n";
        }
    }
    try
    {
        foit.gradestudent(18390007,"Digital Design",6.4);
    }
    catch (int ex7)
    {
        if(ex7==2)
        {
           std::cout<<"Αποτυχία ανοίγματος λίστας μελών";
           exit(-1);
        }
        else if (ex7==3)
        {
            std::cout<<"Δεν έχει δηλωθεί μάθημα με το όνομα που δώθηκε από τον φοιτητή"<<"\n"<<"Δεν έγιναν αλλαγές"<<"\n";
        }
        else
        {
            std::cout<<"Δεν υπάρχει φοιτητής με τον ΑΜ που δώθηκε"<<"\n"<<"Δεν έγιναν αλλαγές"<<"\n";
        }
    }

    try
    {
        foit.editsemesterstudent(18390007,5);
    }
    catch(int ex8)
    {
        if (ex8==2)
        {
           std::cout<<"Αποτυχία ανοίγματος λίστας μελών";
           exit(-1);
        }
        else
        {
           std::cout<<"Δεν υπάρχει φοιτητής με τον ΑΜ που δώθηκε"<<"\n"<<"Δεν έγιναν αλλαγές"<<"\n";
        }
    }
    try
    {
        foit.editprofesorspec("390Α0123","Computer Science");
    }
    catch(int ex9)
    {
        if (ex9==2)
        {
           std::cout<<"Αποτυχία ανοίγματος λίστας μελών";
           exit(-1);
        }
        else
        {
           std::cout<<"Δεν υπάρχει καθηγητής με τον κωδικό που δώθηκε"<<"\n"<<"Δεν έγιναν αλλαγές"<<"\n";
        }
    }

    try
    {
        foit.deleteprof("390Α0123");
    }
    catch(int ex10)
    {
        if (ex10==2)
        {
           std::cout<<"Αποτυχία ανοίγματος λίστας μελών";
           exit(-1);
        }
        else
        {
          std::cout<<"Δεν υπάρχει καθηγητής με τον κωδικό που δώθηκε"<<"\n"<<"Δεν έγιναν αλλαγές"<<"\n";
        }
    }
    try
    {
        foit.deletestud(18390007);
    }
    catch(int ex11)
    {
        if (ex11==2)
        {
           std::cout<<"Αποτυχία ανοίγματος λίστας μελών";
           exit(-1);
        }
        else
        {
          std::cout<<"Δεν υπάρχει φοιτητής με τον ΑΜ που δώθηκε"<<"\n"<<"Δεν έγιναν αλλαγές"<<"\n";
        }
    }
    return 0;
}