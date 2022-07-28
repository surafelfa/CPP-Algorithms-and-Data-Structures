#include <iostream>
#include "BaseArray.h"
///Name: Surafel Fantu ID: VN2703
using namespace std;

template <class T>
bool BaseArray<T>::resize(int newCapacity)
{
    int size=capacity + newCapacity;

    Node<T>* tempBase = new (nothrow) Node<T>[size];
    if(tempBase)
    {
        for(int i = 0; i < capacity; i++)
        {
            tempBase[i].data=base[i].data;
            tempBase[i].next=base[i].next;
        }
        for(int i = capacity; i <= size -2; i++)
            tempBase[i].next = i+1;

        tempBase[size-1].next = NIL;
        delete base;
        base = tempBase;
        avail = capacity;
        capacity = size;
        return true;
        }
    return false;
}
template <class T>
int BaseArray<T>::getNode()
{
    int p=NIL;
    if(avail!=NIL)
    {
        p=avail;
        avail=base[p].next;
    }
    return p;
}
template <class T>
void BaseArray<T>::returnNode(int p)
{
    base[p].next=avail;
    avail=p;
}
template <class T>
void BaseArray<T>::returnList(int listHead, int listTail)//returns all nodes in a linked list
{
    //assignment
    base[listTail].next=avail;
    avail=listHead;
}
template <class T>
bool BaseArray<T>::create(int n)//initialize the base array
{
    base = new (nothrow) Node<T>[n];
    if(base)
    {
        capacity=n;
        for(int i=0;i<=n-2;i++)
            base[i].next=i+1;
        base[n-1].next=NIL;
        avail=0;
        return true;
    }
    return false;
}










