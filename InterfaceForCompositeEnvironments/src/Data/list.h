#ifndef LIST_H
#define LIST_H

#include "dataassembly.h"

template<class T>
class List : DataAssembly<T>
{
public:
    List()
    {
        count=0;
        length=8;
        elements=new T[length];
    }

    ~List()
    {
        delete[] elements;
    }

private:
    T* elements;
    size_t count;
    size_t length;

public:
    virtual size_t Count(){return count;}

    virtual size_t Length(){return length;}

    virtual void add(T *e)
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
        T *tmp = elements[--count];
        return tmp;
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

#endif // LIST_H
