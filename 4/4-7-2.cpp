#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// 普通实现
class Calculator
{
public:
    int getResult(string oper)
    {
        if (oper == "+")
        {
            return m_Num1 + m_Num2;
        }
        else if (oper == "-")
        {
            return m_Num1 - m_Num2;
        }
        else if (oper == "*")
        {
            return m_Num1 * m_Num2;
        }
        // 如果要提供新的运算，需要修改源码
    }

public:
    int m_Num1;
    int m_Num2;
};

// 多态实现
// 抽象计算器类
// 多态优点：代码组织结构清晰，可读性强，利于前期和后期的扩展以及维护

class AbstractCalculator
{
public:
    int m_num1;
    int m_num2;
    virtual int getResult() { return 0; }

    AbstractCalculator()
    {
        m_num1 = 0;
        m_num2 = 0;
    }
    AbstractCalculator(const int a, const int b) : m_num1(a), m_num2(b) {}
};

class AddCalculator : public AbstractCalculator
{
public:
    AddCalculator(const int a, const int b) : AbstractCalculator(a, b) {}
    int getResult() { return m_num1 + m_num2; }
};

class SubCalculator : public AbstractCalculator
{
public:
    SubCalculator(const int a, const int b) : AbstractCalculator(a, b) {}
    int getResult() { return m_num1 - m_num2; }
};
class MulCalculator : public AbstractCalculator
{
public:
    MulCalculator(const int a, const int b) : AbstractCalculator(a, b) {}
    int getResult() { return m_num1 * m_num2; }
};

int main()
{
    Calculator c;
    c.m_Num1 = 10;
    c.m_Num2 = 10;
    cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl;
    cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;
    cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
    AddCalculator a(10, 20);
    SubCalculator s(20, 10);
    MulCalculator m(10, 3);

    cout << a.m_num1 << " + " << a.m_num2 << " = " << a.getResult() << endl;
    cout << s.m_num1 << " - " << s.m_num2 << " = " << s.getResult() << endl;
    cout << m.m_num1 << " * " << m.m_num2 << " = " << m.getResult() << endl;
    return 0;
}