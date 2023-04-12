#include <iostream>
#include <string>
using namespace std;

// 全局函数配合友元  类外实现 - 先做函数模板声明，下方在做函数模板定义,再做友元
template <class T1, class T2>
class Person;

// 如果声明了函数模板，可以将实现写到后面，否则需要将实现体写到类的前面让编译器提前看到
// template<class T1, class T2> void printPerson2(Person<T1, T2> & p);

template <class T1, class T2>
void printPerson2(Person<T1, T2> &p)
{
    cout << "类外实现 ---- 姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
}
template <class T1, class T2>
class Person
{
    // 1、全局函数配合友元   类内实现
    friend void printPerson(Person<T1, T2> &p)
    {
        cout << "类内实现" << endl;
        cout << "姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
    }
    // 全局函数配合友元  类外实现
    friend void printPerson2<>(Person<T1, T2> &p);

public:
    Person(T1 name, T2 age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

private:
    T1 m_Name;
    T2 m_Age;
};

int main()
{
    Person<string, int> p1("mt", 22);
    Person<string, int> p2("Jerry", 30);
    printPerson(p1);
    printPerson2(p2);
    return 0;
}