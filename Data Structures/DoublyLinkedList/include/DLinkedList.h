#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H
#include <iostream>
///Name: Surafel Fantu ID: VN2703
template <class T>
struct Node
{
    T data;
    Node<T> *next;
    Node<T> *prev;
    Node<T>(T val, Node<T>* prv=NULL, Node<T>* nxt=NULL) {
            data = val;
            next = nxt;
            prev =prv;
        }
};

template <class T, class G=T> class DLinkedList;
template <class T, class G>
class DLinkedList
{
    public:
        DLinkedList();
        DLinkedList(bool s);
        DLinkedList(int (*compare)(T dataOne, G dataTwo),bool s);
        //copy constructor
        DLinkedList(DLinkedList& other);
        virtual ~DLinkedList();
        bool isEmpty()
        {
            return head == NULL;
        }
        Node<T>* getHead()
        {
            return head;
        }
        Node<T>* getTail()
        {
            return tail;
        };
        int getSorted()
        {
            return  sorted;
        }
        int getNumberOfElements()
        {
            return numberOfElements;
        }
        typedef int (*fptr)(T dataOne, G dataTwo);
        fptr getComFun()
        {
            return pcompare;
        }
        void ground()
        {
            head=tail=NULL;
        }
        operator = (DLinkedList& other);
        operator [](int index);
        bool insert(T newData);
        bool remove(T targetData);
        Node<T> *findNode(T target);
        void display();
        void update(T userInput);
        void clear();
        void insertRangeBefore(T before, DLinkedList<T> &range);
        ///inserts range of nodes to list
        void insertRangeAfter(T after, DLinkedList<T> &range);
        //removes range of nodes from target1 to target2
        void removeRange(T target1,T target2);
        /*return range of node from list (either removing or copying)
        from target1 to target 2 if fails returns false*/
        DLinkedList<T>* getRange(T target1, T target2, bool remove=true);


    private:
        bool sorted;
        Node<T>* head;
        Node<T>* tail;
        int numberOfElements=0;
        int (*pcompare)(T dataOne, G dataTwo);
        int compareDefault(T data, G target);
        int compare(T data, G target);
        void insertNode(Node<T>* p, Node<T>* prev);
        Node<T>* deleteNode(Node<T>* prev);
        Node<T>* insertionSlot(Node<T>* p);
        bool nodeToDelete(T  targetData, Node<T>* & prev);
        bool check(T target1, T target2, Node<T>* address1, Node<T>* &address2, int &count);
};

#endif // DLINKEDLIST_H
