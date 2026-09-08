// ConsoleTestApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Linklist.h"
#include <iostream>
#include "Person.h"
#include "Vector.h"
#include <iterator> // Required for std::size
#include <vector>
#include "employee_struct.h"

#include "BaseClass.h"
#include "SubClassA.h"
#include "SubClassB.h"
#include <memory>
#include "StringClass.h"



using namespace Vector;
using namespace Person;


int main()
{
    std::cout << "Let the good times roll!\n";

    PersonClass* ptrPerson = 0;

    
    LinkedList<PersonClass>* personLinkedList = new LinkedList<PersonClass>();

    ptrPerson = new Person::PersonClass("Orlando", "Monaco");

    personLinkedList->AppendEntry(*ptrPerson);

    ptrPerson = new Person::PersonClass("Christine", "Monaco");

    personLinkedList->AppendEntry(*ptrPerson);

    ptrPerson = new Person::PersonClass("Maximus", "Monaco");

    personLinkedList->InsertEntry(*ptrPerson, 1);


    ptrPerson = personLinkedList->FirstEntry();

    if (ptrPerson != 0) {

        do {

            std::cout << ptrPerson->strFirstName << "\n";

            std::cout << ptrPerson->strLastName << "\n";

    } while (ptrPerson = personLinkedList->NextEntry());
    }
    


    ptrPerson = new Person::PersonClass("Bruno", "Monaco");


    std::cout << ptrPerson;

    std::cout << ptrPerson->strFirstName;

    std::cout << (*ptrPerson).strFirstName;

    std::cout << ptrPerson->strLastName;

    delete ptrPerson;



    int arrayInt[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };


    for (int Index = 0; Index < std::size(arrayInt); Index++) {

        std::cout << arrayInt[Index];

    }


   


    // Vector of Pointers to Person Class

    std::vector<Person::PersonClass*> personVector;

    ptrPerson = new Person::PersonClass("1", "1");

    personVector.insert(personVector.end(), ptrPerson);

    ptrPerson = new Person::PersonClass("2", "2");

    personVector.insert(personVector.end(), ptrPerson);

    ptrPerson = new Person::PersonClass("3", "3");

    personVector.insert(personVector.end(), ptrPerson);


    // Iterate Through Vector

    for (std::vector<PersonClass*>::iterator vIterator = personVector.begin(); vIterator != personVector.end(); vIterator++) {

        std::cout << (*vIterator._Ptr)->strFirstName;
        std::cout << (*vIterator._Ptr)->strLastName;

    }

    for (int index = 0; index < personVector.size(); index++) {

        std::cout << personVector[index]->strFirstName;
        std::cout << personVector[index]->strLastName;

    }

    // Clear Vector Elements 

    for (int index = 0; index < personVector.size(); index++) {

        delete personVector[index];

    }

    // Clear Vector

    personVector.clear();


    employee_struct* ptr_employeeStruct = 0;


    ptr_employeeStruct = new employee_struct();

    ptr_employeeStruct->strFirstName = "Orlando";
    ptr_employeeStruct->strLastName = "Monaco";


    Vector::VectorClass vector = VectorClass(1.1, 2.2);
    Vector::VectorClass vector2 = VectorClass(2.1, 1.2);

    Vector::VectorClass vector_Total = VectorClass(0.0, 0.0);


    vector = vector + vector2;

    std::cout << " Vector X=" << vector.x << " Vector Y=" << vector.y;


    vector += vector2;


    std::cout << " Vector X=" << vector.x << " Vector Y=" << vector.y;



    vector_Total =  vector + vector2;


    std::cout << " Vector X=" << vector_Total.x << " Vector Y=" << vector_Total.y;


    // std::unique_ptr - single ownership
    // std::shared_ptr for shared ownership
    // Note Do not use Raw Pointers Unless Necessary


    //std::unique_ptr<SubClassA> uptr_SubClassA = std::make_unique<SubClassA>(2.2);

    std::unique_ptr<BaseClass> uptr_BaseClass = std::make_unique<SubClassA>(2.2);

    std::vector<std::unique_ptr<BaseClass>> vec_BaseClasses;


    vec_BaseClasses.push_back(std::make_unique<SubClassA>(2.1));

    vec_BaseClasses.push_back(std::make_unique<SubClassB>(2.2));


    for (int index = 0; index < vec_BaseClasses.size(); index++) {

        vec_BaseClasses[index]->show();

    }


    std::unique_ptr<VectorClass> uptr_VectorClass = std::make_unique<VectorClass>(0.0, 0.0);

    std::unique_ptr<VectorClass> uptr_VectorClassModify = std::make_unique<VectorClass>(5.0, 6.0);


    //  Reference is an alias to the original variable and not a copy so you can modify it.

    std::cout << " Vector X=" << uptr_VectorClassModify->x << " Vector Y=" << uptr_VectorClassModify->y;

    uptr_VectorClass->VectorReset(*uptr_VectorClassModify);

    std::cout << " Vector X=" << uptr_VectorClassModify->x << " Vector Y=" << uptr_VectorClassModify->y;



    // Test assignment = operator

    StringClass stringClass1("Original Value");

    StringClass stringClass2("Hello!");

    stringClass1 = stringClass2;

    std::cout << "String Class 1 " << stringClass1;

    std::cout << "String Class 2 " << stringClass2;


    // Test Copy Constructor

    // Allocate on Heap and not Stack


    std::unique_ptr<StringClass> uptr_StringClass = std::make_unique<StringClass>("Original Value");

    
    StringClass copytoStringClass = *uptr_StringClass;




}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
