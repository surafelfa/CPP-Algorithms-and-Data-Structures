#ifndef BUSLINE_H
#define BUSLINE_H
#include <bits/stdc++.h>

template <class T>
struct Node{
		T data;
		Node<T> * prev=NULL;
		Node<T> * next=NULL;
		Node<T>(T val, Node<T>* prv=NULL, Node<T>* nxt=NULL) {
            data = val;
            next = nxt;
            prev =prv;
        }
};
template <class T,class T2=T> class List;
template <class T,class T2>
class List
{
    public:
        List();
        virtual ~List();
        List(List& old);
        List(int (*compare)(T dataOne, T2 dataTwo),int (*compare2)(T dataOne, T2 dataTwo));
        typedef int (*fptr)(T dataOne, T2 dataTwo);
        fptr getComFun()
        {
            return pcompare;
        }
        typedef int (*fptr2)(T dataOne, T2 dataTwo);
        fptr2 getComFun2()
        {
            return pcompare2;
        }
        bool isEmpty()
        {
            return front == NULL;
        }
        Node<T>* getFront()
        {
            return front;
        }
        Node<T>* getBack()
        {
            return back;
        };
        int getNbElements()
        {
            return nbElements;
        }
        void ground();
        List<T,T2>& operator = (List& other);
        operator [](int index);
        bool insert(T newData);
		bool insertFirst(T data);
		bool insertBack(T data);
		bool insertBefore(T data, Node<T>* before);
		bool insertAfter(T data, Node<T>* after);
		bool remove(T targetData);
		bool removeFirst();
		bool removeLast();
	 	bool removeBefore(Node<T>* before);
		bool removeAfter(Node<T> * after);
		Node<T>* find(T data);
		Node<T> * findById(T target);
		bool update(T oldData, T newData);
		void destroy();
		void display();
		bool insertRangeBefore(Node<T>* before, List<T>& range);
		bool insertRangeAfter(Node<T>* after, List<T>& range);
		bool removeRange(Node<T>* rangeFirst, Node<T>* rangeLast);
        List* getSublist(Node<T>* rangeFirst, Node<T>* rangeLast, bool remove=false);

    private:
        Node<T>* front;
		Node<T>* back;
		int nbElements;
        int (*pcompare)(T dataOne, T2 dataTwo);
        int (*pcompare2)(T dataOne, T2 dataTwo);
        int compareDefault(T data1, T2 data2);
        int compare(T data1, T2 data2);
        int compareById(T data1, T2 data2);
        void insertNode(Node<T>* p, Node<T>* prev);
        Node<T>* deleteNode(Node<T>* prev);
        Node<T>* insertionSlot(Node<T>* p);
        bool nodeToDelete(T  targetData, Node<T>* & prev);
        bool check(T target1, T target2, Node<T>* address1, Node<T>* &address2, int &count);
};

#endif // BUSLINE_H
