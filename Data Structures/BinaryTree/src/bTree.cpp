#include "bTree.h"
template<class T>
bTree<T>::bTree()
{
    baseArray = new (nothrow) T[100];
    if(baseArray){
        capacity = 100;
        maxIndex = -1;
        for(int i = 0 ; i < capacity; i++)
            baseArray[i]='\0';
    }
}
template<class T>
bTree<T>::bTree(int size)
{
    baseArray = new (nothrow) T[size];
    if(baseArray){
        capacity = size;
        maxIndex = -1;
        for(int i =0; i < capacity; i++)
            baseArray[i]='\0';
    }
}
template<class T>
bTree<T>::~bTree()
{
    delete[] baseArray;
}
template<class T>
bool bTree<T>::resize(int size){

    T *temp = new (nothrow) T[capacity +  size];
    if(temp){
        for(int i = 0; i <= maxIndex; i++){
            temp[i] = baseArray[i];
        }
        delete[] baseArray;
        baseArray = temp;
        this->capacity = capacity + size;
        return true;
    }
    return false;
}
template<class T>
void bTree<T>::clear(){
    for(int i =0 ; i <= maxIndex; i++)
            baseArray[i]='\0';
    maxIndex = -1;
}
template<class T>
void bTree<T>::root(T key){
    if(baseArray[0] != '\0'){
        cout << "The tree already has a root.\n";
        pause();
    }
    else baseArray[0] = key;
    if (maxIndex < 1)
        maxIndex = 0;
    cls();
}
template<class T>
void bTree<T>::set_left(T key, int parent){
    int exist = findData(key);
    if(exist == -1){
        int index = (parent*2)+1;
        if(baseArray[parent] == '\0'){
            cout << "\nCan't set the child at index " << index << " because no parent is found.\n";
            pause();
        }
        else if(index < capacity){
            baseArray[index] = key;
            if(maxIndex < index)
                maxIndex = index;
        }
        else{
            cout<<"Index exceeded the size of the base array\n";
            pause();
        }
    }else{
        cout << "Since the tree is treated as set, duplicated data could not be stored.\n";
        pause();
    }
}
template<class T>
void bTree<T>::set_right(T key, int parent){
    int exist = findData(key);
    if(exist == -1){
        int index = (parent*2)+2;
        if(baseArray[parent] == '\0'){
            cout << "\nCan't set the child at index " << index << " because no parent is found.\n";
            pause();
        }
        else if(index < capacity){
            baseArray[index] = key;
            if(maxIndex < index)
                maxIndex = index;
        }
        else{
            cout<<"Index exceeded the size of the base array\n";
            pause();
        }
    }
    else{
        cout << "Since the tree is treated as set, duplicated data could not be stored.\n";
        pause();
    }
}
template<class T>
void bTree<T>::print_tree(){
    cout << "\n\nDisplaying the tree...\n";
    cout << "Index " <<" Data";
    for (int i = 0; i <= maxIndex; i++){
        cout << "\n" << i << "        ";
        if(baseArray[i] != '\0')
            cout << baseArray[i];
        else
            cout << "-";
        cout <<" ";
    }
    cout << "\n\n\n";
}
template<class T>
void bTree<T>::printPreOrder(int index){
    if(baseArray[index] == '\0')
        return;
    int leftChild = (2 * index) + 1;
    int rightChild = (2 * index) + 2;
    cout << baseArray[index] << " ";
    printPreOrder(leftChild);
    printPreOrder(rightChild);
}
template<class T>
void bTree<T>::printPostOrder(int index){
    if(baseArray[index] == '\0')
        return;
    int leftChild = (2 * index) + 1;
    int rightChild = (2 * index) + 2;
    printPostOrder(leftChild);
    printPostOrder(rightChild);
    cout << baseArray[index] << " ";
}
template<class T>
void bTree<T>::printInOrder(int index){
    if(baseArray[index] == '\0')
        return;
    int leftChild = (2 * index) + 1;
    int rightChild = (2 * index) + 2;
    printInOrder(leftChild);
    cout << baseArray[index] << " ";
    printInOrder(rightChild);
}
template<class T>
int bTree<T>::findData(T ch){
    int index = -1;
    for (int i = 0; i <= maxIndex; i++)
        if(baseArray[i] == ch)
            index = i;
    return index;
}
template<class T>
bool bTree<T>::deleteData(T ch){
    int index;
    index = findData(ch);
    if(index == -1)
        return false;
    else{
        if(noChild(index)){
            baseArray[index] = NULL;
            if(index == maxIndex)
                maxIndex = maxIndex - 1;
            return true;
        }
        else{
            return false;
        }
    }
}
template<class T>
bool bTree<T>::noChild(int index){
    int leftchild = 2*index + 1;
    int rightchild = 2*index + 2;
    if(baseArray[leftchild] == NULL && baseArray[rightchild] == NULL)
        return true;
    return false;
}
