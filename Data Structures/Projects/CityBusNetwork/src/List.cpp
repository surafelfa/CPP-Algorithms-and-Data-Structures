#include "List.h"

using namespace std;
/*template <class T,class T2>

int List<T,T2>::compareDefault(T data1, T2 data2){
    if(data1 > data2)
        return 1;
    else if(data1 == data2)
        return 0;
    else
        return -1;

}*/
template <class T,class T2>
int List<T,T2>::compare(T data1, T2 data2){
    if(pcompare)
        return pcompare(data1, data2);
    //else
      //  return compareDefault(data1,data2);
}
template <class T,class T2>
int List<T,T2>::compareById(T data1, T2 data2){
    if(pcompare2)
        return pcompare2(data1, data2);
}
template <class T,class T2>
List<T,T2>::List()
{
    front= back = NULL;
    pcompare = nullptr;
    nbElements=0;
}
template <class T,class T2>
//std::function<int(T,T)> function
List<T,T2>::List(int (*compare)(T dataOne, T2 dataTwo), int (*compare2)(T dataOne, T2 dataTwo))
{
    front= back = NULL;
    nbElements=0;
    pcompare = compare;//getComFun();
    pcompare2 =compare2;
}
template <class T,class T2>
List<T,T2>::~List()
{
    destroy();
}
template <class T,class T2>
List<T,T2>::List(List& old)
{
    if (old.getFront() == NULL)
    {
        front = back = NULL;
    }
    else
    {
        front = back = new Node<T>(old.getFront()->data);
        Node<T>* current = front;
        Node<T>* oldFront = old.getFront();
        Node<T>* currentObj = oldFront;
        while (currentObj->next != NULL) {
            current->next =new Node<T>(currentObj->next->data,currentObj);
            back = new Node<T>(currentObj->next->data,currentObj);
            currentObj = currentObj->next;
            current = current->next;
        }
    }
    nbElements = old.getNbElements();
    pcompare=getComFun();
    pcompare2 = getComFun2;
};
template <class T,class T2>
List<T,T2>& List<T,T2>::operator =(List &old)
{
    ground();
    if (old.getFront() == NULL)
    {
        front = back = NULL;
    }
    else
    {
        front = back = new Node<T>(old.getFront()->data);
        Node<T>* current = front;
        Node<T>* oldFront = old.getFront();
        Node<T>* currentObj = oldFront;
        while (currentObj->next != NULL) {
            current->next =new Node<T>(currentObj->next->data,currentObj);
            back = new Node<T>(currentObj->next->data,currentObj);
            currentObj = currentObj->next;
            current = current->next;
        }
    }
    nbElements = old.getNbElements();
    pcompare=getComFun();
    pcompare2 = getComFun2;
    return *this;
}
template <class T,class T2>
List<T,T2>::operator [](int index)
{
    if(index < nbElements)
    {
        Node<T>* nextNode = front;
        for(int i=0; i < index; i++)
        {
            nextNode = nextNode->next;
        }
        return nextNode->data;
    }
    else
    {
        cout<<"Index out of bound: ";
        return NULL;
    }
}
template <class T,class T2>
void List<T,T2>::ground()
{
    front = back = NULL;
    nbElements=0;
}
template <class T,class T2>
void List<T,T2>::insertNode(Node<T>* p, Node<T>* prev) {
    //insert a new node pointed by p after the node pointed by prev
	if(front == NULL){
		p->next = NULL;
		p->prev = NULL;
		front = back = p;
	}else if (prev == NULL) {
		p->next = front;
		p->prev = NULL;
		front->prev = p;
		front = p;
	}else {
		p->next = prev->next;
		p->prev = prev;
		prev->next = p;
		if(prev == back)
            back = p;
	}
}
template <class T,class T2>
Node<T>* List<T,T2>::insertionSlot(Node<T>* p)
{
    //Return the index to the preceding element after which node p is to be inserted.
    bool found = false;
    Node<T>* prev = NULL, *tempFront;
    tempFront = front;
    while (tempFront != NULL && !found)
    {
        //tempHead->data < p->data
        if (compare(tempFront->data,p->data) == -1)
        {
            prev = tempFront;
            tempFront = tempFront->next;
        }
        else
            found = true;
    }
    return prev;
};
template <class T,class T2>
Node<T>* List<T,T2>::deleteNode(Node<T>* prev)
{
    Node<T>* p;
    // Delete the node preceded by a node pointed by prev
    // If prev is NULL, then delete the node pointed by the front
    if (front == back)
    {
        p = front;
        front = back = NULL;
    }else if (prev == NULL)
    {
        p = front;
        front = front->next;
        p->next->prev = NULL;
    }else
    {
        p = prev->next;
        if(p->next != NULL)
            p->next->prev = prev;
        if(prev->next == back)
            back = prev;
        prev->next = p->next;
    }
    return p;
};
template <class T,class T2>
bool List<T,T2>::nodeToDelete(T targetData, Node<T>* & prev)
{
    /* Searches for a node that contains “targetData” to be deleted. If such a node
    exists, it returns the index of preceding node in prev and return true ; if does not,
    it returns false.*/
    bool found = false;
    Node<T>* newFront = front;
    prev = NULL;
    while (!found && newFront != NULL) {
        if (compareById(newFront->data, targetData) == false){
            //if(compare(newFront->data,targetData) == 1){
              //  return false;
            //}
            prev = newFront;
            newFront = newFront->next;
        }
        else {
            found = true;
        }
    }
    return found;
};
template <class T,class T2>
bool List<T,T2>::insert(T newData)
{
    Node<T>* p = NULL;
    Node<T>*prev = NULL;
    p = new (nothrow) Node<T>(newData);
    if(p){
        prev = insertionSlot(p);
    }
    else{
        return false;//new throw NoMemoryException("There is no enough memory!!!");
    }
    insertNode(p, prev);
    nbElements++;
    return true;
};
template <class T, class T2>
bool List<T,T2>::insertFirst(T newData)
{
    Node<T>* p = NULL;
    p = new Node<T>(newData);
    if (p != NULL)
    {
        insertNode(p,NULL);
        nbElements++;
        return true; //success
    }
    return false; //failed
};
template <class T,class T2>
bool List<T,T2>::insertBack(T newData)
{
    Node<T>* p = NULL;
    p = new Node<T>(newData);
    if (p != NULL)
    {
        insertNode(p,back);
        nbElements++;
        return true; //success
    }
    return false; //failed
};
template <class T,class T2>
bool List<T,T2>::insertBefore(T data, Node<T>* before)
{
    if(find(before->data))
    {
        Node<T>* p = NULL;
        p = new Node<T>(data);
        if (p != NULL)
        {
            insertNode(p,before->prev);
            nbElements++;
            return true; //success
        }
    }

    return false; //failed
}
template <class T,class T2>
bool List<T,T2>::insertAfter(T data, Node<T>* after)
{
    if(find(after->data))
    {
        Node<T>* p = NULL;
        p = new Node<T>(data);
        if (p != NULL)
        {
            insertNode(p,after);
            nbElements++;
            return true; //success
        }
    }

    return false; //failed
};
template <class T,class T2>
bool List<T,T2>::insertRangeBefore(Node<T>* before, List<T>& range)
{
    Node<T>* tempFrontRange = range.getFront();
    Node<T>* beforeNode = find(before->data);

    if(beforeNode)
    {
        Node<T>* beforeNodeAddress = beforeNode;
        Node<T>* tempBackRange = range.getBack();

        tempBackRange->next = beforeNodeAddress;
        tempFrontRange->prev = beforeNodeAddress->prev;
        if(beforeNodeAddress ->prev != NULL)
            beforeNodeAddress->prev->next = tempFrontRange;
        if(beforeNodeAddress->prev == NULL)
            front = tempFrontRange;
        beforeNodeAddress->prev = tempBackRange;
        nbElements += range.getNbElements();

        range.ground();
        return true;
    }
    return false;
};
template <class T,class T2>
bool List<T,T2>::insertRangeAfter(Node<T>* after, List<T> &range)
{
    Node<T>* tempFrontRange = range.getFront();
    Node<T>* afterNode = find(after->data);
    if(afterNode)
    {
        Node<T>* afterNodeAddress = afterNode;
        Node<T>* tempBackRange = range.getBack();

        tempBackRange->next = afterNodeAddress->next;
        tempFrontRange->prev = afterNodeAddress;
        if(afterNodeAddress->next != NULL)
            afterNodeAddress->next->prev = tempBackRange;
        afterNodeAddress->next = range.getFront();
        if(back == afterNodeAddress)
            back = tempBackRange;

        nbElements += range.getNbElements();
        range.ground();

        return true;
    }
    return false;
}
template <class T,class T2>
bool List<T,T2>::remove(T targetData)
{
    Node<T>* prev;
    if(nodeToDelete(targetData,prev))
    {
        delete deleteNode(prev);
        nbElements--;
        return true;
    }
    return false;
}
template <class T,class T2>
bool List<T,T2>::removeFirst()
{
    if(front != NULL)
    {
        delete deleteNode(NULL);
        nbElements--;
        return true;
    };
    return false;
}
template <class T,class T2>
bool List<T,T2>::removeLast()
{
    if(back != NULL)
    {
        delete deleteNode(back->prev);
        nbElements--;
        return true;
    };
    return false;
}
template <class T,class T2>
bool List<T,T2>::removeBefore(Node<T>* before)
{
    if(find(before->data))
    {
        if(before->prev != NULL)
        {
            delete deleteNode(before->prev->prev);
            nbElements--;
            return true;
        }
    }
    return false;
};
template <class T,class T2>
bool List<T,T2>::removeAfter(Node<T> * after)
{
    if(find(after->data))
    {
        if(after->next != NULL)
        {
            delete deleteNode(after);
            nbElements--;
            return true;
        }
    }
    return false;
};
template <class T,class T2>
bool List<T,T2>::removeRange(Node<T>* rangeFirst, Node<T>* rangeLast)
{
    int count=0;
    Node<T>* address1=NULL;
    Node<T>* address2;
    if(nodeToDelete(rangeFirst->data,address1) && check(rangeFirst->data, rangeLast->data, address1, address2, count))
    {
        Node<T>* tempAddress;
        (address1 == NULL)?tempAddress = front:tempAddress =address1->next;
        while(count > 0)
        {
            Node<T>* next = tempAddress->next;
            remove(tempAddress->data);
            tempAddress = next;
            count--;
        }
        return true;
    }
    return false;
};
template <class T,class T2>
bool List<T,T2>::check(T target1, T target2, Node<T>* address1, Node<T>* &address2, int &count)
{
    Node<T>* tempAddress;
    (address1 == NULL)?tempAddress = front:tempAddress =address1->next;
    bool found = false;
    if(tempAddress)
    {
        count=1;
        while(!found && tempAddress != NULL)
        {
            if(compare(tempAddress->data, target2) == 0)
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
template <class T,class T2>
List<T,T2>* List<T,T2>::getSublist(Node<T>* rangeFirst, Node<T>* rangeLast, bool remove)
{
    int count;
    Node<T>* address1 = NULL;
    Node<T>* address2;
    List<T> gottenRange;
    if(nodeToDelete(rangeFirst->data, address1) && check(rangeFirst->data,rangeLast,address1,address2,count))
    {
        bool success = true;
        Node<T>* tempAddress;
        (address1 ==NULL)?tempAddress = front:tempAddress =address1->next;
        while(tempAddress != address2 && success)
        {
            success = gottenRange.insert(tempAddress->data);
            tempAddress = tempAddress->next;
        }
        if(success)
        {
            if(remove)
                removeRange(rangeFirst,rangeLast);
            return &gottenRange;
        }
    }
    return NULL;
};
template <class T,class T2>
Node<T>* List<T,T2>::find(T target)
{
    Node<T>* tempFront = front;
    while(tempFront != NULL)
    {
        if(compare(tempFront->data, target) == 0)
            return tempFront;
        tempFront = tempFront->next;
    }
    return NULL;
};
template <class T,class T2>
Node<T>* List<T,T2>::findById(T target)
{
    Node<T>* tempFront = front;
    while(tempFront != NULL)
    {
        if(compareById(tempFront->data, target) == true)
            return tempFront;
        tempFront = tempFront->next;
    }
    return NULL;
};
template <class T,class T2>
bool List<T,T2>::update(T oldData, T newData)
{
    if(remove(oldData))
        if(insert(newData))
            return true;
    return false;
}
template <class T,class T2>
void List<T,T2>::display()
{
    Node<T>* next = front;
	int i=0;
	cout<<"\n\n\t\t\t"<<setw(20)<<left<<"Node address"<<setw(20)<<left<<"Linked list index"<<setw(20)<<left<<"Data";
	cout<<endl;
	while(next!=NULL) {

		cout<<"\t\t\t"<<setw(20)<<left<<next<<setw(20)<<left<<i<<setw(20)<<left<<next->data;
		next=next->next;
		cout<<endl;
		i++;
	}
    /**Node<T>*tempFront = front;
    cout<<endl;
    while (tempFront != NULL)
    {
        cout<< tempFront->data <<" ";
        tempFront = tempFront->next;
    }
    cout<<endl;*/
}
template <class T,class T2>
void List<T,T2>::destroy()
{
    /**while(front != NULL)
        remove(front->data);*/
    Node<T>* next = front;
	Node<T>* temp;
	while(next != NULL) {
		temp=next;
		next=next->next;
		delete temp;
	}
	front = back = NULL;
	nbElements=0;
}
