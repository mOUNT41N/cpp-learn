#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Base
{
public:
    // 纯虚函数
    // 类中只要有一个纯虚函数就称为抽象类
    // 抽象类无法实例化对象
    // 子类必须重写父类中的纯虚函数，否则也属于抽象类
    virtual void func() = 0;
};

class Son : public Base
{
public:
    virtual void func()
    {
        cout << "func调用" << endl;
    };
};

int main()
{
    Base *base = NULL;
    // base = new Base; // 错误，抽象类无法实例化对象
    Son s;
    s.func();

    return 0;
}