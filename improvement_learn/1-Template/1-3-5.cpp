#include <iostream>
#include <string>
using namespace std;

template <class T>
class Base
{
public:
    T temp;
};

// class son : public Base // 错误，c++编译需要给子类分配内存，必须知道父类中T的类型才可以向下继承
class son1 : public Base<int>
{
public:
    son1()
    {
        cout << typeid(this->temp).name() << endl;
    }
};
template <class T1, class T2>
class son2 : public Base<T2>
{
public:
    son2()
    {
        cout << typeid(T1).name() << endl;
        cout << typeid(T2).name() << endl;
    }
};

int main()
{
    son1 s1;
    son2<int, string> s2;
    return 0;
}