#include <iostream>
using namespace std;

int &test1()
{ // 不能返回局部变量引用
    int a = 10;
    return a; // warning:reference to local variable 'a' returned
}

int &test2()
{ // 返回静态变量引用
    static int a = 10;
    return a;
}

int main()
{
    // 不能返回局部变量的引用
    // int &ref = test1();
    // cout << "test1() = " << test1() << endl;
    // cout << "ref = " << ref << endl;

    // 如果函数做左值，那么必须返回引用
    int &ref2 = test2();
    cout << "test2() = " << test2() << endl;
    cout << "ref2 = " << ref2 << endl;
    test2() = 1000;
    cout << "test2() = " << test2() << endl;
    cout << "ref2 = " << ref2 << endl;

    return 0;
}