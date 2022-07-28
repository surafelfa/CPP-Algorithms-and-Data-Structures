#include <bits/stdc++.h>
#include "src/Queue.cpp"
#include "include/Queue.h"
#include <windows.h>
/**
1. Bisrat Asfaw Serur   Id: OU3676
2. Surafel Fantu Abebe  Id: VN2703
*/
HANDLE hConsole= GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;
string toLower(string name){
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    return name;
}
void sort(Queue<string>& unsortedQueue, Queue<string>& sortedQueue){
    sortedQueue.enqueue(unsortedQueue.dequeue());
    int j = 1;
    while (!unsortedQueue.isEmpty())
    {
        ///(abs(sortedQueue.getRear()-((sortedQueue.getFront()+1)%sortedQueue.getCapacity()))+1);
        string next = unsortedQueue.dequeue();
        for (int i = 0; i < j; ++i)
        {
            if (toLower(sortedQueue.peekFront()) < toLower(next)){
                sortedQueue.enqueue(sortedQueue.dequeue());
            }
            else
            {
                sortedQueue.enqueue(next);
                next = sortedQueue.dequeue();
            }
        }
        j++;
        sortedQueue.enqueue(next);
    }
}
void userInput(Queue<string>& unsortedQueue){
    string name;
    cout<<endl;
    for(int i = 1; i<=10; i++){
        SetConsoleTextAttribute(hConsole, 3);
        cout<<"Name "<<i<<": ";
        SetConsoleTextAttribute(hConsole, 15);
        cin>>name;
        unsortedQueue.enqueue(name);
    }
}
int main()
{
    char ans;
    Queue<string> unsortedQueue(11);
    Queue<string> sortedQueue(11);

    do{
        SetConsoleTextAttribute(hConsole, 2);
        cout<<"..................Driver App.................."<<endl;
        userInput(unsortedQueue);
        system("cls");
        SetConsoleTextAttribute(hConsole, 2);
        cout<<"..................Driver App.................."<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 3);
        cout<<"Unsorted queue: ";
        SetConsoleTextAttribute(hConsole, 15);
        unsortedQueue.display();
        sort(unsortedQueue, sortedQueue);
        SetConsoleTextAttribute(hConsole, 3);
        cout<<"Sorted queue: ";
        SetConsoleTextAttribute(hConsole, 15);
        sortedQueue.display();
        SetConsoleTextAttribute(hConsole, 3);
        cout<<"\nTo continue enter y/Y. To kill the program enter any key: ";
        SetConsoleTextAttribute(hConsole, 15);
        cin>>ans;
        cin.ignore(INT_MAX,'\n');
        unsortedQueue.clear();
        sortedQueue.clear();
        system("cls");
    }while(ans == 'y'|| ans == 'Y');
    SetConsoleTextAttribute(hConsole, 15);

    system("pause");

    return 0;
}
