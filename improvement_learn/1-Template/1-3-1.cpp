#include <iostream>
#include <string>
using namespace std;
// 类模板
template <class NameType, class AgeType>
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
    // 指定NameType 为string类型，AgeType 为 int类型
    Person<string, int> p("mountain", 22);
    p.showPerson();
    return 0;
}