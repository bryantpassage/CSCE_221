#ifndef ABSTRACT_STACK_H
#define ABSTRACT_STACK_H

template <class Type>
class AbstractStack
{
protected:
    int sizeIndex; // current array size
public:
    AbstractStack(void):
        sizeIndex(0) {}

    ~AbstractStack(void) {}

    bool isEmpty(void) 
    {
        if(sizeIndex == 0)
            return true;
        return false;
    }

    int size(void) { return sizeIndex; }

    Type top() {}

    Type pop() {}

    void push(Type e) {}
};

#endif