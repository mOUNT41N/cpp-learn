#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    string m_name;
    int m_age;

    Person(string name, int age) : m_name(name), m_age(age) {}
};

// 普通函数模板
template <typename T>
bool myCompare(T &a, T &b)
{
    if (a == b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 具体化，显示具体化的原型和定意思以template<>开头，并通过名称来指出类型
// 具体化优先于常规模板
template <>
bool myCompare(Person &p1, Person &p2)
{
    if (p1.m_name == p2.m_name && p1.m_age == p2.m_age)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int a = 10;
    int b = 20;
    // 内置数据类型可以直接使用通用的函数模板
    bool ret = myCompare(a, b);
    if (ret)
    {
        cout << "a == b " << endl;
    }
    else
    {
        cout << "a != b " << endl;
    }

    Person p1("Tom", 10);
    Person p2("Tom", 10);
    // 自定义数据类型，不会调用普通的函数模板
    // 可以创建具体化的Person数据类型的模板，用于特殊处理这个类型
    ret = myCompare(p1, p2);
    if (ret)
    {
        cout << "p1 == p2 " << endl;
    }
    else
    {
        cout << "p1 != p2 " << endl;
    }

    return 0;
}