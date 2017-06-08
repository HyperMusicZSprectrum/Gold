#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include <stdexcept>

template<class T>
class SingleLinkedList
{
public:
    SingleLinkedList()
    {
        first=nullptr;
        last=nullptr;
        current=nullptr;
    }

    ~SingleLinkedList()
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
        Item(T* e){element=e;}
    private:
        T *element;
        Item *next;
    public:
        T& get(){return element;}
    };

private:
    Item<T> first, last, current;

public:
    void add(T*)
    {
        Item *item= new Item(e);
        if(first==nullptr)
        {
            first=item;
            last=item;
        }else
        {
            last.next=item;
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
            throw std::out_of_range("End of List reached");
        T *tmp=current.get();
        current=current.next;
        return tmp;
    }

    T& remove()
    {
        Item* toDel;
        T* e;

        if(current==first || last==nullptr)
        {
            throw new NullReferenceException();
        }
        else if(first==last)
        {
            toDel=last;
            e= last.get();
            first=nullptr;
            last=nullptr;
            current=nullptr;
        }else if(current==nullptr)
        {
            toDel=last;
            Item *tmp = first;
            while (tmp->next!=last)
            {
                tmp=tmp->next;
            }
            tmp->Next(nullptr);
            e = last.get();
            last=tmp;
        }else
        {
            Item *tmp = first;
            while (tmp->next->next!=current)
            {
                tmp=tmp->next;
            }
            toDel=tmp->next;
            e=tmp->next->get();
            tmp->next=current;
        }
        delete toDel;
        return e;
    }

    void reset() {current=first;}
};

#endif // SINGLELINKEDLIST_H
