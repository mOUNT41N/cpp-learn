#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Person
{
public:
    int age;

    Person(int age)
    { // 1、当形参和成员变量同名时，可用this指针来区分
        this->age = age;
    }
    Person &PersonAddPerson(Person p)
    {
        this->age += p.age;
        return *this;
    }
};

int main()
{
    Person p1(10);
    cout << "p1.age = " << p1.age << endl;
    Person p2(9);
    cout << "p2.age = " << p2.age << endl;
    p2.PersonAddPerson(p1); // 9+10 = 19
    cout << "p2.age = " << p2.age << endl;
    p2.PersonAddPerson(p1).PersonAddPerson(p2); // 19+10+(19+10) = 58
    cout << "p2.age = " << p2.age << endl;
    return 0;
}