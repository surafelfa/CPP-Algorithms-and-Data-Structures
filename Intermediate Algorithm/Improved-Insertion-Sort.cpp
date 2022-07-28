#include <iostream>
#include <ctime>
///Name: Surafel Fantu ID: VN2703
using namespace std;


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

}
int main()
{
    int size,*db;
    cout<<"Enter the size of the array: ";
    cin>>size;
    db=new (nothrow) int[size];
    if(!db){
        cout << "Insufficient memory!!!"<<endl;
        system("pause");
        return 1;
    }

    srand((unsigned) time(0));
    for(int i=0; i<size; i++)
        db[i]=rand()%(size);
    cout<<"\nThe data base before it is sorted\n\n";
    for(int i=0; i<size; i++)
        cout<<db[i]<<" ";
    insertionSortEx(db, size);
    cout<<"\n\nThe data base after it is sorted\n\n";
    for(int i=0; i<size; i++)
        cout<<db[i]<<" ";
    return 0;

    /**Binary search affects insertion sort by reducing O(n^2) comparisons in worst case to
    O(log n) comparisons; however, the series of shifts are required
    for each insertion, it has running time of O(n^2).*/
}
