#include "DLinkedList.h"
#include <iostream>
///Name: Surafel Fantu ID: VN2703

using namespace std;
template <class T, class G>
DLinkedList<T,G>::DLinkedList()
{
    sorted = false;
    head = NULL;
    tail = NULL;
    pcompare=NULL;
}
template <class T, class G>
DLinkedList<T,G>::DLinkedList(bool s)
{
    sorted = s;
    head = NULL;
    tail = NULL;
    pcompare=NULL;
}
template <class T, class G>
DLinkedList<T,G>::DLinkedList(int (*compare)(T dataOne, G dataTwo),bool s)
{
    head=tail=NULL;
    sorted=s;
    pcompare=compare;
};
template <class T, class G>
DLinkedList<T,G>::DLinkedList(DLinkedList& other)
{
    if (other.getHead() == NULL) {
        head = NULL;
        tail = NULL;
    }
    else {
        head = tail = new Node<T>(other.getHead()->data);
        Node<T>*current = head;
        Node<T>*otherHead = other.getHead();
        Node<T>*currentObj = otherHead;
        while (currentObj->next != NULL) {
            current->next =new Node<T>(currentObj->next->data,currentObj);
            tail = new Node<T>(currentObj->next->data,currentObj);
            currentObj = currentObj->next;
            current = current->next;
        }
    }
    sorted = other.getSorted();
    numberOfElements = other.getNumberOfElements();
    pcompare=getComFun();
    cout<<"copy constructor called\n";
};
template <class T, class G>
DLinkedList<T,G>::~DLinkedList()
{
    clear();
}
template <class T, class G>
DLinkedList<T,G>::operator =(DLinkedList &other)
{
    if (other.getHead() == NULL) {
        head = NULL;
        tail = NULL;
    }
    else {
        head = tail = new Node<T>(other.getHead()->data);
        Node<T>*current = head;
        Node<T>*otherHead = other.getHead();
        Node<T>*currentObj = otherHead;
        while (currentObj->next != NULL) {
            current->next =new Node<T>(currentObj->next->data,currentObj);
            tail = new Node<T>(currentObj->next->data,currentObj);
            currentObj = currentObj->next;
            current = current->next;
        }
    }
    sorted = other.getSorted();
    numberOfElements = other.getNumberOfElements();
    pcompare=getComFun();
    //cout<<"operator = is called\n";
}
template <class T, class G>
DLinkedList<T,G>::operator [](int index)
{
    if(index < numberOfElements)
    {
        Node<T>* nextNode = head;
        for(int i=0; i<index; i++)
        {
            nextNode=nextNode->next;
        }
        return nextNode->data;
    }
    else
    {
        cout<<"\nindex out of bound: ";
        return NULL;
    }
}
template <class T, class G>
void DLinkedList<T,G>::insertNode(Node<T> * p, Node<T> * prev) {
    //insert a new node pointed by p after the node pointed by prev
	if(head == NULL){
		p->next = NULL;
		p->prev = NULL;
		head = tail = p;
	}else if (prev == NULL) {
		p->next = head;
		p->prev = NULL;
		head->prev = p;
		head = p;
	}else {
		p->next = prev->next;
		p->prev = prev;
		prev->next = p;
		if(prev == tail)    tail = p;
	}
}
template <class T, class G>
Node<T>* DLinkedList<T,G>::insertionSlot(Node<T>*  p)
{
    //Return the index to the preceding element after which node p is to be inserted.
    bool found = false;
    Node<T>* prev = NULL, *tempHead;
    tempHead = head;
    while (tempHead != NULL && !found)
    {
        //tempHead->data < p->data
        if (compare(tempHead->data,p->data) == -1)
        {
            prev = tempHead;
            tempHead = tempHead->next;
        }
        else
            found = true;
    }
    return prev;
};
template <class T, class G>
Node<T>* DLinkedList<T,G>::deleteNode(Node<T>* prev)
{
    Node<T>* p;
    // Delete the node preceded by a node pointed by prev
    // If prev is NULL, then delete the node pointed by the head
    if (head == tail)
    {
        p = head;
        head = tail = NULL;
    }else if (prev == NULL)
    {
        p = head;
        head = head->next;
        p->next->prev = NULL;
    }else
    {
        p = prev->next;
        if(p->next != NULL)
            p->next->prev = prev;
        if(prev->next == tail) tail = prev;
        prev->next = p->next;
    }
    return p;
};
template <class T, class G>
bool DLinkedList<T,G>::nodeToDelete(T targetData, Node<T>* & prev)
{
    /* Searches for a node that contains “targetData” to be deleted. If such a node
    exists, it returns the index of preceding node in prev and return true ; if does not,
    it returns false.*/
    bool found = false;
    Node<T>* newHead=head;
    prev = NULL;
    while (!found && newHead != NULL) {
        //newHead->data != targetData
        if (compare(newHead->data,targetData) != 0){
            //newHead->data > targetData
            if(sorted && compare(newHead->data,targetData) == 1){
                return false;
                }
            prev = newHead;
            newHead = newHead->next;
        }
        else {
            found = true;
        }
    }
    return found;
};
template <class T, class G>
bool DLinkedList<T,G>::insert(T newData)
{
    Node<T>* p = NULL, *prev;
    p = new Node<T>(newData);
    if (p != NULL)
    {
        //p->data = newData;
        if(sorted){
            prev = insertionSlot(p);
            insertNode(p, prev);
        }
        else{
            insertNode(p,tail);
        }
        numberOfElements++;
        return true; //success
    }
    else
        return false; //failed
};
template <class T, class G>
bool DLinkedList<T,G>::remove(T targetData)
{
    Node<T>* prev;
    if(nodeToDelete(targetData,prev))
    {
        delete deleteNode(prev);
        numberOfElements--;
        return true;
    };
    return false;
}
template <class T, class G>
Node<T>* DLinkedList<T,G>::findNode(T target)
{
    Node<T>* tempHead=head;
    while(tempHead != NULL)
    {
        //tempHead->data == target
        if(compare(tempHead->data, target) == 0)
        {
            return tempHead;
        }
        tempHead = tempHead->next;
    }
    return NULL;
};
template <class T, class G>
void DLinkedList<T,G>::update(T userInput)
{
    if(remove(userInput))
    {
        cout<<"Updating "<<userInput<<" to: ";
        cin>>userInput;
        (insert(userInput))?cout<<"Updated successfully\n":cout<<"Failed\n";
    }
    else
        cout<<"Failed\n";
}
template <class T, class G>
void DLinkedList<T,G>::display()
{
    Node<T>*tempHead = head;
    cout<<endl;
    while (tempHead != NULL) {
        cout<< tempHead->data <<" ";
        tempHead = tempHead->next;
    }
    cout<<endl;
}
template <class T, class G>
int DLinkedList<T,G>::compareDefault(T data, G target){
    if(data>target)
        return 1;
    else if(data==target)
        return 0;
    else
        return -1;

}
template <class T, class G>
int DLinkedList<T,G>::compare(T data, G target){
    if(pcompare)
        return pcompare(data, target);
    else
        return compareDefault(data,target);
}
//removes nodes that found between target1 and target2 .i.e it does not include target1 and target2
template <class T, class G>
bool DLinkedList<T,G>::check(T target1, T target2, Node<T>* address1, Node<T>* &address2, int &count)
{
    Node<T>* tempAddress;
    (address1 == NULL)?tempAddress = head:tempAddress =address1->next;
    bool found = false;
    if(tempAddress)
    {
        count=1;
        while(!found && tempAddress != NULL)
        {
            if(compare(tempAddress->data, target2) == 0)//tempAddress->data == target2
            {
                address2 = tempAddress->next;
                found = true;
            }
            else
            {
                ++count;
                tempAddress = tempAddress->next;
            }
        }
    }
    return found;
}
template <class T, class G>
void DLinkedList<T,G>::removeRange(T target1,T target2)
{
    int count=0;
    Node<T>* address1=NULL;
    Node<T>* address2;
    if(nodeToDelete(target1,address1) && check(target1, target2, address1, address2, count))
    {
        Node<T>* tempAddress;
        (address1 == NULL)?tempAddress = head:tempAddress =address1->next;
        while(count > 0)
        {
            Node<T>* next = tempAddress->next;
            remove(tempAddress->data);
            tempAddress = next;
            count--;
        }
        return;
    }
    cout<<"Failed";
};
template <class T, class G>
void DLinkedList<T,G>::clear()
{
    while(head != NULL)
    {
        remove(head->data);
    }
}
template <class T, class G>
void DLinkedList<T,G>::insertRangeAfter(T after, DLinkedList<T> &range)
{
    Node<T>* tempHeadRange = range.getHead();
    bool success=false;
    Node<T>* afterNode = findNode(after);
    if(sorted && afterNode)
    {
        cout<<"Since the existing list is sorted, the given list is being inserted ";
        cout<<"\nat a proper place. .i.e the given list may not be inserted after: "<<after<<endl;
        while(tempHeadRange != NULL)
        {
            success = insert(tempHeadRange->data);
            tempHeadRange = tempHeadRange->next;
        }
    }
    else if(afterNode)
    {
        Node<T>* afterNodeAddress = afterNode;
        Node<T>* tempTailRange = range.getTail();

        tempTailRange->next = afterNodeAddress->next;
        tempHeadRange->prev = afterNodeAddress;
        if(afterNodeAddress->next != NULL)
            afterNodeAddress->next->prev = tempTailRange;
        afterNodeAddress->next = range.getHead();
        if(tail == afterNodeAddress)
            tail = tempTailRange;

        numberOfElements += range.getNumberOfElements();
        success = true;
    }
    if(success){
      cout<<"\nRange added successfully\n";
      range.ground();
      return;
    }
    cout<<"Failed\n";
}
template <class T, class G>
void DLinkedList<T,G>::insertRangeBefore(T before, DLinkedList<T>& range)
{
    Node<T>* tempHeadRange = range.getHead();
    bool success=false;
    Node<T>* beforeNode = findNode(before);
    if(sorted && beforeNode)
    {
        cout<<"Since the existing list is sorted, the given list is being inserted ";
        cout<<"\nat a proper place. .i.e the given list may not be inserted before: "<<before<<endl;
        while(tempHeadRange != NULL)
        {
            success = insert(tempHeadRange->data);
            tempHeadRange = tempHeadRange->next;
        }
    }
    else if(beforeNode)
    {
        Node<T>* beforeNodeAddress = beforeNode;
        Node<T>* tempTailRange = range.getTail();

        tempTailRange->next = beforeNodeAddress;
        tempHeadRange->prev = beforeNodeAddress->prev;
        if(beforeNodeAddress ->prev != NULL)
            beforeNodeAddress->prev->next = tempHeadRange;
        if(beforeNodeAddress->prev == NULL)
            head = tempHeadRange;
        beforeNodeAddress->prev = tempTailRange;
        numberOfElements += range.getNumberOfElements();
        success = true;
    }
    if(success){
      cout<<"\nRange added successfully\n";
      range.ground();
      return;
    }
    cout<<"Failed\n";
};
template <class T, class G>
DLinkedList<T>* DLinkedList<T,G>::getRange(T target1, T target2, bool remove)
{
    int count;
    Node<T>* address1 = NULL;
    Node<T>* address2;
    DLinkedList<T> gotRange(sorted);
    if(nodeToDelete(target1,address1) && check(target1,target2,address1,address2,count))
    {
        bool success = true;
        Node<T>* tempAddress;
        (address1 ==NULL)?tempAddress = head:tempAddress =address1->next;
        while(tempAddress != address2 && success)
        {
            success = gotRange.insert(tempAddress->data);
            tempAddress = tempAddress->next;
        }
        if(success)
        {
            if(remove)
                removeRange(target1,target2);
            return &gotRange;
        }
    }
    return NULL;
}
