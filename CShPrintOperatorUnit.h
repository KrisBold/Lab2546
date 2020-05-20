#ifndef CSHPRINTOPERATORUNIT_H
#define CSHPRINTOPERATORUNIT_H
#include "Unit.h"
#include "PrintOperatorUnit.h"
using namespace std;

class CShPrintOperatorUnit: public PrintOperatorUnit
{
public:
    explicit CShPrintOperatorUnit(const string& text): PrintOperatorUnit(text) {};

    string compile(unsigned int level = 0) const
    {
        return generateShift(level) + "System.Console.WriteLine( \"" + m_text + "\" );\n";
    }
};
#endif // CSHPRINTOPERATORUNIT_H
