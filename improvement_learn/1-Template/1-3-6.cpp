#include <iostream>
#include <string>
using namespace std;

// 类模板中成员函数类外实现
template <class T1, class T2>
class Person
{
public:
    T1 m_name;
    T2 m_age;

public:
    Person(T1 name, T2 age) : m_name(name), m_age(age) {}
    void showPerson();
};

// 成员函数 类外实现
template <class T1, class T2>
void Person<T1, T2>::showPerson()
{
    cout << "姓名:" << this->m_name << " 年龄:" << this->m_age << endl;
}

int main()
{
    Person<string, int> p("Tom", 20);
    p.showPerson();
    return 0;
}