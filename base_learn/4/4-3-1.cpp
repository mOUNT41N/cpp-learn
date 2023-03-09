#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Person
{
public:
    Person()
    {
        mA = 0;
    }
    int mA;        // 非静态成员变量占对象空间
    static int mB; // 静态成员变量不占对象空间
    void func()
    { // 函数也不占对象空间，所有函数共享一个函数实例
        cout << "mA:" << this->mA << endl;
    }
    static void sfunc()
    { // 静态成员函数也不占对象空间
    }
};

int main()
{
    cout << sizeof(Person) << endl;
    return 0;
}