#ifndef BASEARRAY_H
#define BASEARRAY_H
#define NIL -1
///Name: Surafel Fantu ID: VN2703

template <class T>
struct Node
{
    T data;
    int next;
};
template <class T>
class BaseArray
{
    public:
        BaseArray()
        {
            create(100);
        }
        BaseArray(int capacity)
        {
            create(capacity);
        }
        virtual ~BaseArray()
        {
            delete base;
        }
        int getCapacity()
        {
            return capacity;
        }
        bool isFull()
        {
            return avail==NIL;
        }
        Node<T> * getBase()
        {
            return base;
        }
        bool resize(int newCapacity);
        int getNode();//a place where a new node is going to be inserted
        void returnNode(int p);
        void returnList(int listHead, int listTail);


    private:
        bool create(int n);
        Node<T>* base;
        int capacity;
        int avail;
};

#endif // BASEARRAY_H
