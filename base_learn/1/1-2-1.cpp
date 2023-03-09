#include <iostream>
using namespace std;
static int b = 10;
int *func()
{
    int a = 10;
    // return &a; // address of local variable 'a' returned
    return &b;
}

int main()
{
    int *p = func();
    cout << p << endl;
    cout << *p << endl;
    return 0;
}