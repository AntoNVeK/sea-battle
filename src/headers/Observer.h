#ifndef OBSERVER_H
#define OBSERVER_H

// Паттерн-Наблюдатель
class Observer
{

public:
    virtual ~Observer() {};

    virtual void accept() = 0;
};

#endif
