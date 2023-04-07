#include <iostream>
#include <string>
using namespace std;
// 类模板
template <class NameType, class AgeType = int>
class Person
{
public:
    NameType m_name;
    AgeType m_age;

public:
    Person(NameType name, AgeType age) : m_name(name), m_age(age) {}
    void showPerson()
    {
        cout << "name:" << this->m_name << " age:" << this->m_age << endl;
    }
};

int main()
{
    // 类模板没有自动类型推导的使用方式
    // Person p("mountain", 22); // 错误 类模板使用时候，不可以用自动类型推导
    Person<string, int> p1("mountain", 22); // 必须使用显示指定类型的方式，使用类模板
    p1.showPerson();

    Person<string> p2("mountain", 23); // 类模板中的模板参数列表 可以指定默认参数
    p2.showPerson();
    return 0;
}