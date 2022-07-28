#include <chrono>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace std::chrono;
enum SortingAlgorithm{
    BUBBLE_SORT=1,
    SELECTION_SORT,
    INSERTION_SORT,
    ALL
};
template <class T>
void swap(T db[],int indexOne,int indexTwo){
    T temp;
    temp=db[indexOne];
    db[indexOne]=db[indexTwo];
    db[indexTwo]=temp;
}


template <class T>
void bubbleSort(T db[],int size){
    int lastIndex=size-1;
    for(int i=1; i<=lastIndex;i++){
        for(int j=lastIndex;j>=i;j--){
            if(db[j]<db[j-1]){
                swap(db,j,j-1);
            }
        }
    }
}

template <class T>
void selectionSort(T db[],int size){
    int position, minPos,innerPos;
    T temp;
    for(position=0; position<=size-2;position++){
        minPos=position;
        innerPos=position+1;
        for (;innerPos<=size-1;innerPos++){
            if(db[innerPos]<db[minPos]){
                minPos=innerPos;
            }
        }
       // cout <<"swapping "<< db[position] << "to position number " <<db[minPos] << endl;
       if(position != minPos)
       {
           swap(db,position,minPos);
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
///Extended version
template<class T >
void bubbleUpsortEx(T db[],int size){

    T temp;
    bool swapped=true;
    int lastIndex=size-1;
    for(int i=1; i<=lastIndex&&swapped;i++){
        swapped=false;
        for(int j=lastIndex;j>=i;j--){
            if(db[j]<db[j-1]){
                swap(db,j,j-1);
                swapped=true;
            }
        }
    }

}

template <class T>
void minMaxSelectionSort(int* db, int n){
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        int min = db[i], max = db[i];
        int min_i = i, max_i = i;
        for (int k = i; k <= j; k++)  {
            if (db[k] > max) {
                max = db[k];
                max_i = k;
            } else if (db[k] < min) {
                min = db[k];
                min_i = k;
            }
        }

        // shifting the min.
        swap(db,i, min_i);

        // Shifting the max. The equal condition
        // happens if we shifted the max to arr[min_i]
        // in the previous swap.
        (db[min_i] == max)?swap(db,j, min_i):swap(db,j, max_i);
    }
}

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
    /**Since the series of shifts are required for each insertion, it has running time of O(n2).
    So, modifying insertion sort using binary search does not affect it in a positive way.*/
}

template <class T>
inline void PopulatingForBestCase(T db[],int size){
    for(int i=0; i<size; i++)
        db[i]=i+1;
}

template <class T>
inline void PopulatingForAverageCase(T db[],int size){
    srand((unsigned) time(0));
    for(int i=0; i<size; i++)
        db[i]=rand()%(size);
}

template <class T>
inline void PopulatingForWorstCase(T db[],int size,int sortingAlgotithm){
    if (sortingAlgotithm!=SELECTION_SORT){
        int Count = 1;
        for(int i=size-1; i>=0; i--){
           db[i]=Count;
        Count++;
        }
    }
    else if(sortingAlgotithm == SELECTION_SORT){
        int last = 0;
        for(int i = 0;i<size;i++){
            if(last != 0){
                db[i]=i;
            }
            else if(last == 0){
                db[i]=size;
                last =1;
            }
        }
    }

}

template<class T,class U>
void analyzingAnAlgotithm(T db[],U &timeTaken,int size,void(*func)(T db[],int size),int scenario, int sortingAlgotithm){
    timeTaken=0;
    int four = scenario;
    if (scenario == 4){
        scenario= 1;
    }
// dividing it based on sorting case scenario
    switch (scenario){
        case 1:{
        // BEST CASE
            PopulatingForBestCase(db,size);
            auto start = high_resolution_clock::now(); //high_resolution_clock::time_point
                // Call the function here
            func(db,size);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "\n1.Time taken by the algorithm for its best case is "<< duration.count() << " microseconds" << endl;
            if(four !=ALL )break;
        }
        case 2:{
          // AVERAGE CASE
            for(int i=0;i<10;i++){
                PopulatingForAverageCase(db,size);
                auto start = high_resolution_clock::now(); //high_resolution_clock::time_point
                // Call the function here
                func(db,size);
                auto stop = high_resolution_clock::now();
                timeTaken+= duration_cast<microseconds>(stop - start).count();
            }
            cout << "2.Time taken by the algorithm for its average case is "<< /**averageTime*/timeTaken/10<< " microseconds" << endl;

            if(four !=ALL )break;
        }
        case 3: {
        // WORST CASE
            PopulatingForWorstCase(db,size,sortingAlgotithm);
            auto start = high_resolution_clock::now(); //high_resolution_clock::time_point
                // Call the function here
            func(db,size);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "3.Time taken by the algorithm for its worst case is "<< duration.count() << " microseconds" << endl;
            cout<<endl;

            if(four !=ALL )break;
            }
        default:
            break;
    }
}

int main()
{
    while (true){

    int size,*db;
    double timeTaken;
    //auto start,stop;
    cout << "Enter the data size: ";
    cin >>size;
    db=new (nothrow) int[size];
    //timeTaken=new (nothrow) double[size];
    if(!db/*||!timeTaken*/){
        cout << "Insufficient memory!!!"<<endl;
        system("pause");
        return 1;
    }
    int sortingAlgotithm,scenario;
    cout << "Which sorting algorithm do you want to use?: \n\n 1: Bubble Sort \n 2: Selection Sort \n 3: Insertion Sort \n 4: ALL at once \n\n";
    cout << "Choice: ";
    cin >>sortingAlgotithm;

    cout << endl << endl;

    cout << "In which case do you want the selected sorting algorithm to perform?: \n\n 1: Best case \n 2: Average case \n 3: Worst case \n 4: ALL at once \n\n";
    cout << "Choice:";
    cin >>scenario;

    system("CLS");

    if (sortingAlgotithm == BUBBLE_SORT){
        cout<<"************Bubble sort************\n";
        analyzingAnAlgotithm(db,timeTaken,size,&bubbleSort,scenario,sortingAlgotithm);

 //  analyzingAnAlgotithm(db,timeTaken,size,&bubbleSort,scenario,sortWay);
    }
    else if (sortingAlgotithm == SELECTION_SORT){

        cout<<"************Selection sort************\n";
        analyzingAnAlgotithm(db,timeTaken,size,&selectionSort,scenario,sortingAlgotithm);

    }
    else if (sortingAlgotithm == INSERTION_SORT){
        cout<<"************Insertion sort************\n";
        analyzingAnAlgotithm(db,timeTaken,size,&insertionSort,scenario,sortingAlgotithm);
    }
    else if (sortingAlgotithm == ALL){

        cout<<"************Bubble sort************\n";
        analyzingAnAlgotithm(db,timeTaken,size,&bubbleSort,scenario,BUBBLE_SORT);
        cout<<"************Selection sort************\n";
        analyzingAnAlgotithm(db,timeTaken,size,&selectionSort,scenario,SELECTION_SORT);
        cout<<"************Insertion sort************\n";
        analyzingAnAlgotithm(db,timeTaken,size,&insertionSort,scenario,INSERTION_SORT);
    }
    cout<<endl;
    system("Pause");
    system("CLS");
    }
    return 0;
}
