#include <iostream>

using namespace std;

bool xIsInTheMatrix(int a[][4], int t)
{
    int i = 0; int j = 3;// a.length - 1;
    while (i <= 3/* a.length - 1 */&& j >= 0)
    {
        if (a[i][j] == t)
            return true;
        else if (a[i][j] < t)
        {
            cout<<a[i][j]<<endl;
            i++;
        }
            //i++;
        else
        {
            cout<<a[i][j]<<endl;
            j--;
        }
            //j--;
    }
        return false;
}
template <class T>
void swap(T db[],int indexOne,int indexTwo){
    T temp;
    temp=db[indexOne];
    db[indexOne]=db[indexTwo];
    db[indexTwo]=temp;
}
template<class T >
bool linearSearch(T db[],T sk,int size){
    bool found =false;
    int count=0;
    while(count<size&&!found){
        if(db[count]==sk){
            found=true;
        }
        count++;
    }
    return found;
}
template<class T >
bool binarySearch(T db[],T sk,int size){
    bool found =false;
    int first=0, last=size-1,mid;
    while(!found&&first<=last){
        mid=(first+last)/2;
        if(db[mid]==sk) found = true;
        else if (db[mid]>sk)last=mid-1;
        else first=mid+1;
    }
    return found;
}
template<class T >
void bubbleUpsort(T db[],int size){
    int lastIndex=size-1;
    for(int i=0; i<lastIndex;i++){
        for(int j=lastIndex;j>=i;j--){
            if(db[j]<db[j-1]){
                swap(db,j,j-1);
            }
        }
    }
}
template<class T >
void bubbleUpsortEx(T db[],int size){
    T temp;
    bool swapped=true;
    int lastIndex=size-1;
    for(int i=0; i<lastIndex&&swapped;i++){
        swapped=false;
        for(int j=lastIndex;j>=i;j--){
            if(db[j]<db[j-1]){
                swap(db,j,j-1);
                swapped=true;
            }
        }
    }
}
/**Provide an alternative bubble sort algorithm that pushes
    the bigger elements downward.*/
template <typename T>
void bubbleUpsortEx2(T *db)
{
    T temp;
    for(int i=1;i<7;i++){
        for (int j=6;j>=i;j--){
            if(db[j]>db[j+1]){
                temp=db[j];
                db[j]=db[j-1];
                db[j-1]=temp;
            }

        }
        for (int k=0;k<7;k++)
            cout<<db[k]<<"  ";
        cout<<endl;
    }
}
template <class T>
void selectionSort(T db[],int size){
    int position, minPos,innerPos;
    T temp;
    for(position=0; position<size-1;position++){
        minPos=position;
        innerPos=position+1;
        for (;innerPos<size;innerPos++){
            if(db[innerPos]<db[minPos]){
                minPos=innerPos;
            }
        }
        swap(db,position,minPos);
    }
}

template <class T>
void selectionSortEx(T db[],int size){
    int position, minPos,innerPos;
    T temp;
    bool assignment=true;
    for(position=0; position<size-1&&assignment;position++){
        assignment=false;
        minPos=position;
        innerPos=position+1;
        for (;innerPos<size;innerPos++){
            if(db[innerPos]<db[minPos]){
                minPos=innerPos;
                assignment=true;
            }
        }
        swap(db,position,minPos);
    }
}
/**Provide an alternative selection sort algorithm that places
    the larger elements rather than the smaller elements.*/
