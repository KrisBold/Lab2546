#ifndef CLASSUNIT_H
#define CLASSUNIT_H
#include <vector>
#include <list>
#include "Unit.h"
using namespace std;

class ClassUnit: public Unit
{
public:
    enum AccessModifier
    {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        INTERNAL,
        PROTECTEDINTERNAL,
        PRIVATEPROTECTED
    };
    static const vector<string> ACCESS_MODIFIERS;

public:
    explicit ClassUnit(const string& name): m_name(name) {};

    virtual void add(shared_ptr<Unit> unit, Flags flags) = 0;

    virtual string compile(unsigned int level = 0) const = 0;

    virtual ~ClassUnit() {};

protected:
    string m_name;
    using Fields = list<shared_ptr<Unit>>;
    vector<Fields> m_fields;
};

// определение статического массива
const vector<string> ClassUnit::ACCESS_MODIFIERS = {"public", "protected", "private", "internal", "protected internal", "private protected"};


#endif // CLASSUNIT_H
