#include <bits/stdc++.h>
#include <windows.h>
#include "Stack.h"
#include "src/Stack.cpp"

/**
1. Bisrat Asfaw Serur   Id: OU3676
2. Surafel Fantu Abebe  Id: VN2703
*/

HANDLE hConsole= GetStdHandle(STD_OUTPUT_HANDLE);
const int RED_COLOR = 12;
struct Identifier{
    char symbol;
    long lineNum;
    long pos;
};
bool areSymbolsBalanced(Stack<Identifier>& stack, string, Identifier&);
void jampCommet(string srCode, long& i, long& lineNum, long length);
void jampSrChConst(string srCode, long& i, long length);
void saveErrors(Stack<Identifier>& stack, string srCode, long i, long lineNum);
void displayError(Stack<Identifier>& stack);
void check()
{
    Stack<Identifier> stack(1000);
    Identifier forSymbols;
    forSymbols.lineNum = 1;
    string srCode ="a\nb}\nc(\n[[ ) /**QQQQQQ{[}]{ [] {]  [}  [[  */[}  ]'('";
    string tp;
    //=>/**QQQQQQ{[}]{ [] {]  [}  [[  */ as a comment
    //=> '(' as a character constant.

    ifstream inFile;

    inFile.open("test.txt");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    srCode = "";
    while (getline(inFile, tp)) {
        srCode = srCode + tp + "\n";
    }
    inFile.close();
    cout<<srCode<<endl;
    bool balanced = areSymbolsBalanced(stack,srCode,forSymbols);
    if(balanced)
        cout<<"Symbols are balanced!!!"<<endl;
    else
        displayError(stack);
}
int main()
{
    check();
    SetConsoleTextAttribute(hConsole, 15);
    cout<<"###################################\n";
    Stack<Identifier> stack(1000);
    Identifier forSymbols;
    forSymbols.lineNum = 1;
    string srCode;
    bool balanced;
    char ans;

    do{
        SetConsoleTextAttribute(hConsole, RED_COLOR);
        cout<<"Write your own sample code...\n";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"Input: ";
        getline(cin, srCode, '\n');
        balanced = areSymbolsBalanced(stack,srCode,forSymbols);
        if(balanced)
            cout<<"Symbols are balanced!!!"<<endl;
        else
            displayError(stack);
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"Enter Y/y to continue or any key to kill the calculator: ";
        cin >>ans;
        system("cls");
        cin.ignore(INT_MAX,'\n');
    }while(ans == 'y'|| ans == 'Y');

    system("pause");
    return 0;
}
bool areSymbolsBalanced(Stack<Identifier>& stack, string srCode, Identifier& forSymbols)
{
    long length = srCode.length(), lineNum=1;
    cout<<"Number of characters/length: "<<length<<endl;
    for (long i = 0; i < length; i++)
    {
        if(srCode[i] == '\n'){
            ++lineNum;
        }
        else if (srCode[i] == '(' || srCode[i] == '[' || srCode[i] == '{')
        {
            if(stack.isFull())
                stack.resize(10);
            forSymbols.symbol = srCode[i];
            forSymbols.pos = i+1;
            forSymbols.lineNum = lineNum;
            stack.push(forSymbols);
            continue;
        }
        jampCommet(srCode, i, lineNum, length);
        jampSrChConst(srCode, i, length);
        if(i < length){
            saveErrors(stack, srCode, i, lineNum);
            forSymbols.lineNum = lineNum;
        }
    }
    return stack.isEmpty();
}
void jampCommet(string srCode, long& i, long& lineNum, long length)
{
    if(srCode[i] == '/')
    {
        if(++i < length){
            if(srCode[i] == '*'){
                bool found = false;
                while(!found && i < length ){
                    if(srCode[i] == '\n')
                        ++lineNum;
                    else if(srCode[i] == '/' && srCode[i-1] == '*')
                        found = true;
                    i++;
                }
                i--;
            }
            else if(srCode[i] == '/'){
                    while(i < length && srCode[i] != '\n'){
                        i++;
                }
                if(i != length) ++lineNum;
            }
        }
    }
};
void jampSrChConst(string srCode, long& i, long length)
{
    char sigQou[] = {"'"};
    if(srCode[i] == sigQou[0] || srCode[i] == '"')
    {
        if(++i < length){
            if(srCode[i-1] == sigQou[0]){
                while(i < length && srCode[i] != sigQou[0]){
                    i++;
                }
            }else{
                while(i < length && srCode[i] != '"'){
                    i++;
                }
            }
        }
    }
};
void saveErrors(Stack<Identifier>& stack, string srCode, long i, long lineNum)
{
    Identifier symbol;
    if (stack.isEmpty() && ( srCode[i] == ')' || srCode[i] == ']' || srCode[i] == '}'))
    {
        symbol.lineNum = lineNum;
        symbol.pos = i+1;
        symbol.symbol = srCode[i];
        stack.push(symbol);
        return;
    }
    switch (srCode[i]) {
    case ')':
        symbol = stack.pop();
        if (symbol.symbol != '('){
            stack.push(symbol);
            symbol.lineNum = lineNum;
            symbol.pos = i+1;
            symbol.symbol = ')';
            stack.push(symbol);
        }
        break;

    case '}':
        symbol = stack.pop();
        if (symbol.symbol != '{'){
            stack.push(symbol);
            symbol.lineNum = lineNum;
            symbol.pos = i+1;
            symbol.symbol = '}';
            stack.push(symbol);
        }
        break;

    case ']':
        symbol = stack.pop();
        if (symbol.symbol != '['){
            stack.push(symbol);
            symbol.lineNum = lineNum;
            symbol.pos = i+1;
            symbol.symbol = ']';
            stack.push(symbol);
        }
        break;
    }
}
void displayError(Stack<Identifier>& stack)
{
    Identifier symbolsFromStack;
    stack.reverse();
    SetConsoleTextAttribute(hConsole, RED_COLOR);
    while(!stack.isEmpty())
    {
        symbolsFromStack = stack.pop();
        if(symbolsFromStack.symbol == '(' || symbolsFromStack.symbol == '{' || symbolsFromStack.symbol == '['){
            cout<<"An error occurred, due to "<<symbolsFromStack.symbol<<" symbol without closing it, on line number: ";
            cout<<symbolsFromStack.lineNum<<" and at position: "<<symbolsFromStack.pos<<endl;
        }
        else{
            cout<<"An error occurred, because "<<symbolsFromStack.symbol<<" was not opened, on line number: ";
            cout<<symbolsFromStack.lineNum<<" and at position: "<<symbolsFromStack.pos<<endl;
        }
    }
}
