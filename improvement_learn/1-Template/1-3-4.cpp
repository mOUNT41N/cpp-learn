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

// 1 指定传入的类型
void printPerson1(Person<string, int> &p)
{
    p.showPerson();
}

// 2 参数模板化
template <class T1, class T2>
void printPerson2(Person<T1, T2> &p)
{
    cout << "T1的类型为:" << typeid(T1).name() << endl;
    cout << "T2的类型为:" << typeid(T2).name() << endl;
    p.showPerson();
}

// 3 整个类模板化
template <class T>
void printPerson3(T &p)
{
    cout << "T的类型为: " << typeid(T).name() << endl;
    p.showPerson();
}

int main()
{
    Person<string, int> p("mountain", 23);
    printPerson1(p);
    printPerson2(p);
    printPerson3(p);
    Person<string, string> p1("mountain", "22");
    // printPerson1(p1); 指定类型参数为<string , int>
    printPerson2(p1);
    printPerson3(p1);
    return 0;
}