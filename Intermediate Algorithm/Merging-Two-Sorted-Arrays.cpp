#include <iostream>
#include <ctime>
///Name: Surafel Fantu ID: VN2703
using namespace std;


///17. Write an algorithm to merge two sorted arrays into a third array. The merged array should be sorted.
template <class T>
void mergingTwoArrays(T dbOne[],int sizeOne,T dbTwo[],int sizeTwo,T dbThree[]){
    for(int dbOneIndex=0,dbTwoIndex=0,count=0;dbOneIndex<sizeOne||dbTwoIndex<sizeTwo;count++){
        if(dbOneIndex<sizeOne&&dbTwoIndex<sizeTwo){
            (dbOne[dbOneIndex]<dbTwo[dbTwoIndex])?dbThree[count]=dbOne[dbOneIndex++]:dbThree[count]=dbTwo[dbTwoIndex++];
        }
        else if(dbOneIndex<sizeOne){
            dbThree[count]=dbOne[dbOneIndex++];
        }
        else{
            dbThree[count]=dbTwo[dbTwoIndex++];
        }

    }
}
template <class T>
void insertionSort(T db[],int size){
    T value;
    int tobe;
    for(int nextElement=1;nextElement<size;nextElement++){
        value=db[nextElement];
        tobe=nextElement;
        for(;tobe>0&&value<db[tobe-1];tobe--){
            db[tobe]=db[tobe-1];
        }
        db[tobe]=value;
    }
}
int main()
{
    int sizeOne,sizeTwo,*dbOne,*dbTwo,*dbThree;
    cout<<"Enter the size of the first array: ";
    cin>>sizeOne;
    dbOne=new (nothrow) int[sizeOne];
    if(!dbOne){
        cout << "Insufficient memory!!!"<<endl;
        system("pause");
        return 1;
    }
    cout<<"\nEnter the size of the second array: ";
    cin>>sizeTwo;
    dbTwo=new (nothrow) int[sizeTwo];
    if(!dbTwo){
        cout << "Insufficient memory!!!"<<endl;
        system("pause");
        return 1;
    }
    dbThree=new (nothrow) int[sizeOne+sizeTwo];
    if(!dbThree){
        cout << "Insufficient memory!!!"<<endl;
        system("pause");
        return 1;
    }
    srand((unsigned) time(0));
    for(int i=0; i<sizeOne; i++)
        dbOne[i]=rand()%(sizeOne);
    insertionSort(dbOne,sizeOne);
    cout<<"The first data base\n";
    for(int i=0; i<sizeOne; i++)
        cout<<dbOne[i]<<" ";
    for(int i=0; i<sizeTwo; i++)
        dbTwo[i]=rand()%(sizeTwo);
    insertionSort(dbTwo,sizeTwo);
    cout<<"\nThe second data base\n";
    for(int i=0; i<sizeTwo; i++)
        cout<<dbTwo[i]<<" ";
    mergingTwoArrays(dbOne,sizeOne,dbTwo,sizeTwo,dbThree);
    cout<<"\nThe two arrays after they are merged\n";
    for(int i=0; i<sizeOne+sizeTwo; i++)
        cout<<dbThree[i]<<" ";
    return 0;
}
