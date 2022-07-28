#include <bits/stdc++.h>
#include <windows.h>
#include "Stack.h"
#include "src/Stack.cpp"

/**
1. Bisrat Asfaw Serur   Id: OU3676
2. Surafel Fantu Abebe  Id: VN2703
*/

HANDLE hConsole= GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;
const double TO_DEGREE = 3.1415926535897932384626433832795/180;//2.7182818284590452353602874713527;
const int RED_COLOR = 12;
/*Pop and output all stack symbols until a symbol of lower precedence or a
right-associative symbol of equal precedence appears. Then push the operator.*/
bool isNumber(const std::string& s)
{
    char* end = nullptr;
    double val = strtod(s.c_str(), &end);
    return end != s.c_str() && *end == '\0' && val != HUGE_VAL;
}
///abs-a, sqrt-s, sin-i, cos-c, tan-t, logab-l, log b-m, ln b-n
string changeToPostfix(Stack<string>& stack, string expr);
string calc(Stack<string>& stack, string postfix);
void check();
/*double x = log (2 - sqrt ( abs ( 2 * cos( 180 ) + (log ( 2 )/log(E) )) ));
    cout<<"X: "<<x<<endl;*/
int main()
{
    Stack<string> stack;
    char ans;
    string solution;
    string expr, postfix;
    cout<<"CHECKING THE CALCULATOR...\n\n";
    check();
    do{
        SetConsoleTextAttribute(hConsole, RED_COLOR);
        cout<<"Check the calculator using your own input. But each and every input has to be space separated!!!";
        cout<<" As you use 'log' with two input use this format x g y (meaning log y to the base x).\n";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"Input: ";
        getline(cin, expr, '\n');
        postfix = changeToPostfix(stack,expr);
        cout<<"Postfix: "<<postfix<<endl;
        solution = calc (stack,postfix);
        cout<<"Solution = "<<solution<<endl;
        cout<<"Enter Y/y to continue or any key to kill the calculator: ";
        cin >>ans;
        system("cls");
        cin.ignore(INT_MAX,'\n');
    }while(ans == 'y'|| ans == 'Y');
    system("pause");

    return 0;
}
string changeToPostfix(Stack<string>& stack, string expr)
{
    stringstream s(expr);
    string temp = "";
    string ch;
    while(s >> ch)
    {
        if(isNumber(ch))
            temp = temp + ch + " ";
        else if(ch == "(")
            stack.push(ch);
        else if(!stack.isEmpty()){
            string oper="";
            if(ch == ")"){
                bool found = false;
                do{
                    oper = stack.pop();
                    if(oper != "("){
                        temp = temp + oper + " ";
                    }
                    else found = true;
                }while(!found && !stack.isEmpty());
            }
            else if(ch == "-" || ch == "+"){
                bool pushed = false;
                do{
                   oper = stack.peek();
                   if(oper == "("){
                        stack.push(ch);
                        pushed = true;
                   }else{
                        temp = temp + stack.pop() + " ";
                        if(stack.isEmpty()){
                            stack.push(ch);
                            pushed = true;
                        }
                   }
                }while(!pushed);
            }
            else if(ch == "*" || ch == "%" || ch == "/"){
                oper = stack.peek();
                bool pushed = false;
                do{
                    if(oper == "-" || oper == "+" || oper == "("){
                        stack.push(ch);
                        pushed = true;
                        break;
                    }
                    temp = temp + stack.pop() + " ";
                    if(!stack.isEmpty()){
                        oper = stack.peek();
                    }
                    else{
                        stack.push(ch);
                        pushed = true;
                    }
                }while(!pushed);
            }else if(ch == "^") {
                oper = stack.peek();
                bool pushed = false;
                do{
                    if(oper == "-" || oper == "+" ||oper == "*" || oper == "%" || oper == "/"|| oper == "^" || oper == "("){
                        stack.push(ch);
                        pushed = true;
                        break;
                    }
                    temp = temp + stack.pop() + " ";
                    if(!stack.isEmpty()){
                        oper = stack.peek();
                    }
                    else{
                        stack.push(ch);
                        pushed = true;
                    }
                }while(!pushed);
            }else if(ch != "sqrt" && ch != "ln"){
                oper = stack.peek();
                bool pushed = false;
                do{
                    if(oper == "-" || oper == "+" || oper == "*" || oper == "%" || oper == "/" || oper == "^" || oper == "("){
                        stringstream  word(ch);
                        char singLetter = '\0';
                        word >> singLetter;
                        string oper(1, singLetter);
                        stack.push(oper);
                        pushed = true;
                        break;
                    }
                    temp = temp + stack.pop() + " ";
                    if(!stack.isEmpty()){
                        oper = stack.peek();
                    }
                    else{
                        stack.push(ch);
                        pushed = true;
                    }
                }while(!pushed);
            }else{
                oper = stack.peek();
                bool pushed = false;
                do{
                    if(oper == "-" || oper == "+" ||oper == "*" || oper == "%" || oper == "/"|| oper == "^" || oper == "("){
                        stringstream  word(ch);
                        char singLetter = '\0';
                        word >> singLetter;
                        word >> singLetter;
                        string oper(1, singLetter);
                        stack.push(oper);
                        pushed = true;
                        break;
                    }
                    temp = temp + stack.pop() + " ";
                    if(!stack.isEmpty()){
                        oper = stack.peek();
                    }
                    else{
                        stack.push(ch);
                        pushed = true;
                    }
                }while(!pushed);
            }
        }
        else if (ch != "ln" && ch != "sqrt"){
            stringstream  word(ch);
            char singLetter = '\0';
            word >> singLetter;
            string oper(1, singLetter);
            stack.push(oper);
        }else{
            stringstream  word(ch);
            char singLetter = '\0';
            word >> singLetter;
            word >> singLetter;
            string oper(1, singLetter);
            stack.push(oper);
        }
    }
    while(!stack.isEmpty()){
        temp = temp + stack.pop() + " ";
    }
    return temp;
}
string calc(Stack<string>& stack, string postfix)
{
    stringstream s(postfix);
    string ch;
    double solution, oper1, oper2;
    while(s >> ch){
        if(isNumber(ch)){
            stack.push(ch);
        }
        else{
            char c[2];
            strcpy(c, ch.c_str());
            char sign = c[0];
            if(sign == '-' || sign == '+' || sign == '*' || sign == '%' || sign == '/' || sign == '^' || sign == 'g'){
                oper2 = atof(stack.pop().c_str());
                oper1 = atof(stack.pop().c_str());
            }
            else{
                oper1 = atof(stack.pop().c_str());
            }
            switch(c[0]){
            case '+':
                solution = oper1 + oper2;
                break;
            case '-':
                solution = oper1 - oper2;
                break;
            case '*':
                solution = oper1 * oper2;
                break;
            case '/':
                solution = oper1/oper2;
                break;
            case '^':
                solution = pow(oper1,oper2);
                break;
            case '%':
                {int oper1Int = (int)oper1, oper2Int = (int)oper2;
                solution = oper1Int%oper2Int;}
                break;
            case 'a':
                solution = abs(oper1);
                break;
            case 's':
                solution = sin(oper1) * TO_DEGREE;
                break;
            case 'c':
                solution = cos(oper1) * TO_DEGREE;
                break;
            case 't':
                solution = tan(oper1) * TO_DEGREE;
                break;
            case 'l':
                solution = log10(oper1);
                break;
            case 'n':
                solution = log(oper1);
                break;
            case 'g':
                solution = log10(oper2)/log10(oper1);
                break;
            case 'q':
                solution = sqrt(oper1);
                break;
            }
            stack.push(to_string(solution));
        }
    }
    //solution = atof(stack.pop().c_str());
    return stack.pop();//solution;
};
void check()
{
    Stack<string> stack;
    char ans;
    string solution;
    string expr, postfix;
    expr = "log ( 2 - sqrt ( abs ( 2 * cos ( 180 ) + ln ( 2 ) ) ) )";
    postfix = changeToPostfix(stack,expr);
    cout<<"Postfix: "<<postfix<<endl;
    solution = calc (stack,postfix);
    cout<<"Solution = "<<solution<<endl;
    expr = "9 / 2 * 2 ^ ( 5 * 2 - 6 )";
    postfix = changeToPostfix(stack,expr);
    cout<<"Postfix: "<<postfix<<endl;
    solution = calc (stack,postfix);
    cout<<"Solution = "<<solution<<endl;
    expr = "1  - 2  ^  3  ^  3  -  ( 4  +  5  *  5 )  * 7";
    postfix = changeToPostfix(stack,expr);
    cout<<"Postfix: "<<postfix<<endl;
    solution = calc (stack,postfix);
    cout<<"Solution = "<<solution<<endl;
};
