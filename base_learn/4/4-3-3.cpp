#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// 空指针访问成员函数
class Person
{
public:
    void ShowClassName()
    {
        cout << "我是Person类!" << endl;
    }
    void ShowPerson()
    {
        if (this == NULL)
        {
            return;
        }
        cout << mAge << endl;
    }

public:
    int mAge;
};

int main()
{
    Person *p = NULL;
    p->ShowClassName(); // 空指针，可以调用成员函数
    p->ShowPerson();    // 但是如果成员函数中用到了this指针，就不可以了
    return 0;
}