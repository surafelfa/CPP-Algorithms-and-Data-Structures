#include <iostream>
#include "Vector.h"
///Name: Surafel Fantu ID: VN2703

using namespace std;


int main()
{
    DynamicArray<int> vectorOne;
    if(vectorOne.Insert(1,0)==-1)
        cout<<"something went wrong!!!"<<endl;
    else if(vectorOne.Insert(1,0)==-2)
        cout<<"the database is full"<<endl;
    else
        cout<<"the element was inserted at index:"<<vectorOne.Insert(1,0)<<endl;
    if(vectorOne.Assign(10,0))
    {
        cout<<"the capacity of vector one:"<<vectorOne.Capacity()<<endl;
        for(int i=0;i<10;i++)
        {
            if(vectorOne.Empty())
            {
                cout<<"vector one is empty."<<endl;
            }
            if(vectorOne.Insert(i+1,i)==i)
            {
                cout<<"the number of element in vector one:"<<vectorOne.Size()<<endl;
                cout<<"the number of available space in vector one:"<<vectorOne.Available()<<endl;
            };
            if(vectorOne.Full())
            {
                cout<<"now, the vector is full so let's resize it by 10."<<endl;
                if(vectorOne.Resize(10))
                {
                    cout<<"vector one is resized by 10."<<endl;
                    cout<<"now, the capacity of vector one:"<<vectorOne.Capacity()<<endl;
                    cout<<"the number of element in vector one:"<<vectorOne.Size()<<endl;
                    cout<<"now, the number of available space in vector one:"<<vectorOne.Available()<<endl;
                }
            }

        }
    };
    (vectorOne[10]==NULL)?cout<<"there is no an element at index 10."<<endl:cout<<"element at index 10:"<<vectorOne[10]<<endl;
    DynamicArray<int> vectorTwo=vectorOne;
    cout<<"the number of element in vector two:"<<vectorTwo.Size()<<endl;
    cout<<"the number of available space in vector two:"<<vectorTwo.Available()<<endl;
    cout<<"\n\n************vectorOne.Clear()************"<<endl;
    vectorOne.Clear();
    cout<<"vector one was just cleansed."<<endl;
    cout<<"the number of element in vector one:"<<vectorOne.Size()<<endl;
    cout<<"the number of available space in vector one:"<<vectorOne.Available()<<endl;
    cout<<"the number of element in vector two:"<<vectorTwo.Size()<<endl;
    cout<<"the number of available space in vector two:"<<vectorTwo.Available()<<endl;
    //cout<<"assigning vector two's elements starting from index 5."<<endl;
    cout<<"\n\n************vectorOne.Assign(vectorTwo,5)************"<<endl;
    vectorOne.Assign(vectorTwo,5);
    cout<<"the number of element in vector one:"<<vectorOne.Size()<<endl;
    cout<<"the number of available space in vector one:"<<vectorOne.Available()<<endl;
    cout<<"\n\n************vectorOne.Erase(1,3)************"<<endl;
    if(vectorOne.Erase(1,3)!= false)
    {
        for(int i=0;i<vectorOne.Size();i++)
        {
            cout<<"an element in vector one at index "<<i<<" is "<<vectorOne.At(i)<<endl;
        }
        cout<<"the number of element in vector one after erasing some element:"<<vectorOne.Size()<<endl;
        cout<<"the number of available space in vector one after erasing some element:"<<vectorOne.Available()<<endl;
    }
    bool flag=true;
    for(int i=vectorTwo.Size()-1;!vectorTwo.Full();i++)
    {
        if(flag)
        {
            vectorTwo.Push_front(i);
            flag=false;
        }
        else
        {
            vectorTwo.Push_back(i);
            flag=true;
        }

    }
    cout<<"the number of element in vector two after pushing some element:"<<vectorTwo.Size()<<endl;
    cout<<"the number of available space in vector two after pushing some element:"<<vectorTwo.Available()<<endl;
    cout<<"elements in vector two."<<endl;
    for(int i=0;i<vectorTwo.Size();i++)
    {
        cout<<vectorTwo[i]<<"  ";
    }
    cout<<endl;
    cout<<"\n\n************vectorTwo.Sort()************"<<endl;
    vectorTwo.Sort();
    cout<<"elements in vector two after it is sorted."<<endl;
    for(int i=0;i<vectorTwo.Size();i++)
    {
        cout<<vectorTwo[i]<<"  ";
    }
    cout<<endl;
    cout<<"\n\n************vectorTwo.Reverse()************"<<endl;
    vectorTwo.Reverse();
    cout<<"elements in vector two after it is reverse."<<endl;
    for(int i=0;i<vectorTwo.Size();i++)
    {
        cout<<vectorTwo[i]<<"  ";
    }
    vectorOne.Reserve(100);
    cout<<"\n\n************vectorOne.Reserve(100)************"<<endl;
    cout<<"the number of element in vector one:"<<vectorOne.Size()<<endl;
    cout<<"the number of available space in vector one:"<<vectorOne.Available()<<endl;
    cout<<"the capacity of vector one:"<<vectorOne.Capacity()<<endl;
    cout<<"\n************vectorOne=vectorTwo************"<<endl;
    vectorOne=vectorTwo;
    cout<<"the number of element in vector one:"<<vectorOne.Size()<<endl;
    cout<<"the number of available space in vector one:"<<vectorOne.Available()<<endl;
    cout<<"the capacity of vector one:"<<vectorOne.Capacity()<<endl;
    cout<<"************vectorOne.Front()************"<<endl;
    cout<<vectorOne.Front()<<endl;
    cout<<"\n************vectorOne.Back()************"<<endl;
    cout<<vectorOne.Back()<<endl;
    cout<<"\n************vectorOne.Pop_back()************"<<endl;
    cout<<vectorOne.Pop_back()<<" has been popped."<<endl;
    cout<<"\n************vectorOne.Pop_front()************"<<endl;
    cout<<vectorOne.Pop_front()<<" has been popped."<<endl;
    cout<<"the number of element in vector one:"<<vectorOne.Size()<<endl;
    cout<<"the number of available space in vector one:"<<vectorOne.Available()<<endl;
    cout<<"\n************vectorTwo.Assign(10,0)************"<<endl;
    vectorTwo.Assign(10,0);
    cout<<"the number of element in vector two:"<<vectorTwo.Size()<<endl;
    cout<<"the number of available space in vector two:"<<vectorTwo.Available()<<endl;
    cout<<"the capacity of vector two:"<<vectorTwo.Capacity()<<endl;
    cout<<"\n************vectorTwo.Assign(vectorOne)************"<<endl;
    vectorTwo.Assign(vectorOne);
    cout<<"the number of element in vector two:"<<vectorTwo.Size()<<endl;
    cout<<"the number of available space in vector two:"<<vectorTwo.Available()<<endl;
    cout<<"the capacity of vector two:"<<vectorTwo.Capacity()<<endl;
    cout<<"\n************vectorTwo.Assign(vectorOne,5)************"<<endl;
    vectorTwo.Assign(vectorOne,5);
    cout<<"the number of element in vector two:"<<vectorTwo.Size()<<endl;
    cout<<"the number of available space in vector two:"<<vectorTwo.Available()<<endl;
    cout<<"the capacity of vector two:"<<vectorTwo.Capacity()<<endl;
    cout<<"\n************vectorTwo.Assign(vectorOne,5,10)************"<<endl;
    vectorTwo.Assign(vectorOne,5,10);
    cout<<"the number of element in vector two:"<<vectorTwo.Size()<<endl;
    cout<<"the number of available space in vector two:"<<vectorTwo.Available()<<endl;
    cout<<"the capacity of vector two:"<<vectorTwo.Capacity()<<endl;
    cout<<"\n*****elements in vector two******"<<endl;
    for(int i=0;i<vectorTwo.Size();i++)
    {
        cout<<vectorTwo.At(i)<<"  ";
    }
    DynamicArray<std::string> v3(10,"a");
    v3.Insert("surafel",0);v3.Insert("fantu",1);v3.Insert("aster",2);v3.Insert("fasika",3);v3.Insert("melat",5);
    cout<<"\n\n************v3.Sort()************"<<endl;
    v3.Sort();
    for(int i=0;i<v3.Size();i++)
    {
        cout<<v3.At(i)<<"  ";
    }
    cout<<"\n\n************v3.Reverse()************"<<endl;
    v3.Reverse();
    for(int i=0;i<v3.Size();i++)
    {
        cout<<v3.At(i)<<"  ";
    }
    cout<<endl<<endl;

    return 0;
}

















