#ifndef STACK_H
#define STACK_H

#include <stdexcept>

#include "dataassembly.h"

template<class T>
class Stack : DataAssembly<T>
{
public:
    Stack()
    {
        elements=new T[8];
        length=8;
        count=0;
    }

    ~Stack()
    {
        delete[] elements;
    }

private:
    T *elements;
    size_t length;
    size_t count;

public:
    virtual size_t Length() {return length;}

    virtual size_t Count() {return count;}

    virtual void add(T* e)
    {
        if(count==length)
        {
            elements=DataAssembly::convertLength();
            length*=2;
        }
        elements[count++]=e;
    }

    virtual T& get()
    {
        if(count*2==length)
        {
            elements=DataAssembly::convertLength();
            length=count;
        }
        return elements[--count];
    }

    virtual T* getAll()
    {
        if(count==length)
            return elements;
        T* tmp=new T[count];
        for(int i=0; i<count; i++)
            tmp[i]=elements[i];
        return tmp;
    }
};

#endif // STACK_H
