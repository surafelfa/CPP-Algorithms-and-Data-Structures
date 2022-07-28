#ifndef BTREE_H
#define BTREE_H
#include <iostream>
using namespace std;
template<class T>
class bTree
{
    public:
        bTree();
        bTree(int size);
        virtual ~bTree();
        void setMaxIndex(int maxIn){
            maxIndex = maxIn;
        };
        int getMaxIndex(){
            return maxIndex;
        };
        int getCapacity(){
            return capacity;
        }
        void cls(){
            system("cls");
        }; // clear screen
        void pause(){
            system("pause");
        }; // pause screen
        bool isEmpty(){
            return baseArray[0] == '\0';
        }
        bool isFull(){
            return ((maxIndex+1) == capacity);
        }
        bool resize(int size);
        void clear();
        void root(T key);
        void set_left(T key, int parent);
        void set_right(T key, int parent);
        void print_tree();
        //void print_realTree();
        void printPreOrder(int index);
        void printPostOrder(int index);
        void printInOrder(int index);
        int findData(T ch);
        bool deleteData(T ch);
        bool noChild(int index);

    private:
        T *baseArray;
        int capacity;
        int maxIndex;

};

#endif // BTREE_H
