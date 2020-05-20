#ifndef JCLASSUNIT_H
#define JCLASSUNIT_H
#include "Unit.h"
#include "MethodUnit.h"
#include "ClassUnit.h"
using namespace std;

class JClassUnit: public ClassUnit
{
public:
    explicit JClassUnit(const string& name): ClassUnit(name)
    {
        m_fields.resize(3);
    }

    void add(shared_ptr<Unit> unit, Unit::Flags flags)
    {
        int accessModifier = ClassUnit::PUBLIC;

        if(flags < 3)
        {
            accessModifier = flags;
        }
        m_fields[accessModifier].push_back(unit);
    }

    string compile(unsigned int level = 0) const
    {
        string result = "LANGUAGE JAVA:\n"+generateShift(level) + "class " + m_name + " {\n";
        for(size_t i = 0; i < m_fields.size(); ++i)
        {
            if(m_fields[i].empty())
            {
                continue;
            }
            for(const auto& f: m_fields[i])
            {
                result += generateShift(level + 1) + ClassUnit::ACCESS_MODIFIERS[i] + ' ' + f->compile(level + 1);
            }
            result += "\n";
        }
        result += generateShift(level) + "};\n";
        return result;
    }
};

#endif // JCLASSUNIT_H
