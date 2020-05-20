#ifndef CSHMETHODUNIT_H
#define CSHMETHODUNIT_H
#include "Unit.h"
#include "MethodUnit.h"
using namespace std;

class CShMethodUnit: public MethodUnit
{
public:
    explicit CShMethodUnit(const string& name, const std::string& returnType, Unit::Flags flags):
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

       if( m_flags & MethodUnit::Modifier::VIRTUAL)
       {
           result += "virtual ";
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
#endif // CSHMETHODUNIT_H
