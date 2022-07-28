#include <iostream>
#include "LinkedList.h"
#include "src/LinkedList.cpp"
using namespace std;

///Name: Surafel Fantu ID: VN2703
int main()
{
    LinkedList<float> linkedList(true);
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
            (linkedList.insert(element))?cout<<"=>"<<element<<" added successfully\n":cout<<"Failed.\n";
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
            (index != NULL)?cout<<"=>"<<element<<" found at index "<<index<<endl:cout<<"=>"<<element<<" is not in the list\n";
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
        system("pause");
        system("CLS");
    }while(choice != 6);
    LinkedList<float> sample;
    sample.insert(3);
    sample.insert(1);
    sample.insert(4);
    sample.insert(2);
    sample.insert(8);
    sample.insert(6);
    sample.insert(7);
    sample.insert(5);

    LinkedList<float> sample2;
    sample2.insert(-3);
    sample2.insert(-1);
    sample2.insert(-4);
    sample2.insert(-2);
    sample2.insert(-8);
    sample2.insert(-6);
    sample2.insert(-7);
    sample2.insert(-5);
    //sample2.insertRangeAfter(-3,sample);
    cout<<"*********sample before a list is inserted*********";
    sample.display();
    cout<<"*********sample.insertRangeAfter(5,sample)**********";
    sample.insertRangeAfter(5,sample2);
    sample.display();
    cout<<"*********sample.removeRange(-3,-5)**********";
    sample.removeRange(-3,-5);
    sample.display();
    return 0;
}
