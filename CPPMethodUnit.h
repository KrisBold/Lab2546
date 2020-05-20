#ifndef CPPMETHODUNIT_H
#define CPPMETHODUNIT_H
#include "Unit.h"
#include "MethodUnit.h"
using namespace std;

class CPPMethodUnit: public MethodUnit
{
public:
    explicit CPPMethodUnit(const string& name, const string& returnType, Flags flags):
        MethodUnit(name, returnType, flags) {}

    void add(shared_ptr<Unit> unit, Flags = 0)
    {
         m_body.push_back(unit);
    }

    string compile(unsigned int level = 0) const
    {
        string result = generateShift(level);

        if(m_flags & MethodUnit::Modifier::STATIC)
        {
            result += "static ";
        }
        else if(m_flags & MethodUnit::Modifier::VIRTUAL)
        {
            result += "virtual ";
        }
        result += m_returnType + " ";
        result += m_name + "()";
        if(m_flags & MethodUnit::Modifier::CONST)
        {
            result += " const";
        }

        result += " {\n";
        for(const auto& b: m_body) {
            result += b->compile(level + 1);
        }
        result += generateShift(level) + "}\n";

        return result;
    }
};
#endif // CPPMETHODUNIT_H
