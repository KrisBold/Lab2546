#ifndef UNIT_H
#define UNIT_H
#include <memory>
using namespace std;

class Unit
{
public:
    using Flags = unsigned int;
public:
    virtual ~Unit() = default;

    virtual void add(shared_ptr<Unit>, Flags = 0)
    {
        throw runtime_error("Not supported");
    }

    virtual string compile(unsigned int level = 0) const = 0;

protected:
    virtual string generateShift(unsigned int level) const
    {
        static const auto DEFAULT_SHIFT = '\t';
        string result;
        for(unsigned int i = 0; i < level; ++i)
        {
            result += DEFAULT_SHIFT;
        }
        return result;
    }
};
#endif // UNIT_H
