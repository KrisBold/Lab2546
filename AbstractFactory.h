#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H
#include "ClassUnit.h"
#include "MethodUnit.h"
#include "PrintOperatorUnit.h"
using namespace std;

class AbstractFactory
{
public:
    virtual shared_ptr<ClassUnit> ClassUnitDo(const string& name) const = 0;

    virtual shared_ptr<MethodUnit> MethodUnitDo(const string& name, const string& returnType, Unit::Flags flags) const = 0;

    virtual shared_ptr<PrintOperatorUnit> PrintOperatorUnitDo(const string& text) const = 0;

    virtual ~AbstractFactory() {};
};

#endif // ABSTRACTFACTORY_H
