#ifndef CPPFACTORY_H
#define CPPFACTORY_H
#include "AbstractFactory.h"
#include "CPPClassUnit.h"
#include "CPPMethodUnit.h"
#include "CPPPrintOperatorUnit.h"
using namespace std;

class CPPFactory: public AbstractFactory
{
public:
    shared_ptr<ClassUnit> ClassUnitDo(const string& name) const
    {
        return shared_ptr<ClassUnit>(new CPPClassUnit(name));
    }

    shared_ptr<MethodUnit> MethodUnitDo(const string& name, const string& returnType, Unit::Flags flags) const
    {
        return shared_ptr<MethodUnit>(new CPPMethodUnit(name, returnType, flags));
    }

    shared_ptr<PrintOperatorUnit> PrintOperatorUnitDo(const string& text) const
    {
        return shared_ptr<PrintOperatorUnit>(new CPPPrintOperatorUnit(text));
    }
    ~CPPFactory() {};
};

#endif // CPPFACTORY_H
