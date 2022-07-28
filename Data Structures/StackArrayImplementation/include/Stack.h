#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "EmptyStackException.h"
#include "NoMemoryException.h"
const int NIL = -1;

using namespace std;

template <class T>
class Stack
{
    public:
        Stack();
        Stack(int capacity);
        Stack(Stack &s);
        virtual ~Stack()
        {
            delete baseArray;
        };
        bool isFull()
        {
            return capacity == count;
        }
        bool isEmpty()
        {
            return top == NIL;
        }
        int getCapacity()
        {
            return capacity;
        };
		int getCount()
		{
		    return count;
		};
		void setBaseArray(T * base)
		{
		    baseArray = base;
		};
        void push(T item);
        T pop();
        T peek();
		bool resize(int capacity);
		void clear();
		T reverse();
		T insertAtBottom(T item);
		Stack<T>& operator=(Stack<T> &s);
    private:
        T * baseArray;
		int top;
		int capacity;
		int count;
};

#endif // STACK_H
