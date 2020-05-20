#ifndef PRINTOPERATORUNIT_H
#define PRINTOPERATORUNIT_H
#include "Unit.h"
using namespace std;

class PrintOperatorUnit: public Unit
{
public:
    explicit PrintOperatorUnit(const string& text): m_text(text) {};

    virtual string compile(unsigned int level = 0) const = 0;

    virtual ~PrintOperatorUnit() {};

protected:
    string m_text;
};
#endif // PRINTOPERATORUNIT_H
