#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <stdexcept>

template<class T>
class DoubleLinkedList
{
public:
    DoubleLinkedList()
    {
        first=nullptr;
        last=nullptr;
        current=nullptr;
    }

    ~DoubleLinkedList()
    {
        reset();
        Item *toDel;
        while (hasNext())
        {
            toDel=current;
            current=current.next;
            delete toDel;
        }
    }

private:
    template<class T>
    class Item
    {
    public:
        Item(T* e) {element=e;}

    private:
        T *element;
        Item* next;
        Item *previous;

    public:
        T& get(){return element;}
    };

private:
    Item<T> first, last, current;

public:
    void add(T* e)
    {
        Item *item=new Item(e);
        if(first==nullptr)
        {
            first=item;
            last=item;
        }else
        {
            last.next=item;
            item->previous=last;
            last=item;
        }
        current=item;
    }

    bool hasNext()
    {
        return current!=nullptr;
    }

    T& next()
    {
        if(!hasNext())
            throw std::out_of_range("End of List");
        T* tmp=current.get();
        current=current.next;
        return tmp;
    }

    bool hasPrevious()
    {
        return current.previous!=nullptr;
    }

    T& previous()
    {
        if(!hasPrevious())
            throw std::out_of_range("Start of List");
        current=current.previous;
        return current.get();
    }

    T& remove()
    {
        T* tmp;
        Item* toDel;
        if(current==first || last==nullptr)
        {
            throw new NullReferenceException();
        }
        else if(first==last)
        {
            toDel=last;
            tmp= last.get();
            first=nullptr;
            last=nullptr;
            current=nullptr;
        }else if(current==nullptr)
        {
            toDel=last;
            tmp=last.get();
            last=last.previous;
            last.next=nullptr;
        }else
        {
            toDel=current.previous;
            tmp=toDel->get();
            toDel->previous->next=toDel->next;
            toDel->next->previous=toDel->previous;
        }
        delete toDel;
        return tmp;
    }

    void reset() {current=first;}
};
#endif // DOUBLELINKEDLIST_H
