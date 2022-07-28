#include "Stack.h"


template <class T>
Stack<T>::Stack()
{
    baseArray= new (nothrow) T[100];
 	if (!baseArray)
		throw NoMemoryException("No enough memory!!!");
	capacity=100;
	top=NIL;
	count=0;

}
template <class T>
Stack<T>::Stack(int capacity)
{
    baseArray= new (nothrow) T[capacity];
 	if (!baseArray)
		throw NoMemoryException("No enough memory!!!");
	this->capacity = capacity;
	top=-1;
	count=0;
}
template <class T>
Stack<T>::Stack(Stack<T>& s)
{
	capacity=s.getCapacity();
	Stack temp(s.count);
	while(!s.isEmpty())
    {
		temp.push(s.pop());
	}
	baseArray=new T[capacity];
	while(!temp.isEmpty())
	{
		T data=temp.pop();
		s.push(data);
		this->push(data);
	}
}
template <class T>
Stack<T>& Stack<T>::operator=(Stack<T> &s)
{
    this->clear();
	Stack<T> temp(s.count);
	while(!s.isEmpty())
    {
		temp.push(s.pop());
	}
	while(!temp.isEmpty())
	{
		T data=temp.pop();
		s.push(data);
		this->push(data);
	}
	return *this;
};
template <class T>
void Stack<T>::push(T item) {
	if(!isFull())
    {
		baseArray[++top]=item;
		count++;
		return;
	}
	throw NoMemoryException("Stack is full!!!");
}
template <class T>
T Stack<T>::peek() {
    if(isEmpty())
        throw EmptyStackException("Stack is empty!!!");
	return baseArray[top];
}

template <class T>
T Stack<T>::pop()
{
    if(isEmpty())
        throw EmptyStackException("Stack is empty!!!");
	T item = baseArray[top--];
	count--;
	return item;
}
template <class T>
bool Stack<T>::resize(int newCapacity)
{
	//capacity=s.capacity;
	Stack temp(this->count);
	while(!this->isEmpty())
    {
		temp.push(this->pop());
	}
	//setBaseArray(&temp);
	baseArray=new (nothrow) T[capacity + newCapacity];
	if(baseArray)
    {
        count = 0; top = NIL;
        capacity += newCapacity;
        while(!temp.isEmpty())
        {
            this->push(temp.pop());
        }
        return true;
    }
    return false;
};
template <class T>
void Stack<T>::clear()
{
    top = NIL;
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

