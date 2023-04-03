#include <iostream>
#include <iomanip>
using namespace std;

// 交换整型函数
void swapInt(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 交换浮点型函数
void swapDouble(double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp;
}

// 利用模板提供通用的交换函数
template <typename T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 10;
    int b = 20;
    double c = 10.1;
    double d = 20.1;
    swapInt(a, b);
    swapDouble(c, d);
    cout << "----- swapint swap double -----" << endl;
    cout << "a:" << a << " b:" << b << endl;
    cout << "c:" << fixed << setprecision(1) << c << " d:" << d << endl;

    mySwap(a, b);
    mySwap(c, d);
    cout << "----- my swap -----" << endl;
    cout << "a:" << a << " b:" << b << endl;
    cout << "c:" << fixed << setprecision(1) << c << " d:" << d << endl;
    return 0;
}