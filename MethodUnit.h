#ifndef METHODUNIT_H
#define METHODUNIT_H
#include <list>
#include "Unit.h"
using namespace std;

class MethodUnit: public Unit
{
public:
    enum Modifier
    {
        CONST= 1,
        STATIC= 2,
        VIRTUAL= 4,
        FINAL= 8,
        ABSTRACT= 16,
        SYNCHRONIZED= 32
    };
public:
     MethodUnit(const string& name, const string& returnType, Flags flags):
        m_name(name), m_returnType(returnType), m_flags(flags) {}

    virtual void add(shared_ptr<Unit> unit, Flags flags = 0) = 0;

    virtual string compile(unsigned int level = 0) const = 0;

    virtual ~MethodUnit() {};

protected:
    string m_name;
    string m_returnType;
    Flags m_flags;
    list<shared_ptr<Unit>> m_body;
};

#endif // METHODUNIT_H
