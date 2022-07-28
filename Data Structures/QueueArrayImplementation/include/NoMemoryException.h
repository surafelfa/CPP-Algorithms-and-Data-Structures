#ifndef NOMEMORYEXCEPTION_H
#define NOMEMORYEXCEPTION_H
#include <bits/stdc++.h>
using namespace std;
class NoMemoryException
{
    public:
        NoMemoryException(const string& msg)
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

#endif // NOMEMORYEXCEPTION_H
