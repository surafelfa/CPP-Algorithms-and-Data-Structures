#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "BaseArray.h"
///Name: Surafel Fantu ID: VN2703

template <class T, class G=T> class LinkedList;

template <class T, class G>
class LinkedList
{
    public:
        LinkedList(BaseArray<T>* base);
        LinkedList(BaseArray<T>* base,bool sorted);
        //copy constructor
        LinkedList(LinkedList* other);
        LinkedList(BaseArray<T> *base,int (*compare)(T dataOne, G dataTwo),bool sorted);
        virtual ~ LinkedList();
        int getHead()
        {
            return head;
        }
        int getTail()
        {
            return tail;
        };
        int getSorted()
        {
            return  sorted;
        }
        BaseArray<T>* getBaseArray()
        {
            return baseArray;
        };
        bool isEmpty()
        {
            return head == NIL;
        };  //returns true if list is empty
        void operator = (LinkedList* other);
        T operator [](int index);
        bool insert(T newData);
        bool remove(T targetData);
        int findNode(T target);
        int count();
        void display();
        void update(T userInput);
        void clear();

    private:
        BaseArray<T>* baseArray;
        int (*pcompare)(T dataOne, G dataTwo);
        int compareDefault(T data, G target);
        int compare(T data, G target);
        int head;
        int tail;
        int numberOfElements=0;
        bool sorted;

        void insertNode(int p, int prev);
        int deleteNode(int prev);
        int insertionSlot(int p);
        bool nodeToDelete(T  targetData, int & prev);

};

#endif // LINKEDLIST_H
