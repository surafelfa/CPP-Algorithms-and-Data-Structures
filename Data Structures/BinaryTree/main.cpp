#include <iostream>
#include <math.h>
#include "bTree.h"
#include "src/bTree.cpp"
using namespace std;
/**
1. Amanuel Sisay
2. Bisrat Asfaw
3. Oumer Mohammed
4. Surafel Fantu
*/
// Binary tree array implementation
// 1. if parent is p and
// Array starts from 0 to n-1 then
// left child => (2*p)+1
// right child => (2*p)+2
// if array starts from 1 to n then
// we will reduce 1 in each formula
void menu(bTree<char> bt);
int main()
{
    bTree<char> tree;
    menu(tree);
    return 0;
}
void menu(bTree<char> bt)
{
    int choice;
    char n;
    while(1){
        cout << "Enter Your Choice: ";
        cout << "\n 1. For Adding root \n 2. For Adding Children \n 3. For Displaying the Tree \n 4. For Displaying in Traversal Order \n 5. Find Data \n 6. Delete Data \n 7. EXIT \n Choice:  ";
        cin >> choice;
        switch (choice){
        case 1:{
            cout << "Enter a Character for Root: ";
            cin >> n;
            bt.root(n);
            break;
        }
        case 2:{
            int parent=-1;
            char ch;
            int choice = 0;
            bt.print_tree();
            cout << " 1. For Left Child \n 2. For Right Child \n Choice: ";
            cin >> choice;
                switch(choice){
                case 1:
                    cout << "Enter a Character: ";
                    cin >> ch;
                    cout << "\nEnter the Parent Index: ";
                    cin >> parent;
                    bt.set_left(ch, parent);
                    bt.cls();
                    break;
                case 2:
                    cout << "Enter a Character: ";
                    cin >> ch;
                    cout << "\nEnter the Parent Index: ";
                    cin >> parent;
                    bt.set_right(ch, parent);
                    bt.cls();
                    break;
                    }
            break;
        }
        case 3:{
            bt.print_tree();
            bt.pause();
            bt.cls();
            break;
        }
        case 4:{
            int choice = 0;

            bt.print_tree();

            cout << " 1. PreOrder Traversal \n 2. PostOrder Traversal \n 3. InOrder Traversal \n Choice: ";
            cin >> choice;
                switch(choice){
                case 1:

                    bt.printPreOrder(0);
                    cout << "\n\n\n";
                    bt.pause();
                    break;
                case 2:
                    bt.printPostOrder(0);
                    cout << "\n\n\n";
                    bt.pause();
                    break;
                case 3:
                    bt.printInOrder(0);
                    cout << "\n\n\n";
                    bt.pause();
                    break;
                }
            bt.cls();
            break;
        }
        case 5:{
            char chh;
            cout << "Enter a Character to find: ";
                    cin >> chh;
            int index = bt.findData(chh);
            if(index == -1){
                cout << "There is no such an element in the tree.\n";
            }
            else{
                cout << "Element " << chh <<" is stored at index "<< index << "\n";
            }
            bt.pause();
            bt.cls();
            break;
        }
        case 6:{
            bt.print_tree();
                char chh;
            cout << "Enter a Character to Delete: ";
                    cin >> chh;
            bool deleted = bt.deleteData(chh);
            if(deleted){
                cout << "Data is deleted.\n";
            }else{
                cout << "Can't delete the data because the data does not exists or the data has children.\n";
            }
            bt.pause();
            bt.cls();
                break;
            }
        case 7:
            exit(0);
            break;
        default:
            cout << "Invalid Choice.\n";

        }
    }
};
