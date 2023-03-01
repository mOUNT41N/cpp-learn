#include <iostream>
#include <string>
#include <ctime>
using namespace std;
class Father
{
public:
    int m_a;

protected:
    int m_b;

private:
    int m_c;

public:
    Father()
    {
        m_a = 10;
        m_b = 20;
        m_c = 30;
    }
};

class Son1 : public Father
{
public:
    Son1()
    {
        m_a = 11;
        m_b = 21;
    }
    void func()
    { // m_a public 权限 m_b protected权限 m_c 不可访问
        cout << m_a << " " << m_b << endl;
        // m_c 不可访问
    }
};

class Son2 : protected Father
{
public:
    Son2()
    {
        m_a = 12;
        m_b = 22;
    }
    void func()
    { // m_a m_b protected权限 m_c 不可访问
        cout << m_a << " " << m_b << endl;
    }
};

class Son3 : private Father
{
public:
    void func()
    { // m_a m_b private权限 m_c 不可访问
        cout << m_a << " " << m_b << endl;
    }
};

class GrandSon3 : public Son3
{
public:
    void func()
    {
        // Son3是私有继承，所以继承Son3的属性在GrandSon3中都无法访问到
    }
};

int main()
{
    Son1 s1;
    Son2 s2;
    Son3 s3;
    s1.func();
    s2.func();
    s3.func();
    return 0;
}