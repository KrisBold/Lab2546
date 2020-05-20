#ifndef JPRINTOPERATORUNIT_H
#define JPRINTOPERATORUNIT_H
#include "Unit.h"
#include "PrintOperatorUnit.h"
using namespace std;

class JPrintOperatorUnit: public PrintOperatorUnit {
public:
    explicit JPrintOperatorUnit(const string& text): PrintOperatorUnit(text) {};

    string compile(unsigned int level = 0) const
    {
        return generateShift(level) + "System.out.print( \"" + m_text + "\" );\n";
    }
};
#endif // JPRINTOPERATORUNIT_H
