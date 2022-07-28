#include <iostream>
#include "LinkedList.h"
#include "BaseArray.h"
#include "src/BaseArray.cpp"
#include "src/LinkedList.cpp"
///Name: Surafel Fantu ID: VN2703
using namespace std;

int main()
{
    BaseArray<float> baseArray(5);
    LinkedList<float> linkedList(&baseArray,true);
    int choice;
    float element;
    do
    {
        cout<<"1. Add float"<<endl;
        cout<<"2. Remove float"<<endl;
        cout<<"3. Search"<<endl;
        cout<<"4. Update"<<endl;
        cout<<"5. Display"<<endl;
        cout<<"6. Exit"<<endl;
        cin>>choice;
        system("CLS");
        switch(choice)
        {
            int index;
        case 1:
            cout<<"Adding float\nEnter a float number: ";
            cin>>element;
            if(linkedList.insert(element))
                cout<<"=>"<<element<<" added successfully\n";
            else{
                cout<<"Since the container is full, you can not add elements any more.";
                cout<<" Thus we are resizing the container by 10...";
                (baseArray.resize(10))?cout<<"\nResized successfully. You can reinsert the element again\n":cout<<"\nFailed\n";
            }
            break;
        case 2:
            cout<<"Removing float\nEnter a float number: ";
            cin>>element;
            (linkedList.remove(element))?cout<<"=>"<<element<<" removed successfully\n":cout<<"=>"<<element<<" is not in the list\n";
            break;
        case 3:
            cout<<"Searching\nEnter a float number: ";
            cin>>element;
            index = linkedList.findNode(element);
            (index != -1)?cout<<"=>"<<element<<" found at index "<<index<<endl:cout<<"=>"<<element<<" is not in the list\n";
            break;
        case 4:
            cout<<"Updating\nEnter a float number: ";
            cin>>element;
            linkedList.update(element);
            break;
        case 5:
            linkedList.display();
            cout<<endl;
            break;
        case 6:
            choice = 6;
            break;
        default:
            cout<<"\nInvalid input!!!";
            break;
        }
        //cout<<endl<<"likedList.count();"<<linkedList.count()<<endl;
        system("pause");
        system("CLS");
    }while(choice != 6);
    LinkedList<float> linkedList2=&linkedList;//(&baseArray,true);
    linkedList=&linkedList2;
    cout<<"element at index 3: "<<linkedList2[3]<<endl;
    cout<<"*********likedList->clear()**********"<<endl;
    linkedList.clear();
    cout<<"number of elements after the liked list has been cleansed: "<<linkedList.count()<<endl;

    //system("pause");
    return 0;
}
