#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class MyStringPrintln
{
public:
    void operator()(string text)
    {
        cout << text << endl;
    }
};

class MyIntAdd
{
public:
    int operator()(int a, int b)
    {
        return a + b;
    }
};

int main()
{
    MyStringPrintln mspl;
    mspl("hello ");
    MyIntAdd mia;
    cout << mia(1010, 14) << endl;
    return 0;
}
