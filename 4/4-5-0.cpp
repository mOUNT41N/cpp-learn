#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Person
{
public:
    int m_a;
    int m_b;

public:
    Person(){};
    Person(int a, int b) : m_a(a), m_b(b) {}
};

// 如果输出内容为Private 内容需要使用友元函数声明
ostream &operator<<(ostream &os, const Person &p)
{
    return os << "a=" << p.m_a << " b=" << p.m_b;
}
int main()
{
    Person p1(10, 10);
    Person p2(20, 20);
    cout << "p1:" << p1 << endl;
    cout << "p2:" << p2 << endl;
    return 0;
}