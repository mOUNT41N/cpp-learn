#include <iostream>
using namespace std;
void showValue(const int &v)
{
    // v += 10; 表达式必须是可修改的左值
    cout << v << endl;
}

int main()
{
    // int& ref = 10;  引用本身需要一个合法的内存空间，因此这行错误
    // 加入const就可以了，编译器优化代码，int temp = 10; const int& ref = temp;
    const int &ref = 10;

    // ref = 100; 表达式必须是可修改的左值
    cout << ref << endl;
    // 函数中利用常量引用防止误操作修改实参
    int a = 10;
    showValue(a);
    return 0;
}