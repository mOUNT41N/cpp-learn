#include <iostream>
using namespace std;
int *func()
{
    int *a = new int(10);
    cout << a << endl;
    return a;
}

int main()
{
    int *p = func();
    cout << p << endl;
    cout << *p << endl;
    return 0;
}