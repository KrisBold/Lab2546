#ifndef JFACTORY_H
#define JFACTORY_H
#include "AbstractFactory.h"
#include "JClassUnit.h"
#include "JMethodUnit.h"
#include "JPrintOperatorUnit.h"
using namespace std;

class JFactory: public AbstractFactory
{
public:
    shared_ptr<ClassUnit> ClassUnitDo(const string& name) const
    {
        return shared_ptr<ClassUnit>(new JClassUnit(name));
    }

    shared_ptr<MethodUnit> MethodUnitDo(const string& name, const string& returnType, Unit::Flags flags) const
    {
        return shared_ptr<MethodUnit>(new JMethodUnit(name, returnType, flags));
    }

    shared_ptr<PrintOperatorUnit> PrintOperatorUnitDo(const string& text) const
    {
        return shared_ptr<PrintOperatorUnit>(new JPrintOperatorUnit(text));
    }
    ~JFactory() {};
};
#endif // JFACTORY_H
