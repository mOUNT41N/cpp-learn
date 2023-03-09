#include <iostream>
#include <string>
#include <ctime>
using namespace std;
class Person
{
private:
    int m_A;
    int m_B;

public:
    Person(int a, int b)
    {
        this->m_A = a;
        this->m_B = b;
    }
    // 成员函数 实现不了  p << cout 不是我们想要的效果
    // void operator<<(Person& p){
    // }
    friend ostream &operator<<(ostream &out, Person &p);
};

// 全局函数实现左移重载
// ostream对象只能有一个
ostream &operator<<(ostream &os, Person &p)
{
    os << "a:" << p.m_A << " b:" << p.m_B;
    return os;
}

int main()
{

    Person p1(10, 20);
    cout << p1 << endl
         << "hello world" << endl; // 链式编程
    return 0;
}