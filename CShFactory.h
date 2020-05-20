#ifndef CSHFACTORY_H
#define CSHFACTORY_H
#include "AbstractFactory.h"
#include "CShClassUnit.h"
#include "CShMethodUnit.h"
#include "CShPrintOperatorUnit.h"

class CShFactory: public AbstractFactory
{
public:
    shared_ptr<ClassUnit> ClassUnitDo(const string& name) const
    {
        return shared_ptr<ClassUnit>(new CShClassUnit(name));
    }

    shared_ptr<MethodUnit> MethodUnitDo(const string& name, const string& returnType, Unit::Flags flags) const
    {
        return shared_ptr<MethodUnit>(new CShMethodUnit(name, returnType, flags));
    }

    shared_ptr<PrintOperatorUnit> PrintOperatorUnitDo(const string& text) const
    {
        return shared_ptr<PrintOperatorUnit>(new CShPrintOperatorUnit(text));
    }
    ~CShFactory() {};
};

#endif // CSHFACTORY_H
