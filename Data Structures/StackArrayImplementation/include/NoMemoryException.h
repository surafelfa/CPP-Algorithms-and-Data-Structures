#ifndef NOMEMORYEXCEPTION_H
#define NOMEMORYEXCEPTION_H
#include <string>
#include <iostream>
using namespace std;
class NoMemoryException
{
    public:
        NoMemoryException(const string& msg)
        {
            this->msg = msg;
        }
        void print()
        {
            cout<<msg<<endl;
        }

    protected:
        string msg;

    private:
};

#endif // NOMEMORYEXCEPTION_H
