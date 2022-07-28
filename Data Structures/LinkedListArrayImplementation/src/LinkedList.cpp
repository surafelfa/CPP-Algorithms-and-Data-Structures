#include <iostream>
#include "LinkedList.h"
#include "BaseArray.h"
///Name: Surafel Fantu ID: VN2703

using namespace std;


template <class T, class G>
LinkedList<T,G>::LinkedList(BaseArray<T>* base)
{
    baseArray=base;
    head=tail=NIL;
    this.sorted=false;
    this.pcompare=NULL;
};
template <class T, class G>
LinkedList<T,G>::LinkedList(BaseArray<T>* base,bool sorted)
{
    baseArray=base;
    head=tail=NIL;
    this->sorted=sorted;
    pcompare=NULL;
};
template <class T, class G>
//copy constructor
LinkedList<T,G>::LinkedList(LinkedList* other)
{
    head = other->getHead();
    tail = other->getTail();
    sorted = other->getSorted();
    numberOfElements = other->count();
    baseArray = other->getBaseArray();
    pcompare=NULL;
    cout<<"copy constructor is called"<<endl;

}
template <class T, class G>
LinkedList<T,G>::LinkedList(BaseArray<T> *base,int (*pcompare)(T dataOne, G dataTwo),bool sorted)
{
    baseArray=base;
    head=tail=NIL;
    this.sorted=sorted;
    this.pcompare=pcompare;
}
template <class T, class G>
LinkedList<T,G>::~LinkedList()
{
    baseArray->returnList(head,tail);
    head=tail=NIL;
};
template <class T, class G>
///overload assignment operator
void LinkedList<T,G>::operator = (LinkedList* other)
{
    head = other->getHead();
    tail = other->getTail();
    sorted = other->getSorted();
    numberOfElements = other->count();
    baseArray = other->getBaseArray();
    cout<<"operator =  called"<<endl;
}
template <class T, class G>
///overloading [] operator
T LinkedList<T,G>::operator [](int index)
{
    numberOfElements = count();
    if(index < numberOfElements)// baseArray->getCapacity())
    {
        int next = head;
        for(int i=0; i<index; i++)
        {
            next=baseArray->getBase()[next].next;
        }
        return baseArray->getBase()[next].data;
    }
    else
    {
        cout<<"\nindex out of bound: ";
        return NULL;
    }
}
template <class T, class G>
bool LinkedList<T,G>::insert(T newData)
{
    int p = NIL, prev;
    p=baseArray->getNode();
    if (p != NIL)
    {
        baseArray->getBase()[p].data = newData;
        if(sorted){
            prev = insertionSlot(p);
            insertNode(p, prev);
        }
        else{
            insertNode(p,tail);
        }
        return true; //success
    }else
        return false; //failed
};  //insert data
template <class T, class G>
bool LinkedList<T,G>::remove(T targetData)
{
    int prev;
    if(nodeToDelete(targetData,prev))
    {
        baseArray->returnNode(deleteNode(prev));
        return true;
    };
    return false;

};  //remove targetData
template <class T, class G>
int LinkedList<T,G>::findNode(T target)
{
    int i=0;
    numberOfElements=count();
    int tempHead=head;
    while(i < numberOfElements)
    {
        if(compare(baseArray->getBase()[tempHead].data, target) == 0)
        {
            return tempHead;
        }
        tempHead = baseArray->getBase()[tempHead].next;
        i++;
    }
    return -1;
}; //returns reference to the node
template <class T, class G>
int LinkedList<T,G>::count()
{
    numberOfElements=0;
    int tempHead=head;
    while(tempHead != NIL) //&& baseArray->getBase()[i].next!=NIL)
    {
        numberOfElements++;
        tempHead = baseArray->getBase()[tempHead].next;
    }
    return numberOfElements;
};//no of element
template <class T, class G>
void LinkedList<T,G>::display()
{
    int n=count();
    for(int i=head;n>0;n--)
    {
        cout<<baseArray->getBase()[i].data<<"  ";
        i=baseArray->getBase()[i].next;
    }
}
template <class T, class G>
void LinkedList<T,G>::update(T userInput)
{
    //int index = findNode(userInput);
    if(remove(userInput))
    {
        cout<<"Updating "<<userInput<<" to: ";
        cin>>userInput;
        (insert(userInput))?cout<<"Updated successfully\n":cout<<"Failed\n";
        //baseArray->getBase()[index].data=userInput;
    }
    else
        cout<<"Failed\n";
}
template <class T, class G>
void LinkedList<T,G>::clear()
{
    baseArray->returnList(head,tail);
    head=tail=NIL;
};//truncate the list to empty
template <class T, class G>
void LinkedList<T,G>::insertNode(int p, int prev)
{
    // insert a new node pointed by p after the node pointed by prev
    if(head == NIL)
    {
        baseArray->getBase()[p].next=NIL;
        head=tail=p;
    }else if(prev == NIL)
    {
        baseArray->getBase()[p].next = head;
        head = p;
    }else
    {
        baseArray->getBase()[p].next = baseArray->getBase()[prev].next;
        baseArray->getBase()[prev].next = p;
        if(prev == tail)    tail=p;
    }

};//insert a prepared node
template <class T, class G>
int LinkedList<T,G>::deleteNode(int prev)
{
    int p;
    // Delete the node preceded by a node pointed by prev
    // If prev is -1, then delete the node pointed by the head
    if (head == tail)
    {
        p=head;
        head=tail=NIL;
    }else if (prev == NIL)
    {
        p= head;
        head = baseArray->getBase()[head].next;
    }else
    {
        p=baseArray->getBase()[prev].next;
        baseArray->getBase()[prev].next = baseArray->getBase()[p].next;
        if(baseArray->getBase()[prev].next == tail) tail=prev;
    }
    return p;
}; //remove node
template <class T, class G>
int LinkedList<T,G>::insertionSlot(int p)
{
    //Return the index to the preceding element after which node p is to be inserted.
    int found, prev = NIL, tempHead;
    found = 0; // False
    tempHead=head;
    while (tempHead != NIL && !found)
    {
        if (compare(baseArray->getBase()[tempHead].data,baseArray->getBase()[p].data) == -1)
        {
            prev = tempHead;
            tempHead = baseArray->getBase()[tempHead].next;
        }
        else
            found = 1; // True
    }
    return (prev);
};//it finds after which to insert
template <class T, class G>
bool LinkedList<T,G>::nodeToDelete(T  targetData, int & prev)
{
    /* Searches for a node that contains “targetData” to be deleted. If such a node
    exists, it returns the index of preceding node in prev and return true ; if does not,
    it returns false.*/
    int found,newHead=head;
    prev = NIL;
    found =false; // False
    while (!found && newHead != NIL) {
        if (compare(baseArray->getBase()[newHead].data,targetData) != 0){
            if(sorted && compare(baseArray->getBase()[newHead].data,targetData) == 1){
                return false;
                }
            prev = newHead;
            newHead = baseArray->getBase()[newHead].next;
        }else {
            found = true;
            }
    }
    return found;
};

template <class T, class G>
int LinkedList<T,G>::compareDefault(T data, G target){
    if(data>target)
        return 1;
    else if(data==target)
        return 0;
    else
        return -1;

}
template <class T, class G>
int LinkedList<T,G>::compare(T data, G target){
    if(pcompare)
        return pcompare(data, target);
    else
        return compareDefault(data,target);

}

