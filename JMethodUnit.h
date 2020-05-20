#ifndef JMETHODUNIT_H
#define JMETHODUNIT_H
#include "Unit.h"
#include "MethodUnit.h"
using namespace std;

class JMethodUnit: public MethodUnit
{
public:
    explicit JMethodUnit(const string& name, const string& returnType, Unit::Flags flags):
        MethodUnit(name, returnType, flags) {};

    void add(shared_ptr<Unit> unit, Unit::Flags = 0)
    {
        m_body.push_back(unit);
    }

    string compile(unsigned int level = 0) const
    {
        string result = "";

        if(m_flags & MethodUnit::Modifier::STATIC)
        {
            result += "static ";
        }

        if (m_flags & MethodUnit::Modifier::FINAL)
        {
            result += "final ";
        }

        if(m_flags & MethodUnit::Modifier::SYNCHRONIZED)
        {
            result += "synchronized ";
        }

        if(m_flags & MethodUnit::Modifier::ABSTRACT)
        {
            result += "abstract ";
        }

        result += m_returnType + " ";
        result += m_name + "()";
        result += " {\n";

        for(const auto& b: m_body) {
            result += b->compile(level + 1);
        }
        result += generateShift(level) + "}\n";

        return result;
    }
};
#endif // JMETHODUNIT_H
