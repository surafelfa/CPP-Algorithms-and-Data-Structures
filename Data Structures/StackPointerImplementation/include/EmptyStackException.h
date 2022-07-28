#ifndef EMPTYSTACKEXCEPTION_H
#define EMPTYSTACKEXCEPTION_H
#include <bits/stdc++.h>
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
};

#endif // EMPTYSTACKEXCEPTION_H
