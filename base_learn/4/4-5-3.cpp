#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class MyInteger
{
private:
    int m_num;

public:
    MyInteger() { m_num = 0; }
    MyInteger(int n) : m_num(n) {}

    // 前置++
    MyInteger operator++()
    {
        m_num += 1;
        return *this;
    }
    // 后置++
    MyInteger operator++(int)
    {
        // 记录当前本身的值，然后让本身的值加1，但是返回的是以前的值，达到先返回后++；
        MyInteger temp = *this;
        m_num += 1;
        return temp;
    }
    friend ostream &operator<<(ostream &os, const MyInteger &m);
};

ostream &operator<<(ostream &os, const MyInteger &m)
{
    return os << "num=" << m.m_num;
}

int main()
{
    MyInteger i1(10);
    cout << ++i1 << endl;
    cout << i1 << endl;
    cout << i1++ << endl;
    cout << i1 << endl;
    return 0;
}