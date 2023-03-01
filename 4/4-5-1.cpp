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
    Person &operator+=(const Person &p);
    // Person operator+(const Person &p); 成员函数运算符重载

    friend Person &__doapl(Person *, const Person &);
};

Person &__doapl(Person *ths, const Person &p)
{
    ths->m_a += p.m_a;
    ths->m_b += p.m_b;
    return *ths;
}

inline Person &Person::operator+=(const Person &p)
{
    // 返回临时变量 错误
    // return Person(this->m_a + p.m_a, this->m_b + p.m_b);
    return __doapl(this, p);
}
// inline Person Person::operator+(const Person &p)
// {
//     return Person(this->m_a + p.m_a, this->m_b + p.m_b);
// }

inline Person operator+(const Person &p1, const Person &p2)
{
    return Person(p1.m_a + p2.m_a, p1.m_b + p2.m_b);
}
inline Person operator+(const Person &p1, const int v)
{
    return Person(p1.m_a + v, p1.m_b + v);
}
inline Person operator+(const int v, const Person &p1)
{
    return Person(p1.m_a + v, p1.m_b + v);
}

ostream &operator<<(ostream &os, const Person &p)
{
    return os << "a=" << p.m_a << " b=" << p.m_b;
}
int main()
{
    Person p1(10, 10);
    Person p2(20, 20);
    Person p3 = p1 + p2;
    Person p4 = p1 + 30;
    p1 += p3;
    cout << "p1:" << p1 << endl;
    cout << "p3:" << p3 << endl;
    cout << "p4:" << p4 << endl;
    return 0;
}