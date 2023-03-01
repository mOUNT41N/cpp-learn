#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Building;
class MyFriend;

class MyFriend
{
private:
    Building *building;

public:
    MyFriend();
    void visit();
    void visit2();
};

class Building
{
    // 告诉编译器  goodGay类中的visit成员函数 是Building好朋友，可以访问私有内容
    friend void MyFriend::visit();

private:
    string m_bed;

public:
    string m_sit;
    Building();
};

inline MyFriend::MyFriend()
{
    building = new Building;
}

inline Building::Building()
{
    this->m_sit = "客厅";
    this->m_bed = "卧室";
}

void MyFriend::visit()
{
    cout << "this is visit" << endl;
    cout << "Visit " << building->m_sit << endl;
    cout << "Visit " << building->m_bed << endl;
}

void MyFriend::visit2()
{
    cout << "this is visit2" << endl;
    cout << "Visit " << building->m_sit << endl;
    // cout << "Visit " << building->m_bed << endl;
}

int main()
{
    MyFriend mf;
    mf.visit2();
    mf.visit();
    return 0;
}