#ifndef EMPTYSTACKEXCEPTION_H
#define EMPTYSTACKEXCEPTION_H
#include <string>
#include <iostream>
using namespace std;
class EmptyStackException
{
    public:
        EmptyStackException(const string& msg)
        {
            this->msg = msg;
        };
        void print()
        {
            cout<<msg<<endl;
        }

    protected:
        string msg;

    private:
};

#endif // EMPTYSTACKEXCEPTION_H
