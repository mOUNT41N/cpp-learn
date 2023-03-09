#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Person
{
private:
    int *m_age;

public:
    Person(int age) { m_age = new int(age); }
    Person &operator=(Person &p)
    {
        if (m_age != NULL)
        {
            delete m_age;
            m_age = nullptr;
        }
        // 编译器提供的代码是浅拷贝
        // m_Age = p.m_Age;

        // 提供深拷贝 解决浅拷贝的问题
        m_age = new int(*p.m_age);
        return *this;
    }
    ~Person()
    {
        if (m_age != nullptr)
        {
            delete m_age;
            m_age = nullptr;
        }
    }
    friend ostream &operator<<(ostream &os, Person &p);
};
ostream &operator<<(ostream &os, Person &p)
{
    return os << "age=" << *p.m_age;
}

int main()
{
    Person p1(18);
    Person p2(20);
    Person p3(30);
    p3 = p2 = p1;
    cout << p1 << " " << &p1 << endl;
    cout << p2 << " " << &p2 << endl;
    cout << p3 << " " << &p3 << endl;
}