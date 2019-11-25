#ifndef STACK_H
#define STACK_H

template <class Type>
class Stack
{

public:
	virtual bool isEmpty() const = 0;

    virtual int size() const = 0;

    virtual Type top() const = 0;

    virtual Type pop() = 0;
     
    virtual void push(Type e) = 0;

};
#endif