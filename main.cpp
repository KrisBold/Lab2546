#include <QCoreApplication>
#include <iostream>
#include "CPPFactory.h"
#include "CShFactory.h"
#include "JFactory.h"
using namespace std;

string generateProgram()
{
    string result;
    AbstractFactory* factory;

    for (int i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
            factory = new CPPFactory(); break;
        case 1:
            factory = new CShFactory(); break;
        case 2:
            factory = new JFactory(); break;
        }
        shared_ptr<ClassUnit> myClass(factory->ClassUnitDo("MyClass"));

        myClass->add(factory->MethodUnitDo("testFunc1", "void", 0), ClassUnit::PUBLIC);

        myClass->add(factory->MethodUnitDo("testFunc2", "void", MethodUnit::STATIC), ClassUnit::PRIVATE);

        myClass->add(factory->MethodUnitDo("testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST), ClassUnit::PUBLIC);

        shared_ptr<MethodUnit> method = factory->MethodUnitDo("testFunc4", "void", MethodUnit::STATIC);

        method->add(factory->PrintOperatorUnitDo(R"(Hello, world!\n)"));

        myClass->add(method, ClassUnit::PROTECTED);

        result += myClass->compile() + '\n';

        delete factory;
    }
    return result;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout << generateProgram() << endl;

    return a.exec();
}
