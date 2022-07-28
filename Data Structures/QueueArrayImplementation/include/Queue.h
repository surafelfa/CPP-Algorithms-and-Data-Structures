#ifndef QUEUE_H
#define QUEUE_H
#include <bits/stdc++.h>
const int NIL = -1;
template<class T>
class Queue
{
    public:
        Queue();
        Queue(int capacity);
        virtual ~Queue();
        Queue(Queue& other);
        Queue& operator=(Queue& other);
        bool isEmpty()
        {
            return front == rear;
        };
        bool isFull()
        {
            return ((rear + 1) % capacity) == front;
        };
		bool enqueue(T item);
		T dequeue(); //may throw exception
		T peekFront(); //may throw exception
		T peekRear(); //may throw exception
        int getCapacity()
        {
            return capacity;
        };
        int getFront()
        {
            return front;
        }
        int getRear()
        {
            return rear;
        }
        void display();
		void clear();
		void reverse();
		bool resize(int capacity);
    private:
        T * baseArray;
		int capacity;
		int front;
		int rear;

};

#endif // QUEUE_H
