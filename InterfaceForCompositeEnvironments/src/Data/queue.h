#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>

#include "dataassembly.h"

template<class T>
class Queue : DataAssembly<T>
{
public:
    Queue()
    {
        elements=new T[8];
        length=8;
        count=0;
    }

    ~Queue()
    {
        delete[] elements;
    }

private:
    T *elements;
    size_t length;
    size_t count;
    size_t off;

public:
    virtual size_t Length() {return length;}

    virtual size_t Count() {return count;}

    virtual void add(T* e)
    {
        if(count==length)
        {
            sortElements();
            elements=DataAssembly::convertLength();
            length*=2;
        }
        elements[count++]=e;
    }

    virtual T& get()
    {
        if(count*2==length)
        {
            sortElements();
            elements=DataAssembly::convertLength();
            length=count;
        }
        count--;
        return elements[(off++)%length];
    }

    virtual T* getAll()
    {
        return sortElements();
    }

    void sortElements()
    {
        T *tmp=new T[count];
        for(int i=0; i<count; i++)
            tmp[i]=elements[i+off];
        elements=new T[length];
        for(int i=0; i<count; i++)
            elements[i]=tmp[i];
        off=0;
        delete[] tmp;
    }
};

#endif // QUEUE_H