template <class T>
void selectionSortEx2(T db[],int size){
    int position, maxPos,innerPos;
    for(position=size-1; position>0;position--){
        maxPos=position;
        innerPos=position-1;
        for (;innerPos>=0;innerPos--){
            if(db[innerPos]>db[maxPos]){
                maxPos=innerPos;
            }
        }
        swap(db,position,maxPos);
        for (int k=0;k<7;k++)
            cout<<db[k]<<"  ";
        cout<<endl;
    }
}
template <class T>
void insertionSort(T db[],int size){
    T value;
    int tobe;
    for(int inserted=1;inserted<size;inserted++){
        value=db[inserted];
        tobe=inserted;
        for(;tobe>0&&value<db[tobe-1];tobe--){
            db[tobe]=db[tobe-1];
        }
        db[tobe]=value;
    }
}
/**16.Modify insertion sort so that it uses Binary search to locate the position within the first i -1 elements
of the array into which element i should be inserted. How would using such Binary search affect the Big-Oh for Insertion Sort?*/
int binarySearchRecursively(int db[],int sk,int first,int last){
    int mid;
    if(last<=first)
        return (sk>db[first])?(first+1):first;
    mid=(first+last)/2;
    if(sk == db[mid])
        return mid+1;
    if(sk > db[mid])
        return binarySearchRecursively(db, sk, mid+1, last);
    return binarySearchRecursively(db, sk, first, mid-1);
}
void insertionSortEx(int db[], int n){
    int i, location, j, sk;

    for (i = 1; i < n; i++)
    {
        sk = db[i];
        j = i - 1;
        location = binarySearchRecursively(db, sk, 0, j);
        while (j >= location)
        {
            db[j+1] = db[j];
            j--;
        }
        db[j+1] = sk;
    }
    /**In insertion sort, it takes O(n^2) comparisons in worst case; however, it can be
    can reduced to O(log n) by using binary search. Since the series of shifts are required
    for each insertion, it has running time of O(n2). So, modifying insertion sort using
    binary search does affect its running time.*/

}
/**
Provide an alternative insertion sort algorithm that swaps the
key with the element to the right (rather than shifting the
elements) until no more swapping is possible or until the key
reaches the left most position.
*/
void insertionSortEx2(int* V,int size)
{
    int N = size;
    int i, j, key;

    for (i = 1; i < N; i++) {
        j = i;

        // Insert V[i] into list 0..i-1
        while (j > 0 and V[j] < V[j - 1]) {

            // Swap V[j] and V[j-1]
            swap(V[j], V[j - 1]);

            // Decrement j by 1
            j --;
        }
    }
}
/**Provide an alternative insertion sort algorithm that inserts
    an element from the left into an already “relatively sorted”
    segment on the right.*/
void insertionSortEx3(int* db,int size){
    int value,tobe;
    for(int nextElement=size-1;nextElement>=0;nextElement--)
    {
        value=db[nextElement];//2
        tobe=nextElement;
        for(;tobe<6 && value>db[tobe+1];tobe++)
        {
            db[tobe]=db[tobe+1];
        }
        db[tobe]=value;
    }
    for (int i=0;i<7;i++)
    {
        cout<<db[i]<<"##";
    }
}
/**18.	Design algorithm to sort a two dimensional array A[n][n] (all elements in a row is sorted and
//all the elements in the ith row are less than the elements in the ith +1 row ) using Selection Sort.
//And determine its running time complexity and its Big-Oh.*/
template <class T>
void selectionSortForNxM_Matrix(T **db,int n,int m){
    T temp;
    int i=0,CurrentRowIndex,CurrentColumnIndex,minRowIndex,minColumnIndex,x,y;
    while(i<n*m){
        CurrentRowIndex=i/m;
        CurrentColumnIndex=i%m;
        minRowIndex=CurrentRowIndex;
        minColumnIndex=CurrentColumnIndex;
        for(int j=i+1;j<n*m;j++){
            x=j/m;
            y=j%m;
            if(db[x][y]<db[minRowIndex][minColumnIndex]){
                minRowIndex=x;
                minColumnIndex=y;
            }
        }
        temp=db[CurrentRowIndex][CurrentColumnIndex];
        db[CurrentRowIndex][CurrentColumnIndex]=db[minRowIndex][minColumnIndex];
        db[minRowIndex][minColumnIndex]=temp;
        i++;
    }
    cout<<endl;
}

int main()
{

    int db[][4]={{4,16,6,11},{12,3,8,1},{7,14,2,15},{5,10,13,9}};
    //selectionSortForNxM_Matrix(db[][4],4,4);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<db[i][j]<<"   ";
        }
        cout<<endl;
    }
    return 0;
}
