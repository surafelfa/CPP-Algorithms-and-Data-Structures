#include "Stack.h"
template <class T>
Stack<T>::Stack()
{
    top=NULL;
	count=0;
}
template <class T>
Stack<T>::~Stack()
{
    Node<T>* temp = top;
    while(temp)
    {
        top = top->next;
        delete temp;
        temp = top;
    }
    count = 0;
}
template <class T>
Stack<T>::Stack(Stack<T>& s)
{
	Stack<T> temp;
	while(!s.isEmpty())
    {
		temp.push(s.pop());
	}
	while(!temp.isEmpty())
	{
		Node<T>* data=temp.pop();
		s.push(data);
		this->push(data);
	}
}
template <class T>
Stack<T>& Stack<T>::operator=(Stack<T> &s){
	clear();
	Stack<T> temp;
	while(!s.isEmpty()){
		temp.push(s.pop());
	}
	while(!temp.isEmpty()){
		Node<T>* data=temp.pop();
		s.push(data);
		push(data);
	}
	return *this;
}
template <class T>
bool Stack<T>::push(T item) {
    Node<T>* p = new Node<T>();
	if(p)
    {
        p->data = item;
        p->next = top;
        top = p;
		count++;
		return true;
	}
	return false;
}
template <class T>
T Stack<T>::peek() {
    if(isEmpty())
        throw EmptyStackException("Stack is empty!!!");
	return top->data;
}

template <class T>
T Stack<T>::pop() {
	Node<T>* p;
 	if (isEmpty())
		throw EmptyStackException("Stack is empty!!!");
	T item = top->data;
	p = top;
	top = top->next;
	delete p;
	return item;
}
template <class T>
void Stack<T>::clear()
{
    Node<T>* temp = top;
    while(temp)
    {
        top = top->next;
        delete temp;
        temp = top;
    }
    count = 0;
};
template <class T>
T Stack<T>::reverse()
{
    if(!isEmpty())
    {
        T item = peek();
        pop();
        reverse();
        insertAtBottom(item);
    }
};
template <class T>
T Stack<T>::insertAtBottom(T item)
{
    if(isEmpty())
        push(item);
    else
    {
        T a = peek();
        pop();
        insertAtBottom(item);
        push(a);
    }
}

