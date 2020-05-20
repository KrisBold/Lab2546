#ifndef CPPPRINTOPERATORUNIT_H
#define CPPPRINTOPERATORUNIT_H
#include "Unit.h"
#include "PrintOperatorUnit.h"

class CPPPrintOperatorUnit: public PrintOperatorUnit
{
public:
    explicit CPPPrintOperatorUnit(const std::string& text): PrintOperatorUnit(text) {};

    std::string compile(unsigned int level = 0) const
    {
        return generateShift(level) + "printf( \"" + m_text + "\" );\n";
    }
};

#endif // CPPPRINTOPERATORUNIT_H
