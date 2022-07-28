#include <iostream>
#include "DLinkedList.h"
#include "src/DLinkedList.cpp"
///Name: Surafel Fantu ID: VN2703
using namespace std;

int main()
{
    DLinkedList<float> DlinkedList(true);
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
            Node<float>* index;
        case 1:
            cout<<"Adding float\nEnter a float number: ";
            cin>>element;
            (DlinkedList.insert(element))?cout<<"=>"<<element<<" added successfully\n":cout<<"Failed.\n";
            break;
        case 2:
            cout<<"Removing float\nEnter a float number: ";
            cin>>element;
            (DlinkedList.remove(element))?cout<<"=>"<<element<<" removed successfully\n":cout<<"=>"<<element<<" is not in the list\n";
            break;
        case 3:
            cout<<"Searching\nEnter a float number: ";
            cin>>element;
            index = DlinkedList.findNode(element);
            (index != NULL)?cout<<"=>"<<element<<" found at index "<<index<<endl:cout<<"=>"<<element<<" is not in the list\n";
            break;
        case 4:
            cout<<"Updating\nEnter a float number: ";
            cin>>element;
            DlinkedList.update(element);
            break;
        case 5:
            DlinkedList.display();
            cout<<endl;
            break;
        case 6:
            choice = 6;
            break;
        default:
            cout<<"\nInvalid input!!!";
            break;
        }
        system("pause");
        system("CLS");
    }while(choice != 6);
    DLinkedList<float> sample;
    sample.insert(3);
    sample.insert(1);
    sample.insert(2);
    sample.insert(6);
    sample.insert(8);
    sample.insert(5);
    cout<<"*********sample before a list is inserted*********";
    sample.display();
    DLinkedList<float>sample2;
    sample2.insert(-3);
    sample2.insert(-1);
    sample2.insert(-2);
    sample2.insert(-6);
    sample2.insert(-8);
    sample2.insert(-5);
    cout<<"*********sample.insertRangeBefore(3,sample2)**********";
    sample.insertRangeBefore(3,sample2);
    sample.display();
    cout<<"*********sample.removeRange(-3,-5)**********";
    sample.removeRange(-3,-5);
    sample.display();
    return 0;
}
