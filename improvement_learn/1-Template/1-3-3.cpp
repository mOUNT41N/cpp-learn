#include <iostream>
#include <string>
using namespace std;

class Person1
{
public:
    void showPerson1()
    {
        cout << "Person1 show" << endl;
    }
};

class Person2
{
public:
    void showPerson2()
    {
        cout << "Person2 show" << endl;
    }
};

template <class T>
class MyClass
{
public:
    T obj;
    // 类模板中的成员函数，并不是一开始就创建的，而是在模板调用时再生成

    void fun1() { obj.showPerson1(); }
    void fun2() { obj.showPerson2(); }
};

int main()
{
    MyClass<Person1> p1;
    p1.fun1();
    // p1.fun2(); // 编译会出错，说明函数调用才会去创建成员函数
    MyClass<Person2> p2;
    p2.fun2();
    return 0;
}