#ifndef EMPTYQUEUEEXCEPTION_H
#define EMPTYQUEUEEXCEPTION_H
#include <bits/stdc++.h>
using namespace std;
class EmptyQueueException
{
    public:
        EmptyQueueException(const string& msg) {
            this->msg = msg;
        }
        void print()
        {
            cout<<msg<<endl;
        }

    protected:
        string msg;
};

#endif // EMPTYQUEUEEXCEPTION_H
