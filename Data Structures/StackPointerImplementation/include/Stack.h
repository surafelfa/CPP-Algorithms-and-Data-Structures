#ifndef STACK_H
#define STACK_H
#include <bits/stdc++.h>
#include "EmptyStackException.h"
template <class T>
struct Node{
    T data;
    Node<T>* next;
};
template <class T>
class Stack
{
    public:
        Stack();
        Stack(Stack &s);
        virtual ~Stack();
        bool isEmpty()
        {
            return top == NULL;
        }
		int getCount()
		{
		    return count;
		};
        bool push(T item);
        T pop();
        T peek();
		void clear();
		T reverse();
		T insertAtBottom(T item);
		Stack<T>& operator=(Stack<T> &s);

    private:
        Node<T>* top;
		int count;
};

#endif // STACK_H
