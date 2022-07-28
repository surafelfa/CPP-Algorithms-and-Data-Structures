#include <iostream>
#include <ctime>
///Name: Surafel Fantu ID: VN2703
using namespace std;

/**18.	Design algorithm to sort a two dimensional array A[n][n] (all elements in a row is sorted and
all the elements in the ith row are less than the elements in the ith +1 row ) using Selection Sort.
And determine its running time complexity and its Big-Oh.*/
template <class T>
void selectionSortForNxM_Matrix(T **db,int size){
    T temp;
    int i=0,CurrentRowIndex,CurrentColumnIndex,minRowIndex,minColumnIndex,x,y;///1
    int TotSize=size*size;/// 1+3=4
    while(i<TotSize){///n*n+1
        CurrentRowIndex=i/size;///2n^2
        CurrentColumnIndex=i%size;///2n^2
        minRowIndex=CurrentRowIndex;///1
        minColumnIndex=CurrentColumnIndex;///1
        for(int j=i+1;j<TotSize;j++){
            x=j/size;///2
            y=j%size;///2
            if(db[x][y]<db[minRowIndex][minColumnIndex]){///7
                minRowIndex=x;///1
                minColumnIndex=y;///1
            }
        }
        temp=db[CurrentRowIndex][CurrentColumnIndex];///4
        db[CurrentRowIndex][CurrentColumnIndex]=db[minRowIndex][minColumnIndex];///7
        db[minRowIndex][minColumnIndex]=temp;///4
        i++;///2
    }
    cout<<endl;
}

int main()
{
    int size,**matrix;
    cout<<"Enter the size of the matrix: ";
    cin>>size;
    matrix= new int *[size];
    if(!matrix){
        cout << "Insufficient memory!!!"<<endl;
        system("pause");
        return 1;
    }
    for(int i = 0; i <size; i++){
        matrix[i] = new int[size];
        if(!matrix[i]){
            cout << "Insufficient memory!!!"<<endl;
            system("pause");
            return 1;
        }
    }
    srand((unsigned) time(0));
    for(int i=0; i<size; i++)
        for(int j=0;j<size;j++)
            matrix[i][j]=rand()%(size);
    cout<<"\nThe matrix before it is sorted.\n";
    for(int i=0; i<size; i++){
        for(int j=0;j<size;j++)
            cout<<matrix[i][j]<<"  ";
        cout<<endl;
    }

    selectionSortForNxM_Matrix(matrix,size);

    cout<<"The matrix after it is sorted.\n";
    for(int i=0; i<size; i++){
        for(int j=0;j<size;j++)
            cout<<matrix[i][j]<<"  ";
        cout<<endl;
    }
    return 0;
}
