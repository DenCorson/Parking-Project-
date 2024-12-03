#ifndef OBSERVER_H
#define OBSERVER_H
#include <vector>
#include <algorithm>


class Observer {
public:
    virtual void update(const string& message) = 0;
    virtual ~Observer() {}
};

#endif


