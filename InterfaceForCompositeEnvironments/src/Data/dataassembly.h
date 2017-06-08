#ifndef DATAASSEMBLY_H
#define DATAASSEMBLY_H

#include <cstddef>

template<class T>
class DataAssembly
{
public:
    DataAssembly();

    virtual size_t Length();
    virtual size_t Count();
    virtual void add(T*);
    virtual T& get();
    virtual T* getAll();

    virtual void convertTo(DataAssembly *target)
    {
        for(int i=0; i<Count(); i++)
            target->add(this->get());
    }

private:

    virtual T* convertLength()
    {
        T *tmp=getAll();
        T *elementsNew;
        if(Count()==Length())
        {
            elementsNew=new T[Length()*2];
        }else
        {
            elementsNew=new T[Count()];
        }
        for(int i=0; i<Count(); i++)
            elementsNew[i]=tmp[i];
        return elementsNew;
    }
};

#endif // DATAASSEMBLY_H
