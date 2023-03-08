#include <iostream>
using namespace std;
// 1. 如果某个位置参数有默认值，那么从这个位置往后，从左向右，必须都要有默认值
int func(int a, int b = 10, int c = 20)
{
    return a + b + c;
}
// 2. 如果函数声明有默认值，函数实现的时候就不能有默认参数
int func2(int a = 10, int b = 20);
int func2(int a, int b)
{
    return a + b;
}

int main()
{
    cout << "func:" << endl;
    cout << "a = 10 -> ret = " << func(10) << endl;
    cout << "a = 10, b = 100 -> ret = " << func(10, 100) << endl;
    cout << "func2:" << endl;
    cout << "ret = " << func2() << endl;
    cout << "a = 100 -> ret = " << func2(100) << endl;
}