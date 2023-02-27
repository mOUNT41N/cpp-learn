#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Person
{
public:
    int m_A;
    mutable int m_B; // 可修改 可变的

    Person()
    {
        m_A = 0;
        m_B = 1;
    }

    // this指针的本质是一个指针常量，指针的指向不可修改
    // 如果想让指针指向的值也不可以修改，需要声明常函数
    void ShowPerson() const
    {
        // const Type *const pointer;
        // this = NULL;    // 不能修改指针的指向 Person* const this;
        // this->mA = 100; // 但是未声明常函数的情况下，this指针指向的对象的数据是可以修改的

        // const修饰成员函数，表示指针指向的内存空间的数据不能修改，除了mutable修饰的变量
        this->m_B = 100;
    }
    void MyFunc() const
    {
        cout << "MyFunc" << endl;
        // mA = 10000;
    }
};

int main()
{
    const Person p; // const修饰对象  常对象
    cout << p.m_A << " " << p.m_B << endl;
    // p.mA = 100; //常对象不能修改成员变量的值,但是可以访问
    p.ShowPerson();
    cout << p.m_A << " " << p.m_B << endl;
    p.m_B = 10; // 但是常对象可以修改mutable修饰成员变量
    cout << p.m_A << " " << p.m_B << endl;
    p.MyFunc();
    return 0;
}