#include "../include/Queue.h"
#include "../include/EmptyQueueException.h"
#include "../include/NoMemoryException.h"
using namespace std;

template<class T>
Queue<T>::Queue()
{
    baseArray=new (nothrow) T[100];
	if(!baseArray)
		throw NoMemoryException("No enough memory!!!");
	capacity=100;
	rear = front = 99;

}
template<class T>
Queue<T>::Queue(int capacity)
{
    baseArray=new (nothrow) T[capacity];
	if(!baseArray)
		throw NoMemoryException("No enough memory!!!");
	this->capacity = capacity;
	rear = front = capacity-1;
}
template<class T>
Queue<T>::~Queue()
{
    delete[] baseArray;
    capacity = 0;
    //front = rear = NIL;
}
template<class T>
Queue<T>::Queue(Queue& other)
{
    capacity = other.getCapacity();
	Queue temp(capacity);
	while(!other.isEmpty())
    {
		temp.enqueue(other.dequeue());
	}
	baseArray=new (nothrow) T[capacity];
	if(baseArray){
        clear();
        while(!temp.isEmpty())
        {
            T data=temp.dequeue();
            other.enqueue(data);
            this->enqueue(data);
        }

	}
	else
        throw NoMemoryException("No enough memory!!!");
}
template<class T>
Queue<T>& Queue<T>::operator=(Queue& other)
{
    clear();
	Queue temp(capacity);
	while(!other.isEmpty())
    {
		temp.enqueue(other.dequeue());
	}
    while(!temp.isEmpty())
    {
        T data=temp.dequeue();
        other.enqueue(data);
        this->enqueue(data);
    }
    return *this;
}
template<class T>
bool Queue<T>::enqueue(T item)
{
    if (!isFull()) {
		rear = (rear + 1) % capacity;
		baseArray[rear] = item;
	   	return true;
	}else
		return false;
}
template<class T>
T Queue<T>::dequeue()
{
    if(isEmpty())
        throw EmptyQueueException("Empty queue exception!!!");
    int newFront = (front + 1) % capacity;
    T item = baseArray[newFront];
    if (newFront == rear)
        front = rear = capacity - 1;
    else
        front = newFront;
    return item;
}
template<class T>
T Queue<T>::peekFront()
{
    if(isEmpty())
        throw EmptyQueueException("Empty queue exception!!!");
    int realFront = (front + 1) % capacity;
    return baseArray[realFront];
};
template<class T>
T Queue<T>::peekRear()
{
    if(isEmpty())
        throw EmptyQueueException("Empty queue exception!!!");
    return baseArray[rear];
};
template<class T>
void Queue<T>::clear()
{
    front = rear = capacity -1;
};
template<class T>
void Queue<T>::reverse()
{
    stack<T> Stack;
    while(!isEmpty()){
        Stack.push(dequeue());
    }
    while(!Stack.empty()){
        enqueue(Stack.top());
        Stack.pop();
    }
};
template<class T>
bool Queue<T>::resize(int size)
{
    int newCapacity = this->capacity + size;
    Queue temp(capacity);
	while(!isEmpty())
    {
		temp.enqueue(dequeue());
	}
	delete[] baseArray;
	baseArray=new (nothrow) T[newCapacity];
	if(baseArray)
    {
        //clear();
        capacity = newCapacity;
        while(!temp.isEmpty())
        {
            this->enqueue(temp.dequeue());
        }
        return true;
    }
    return false;
};
template<class T>
void Queue<T>::display()
{
    if(!isEmpty()){
        int realFront = (front + 1) % capacity;
        cout/*<<"Front-> "<<realFront*/<<endl<<"Items-> ";
        for(int i = realFront; i != rear; i = (i + 1) % capacity)
            cout<<baseArray[i]<<", ";
        cout<<"and "<<baseArray[rear]<<endl/*<<"Rear-> "<<rear*/;
    }
}



