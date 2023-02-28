#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Building;
class MyFriend
{
private:
    Building *building;

public:
    MyFriend();
    void visit();
};

class Building
{
    // 告诉编译器 MyFriend类是Building类的好朋友，可以访问到Building类中私有内容
    friend class MyFriend;

private:
    string m_BedRoom;

public:
    string m_SittingRoom;
    Building();
};

Building::Building()
{
    this->m_BedRoom = "卧室";
    this->m_SittingRoom = "客厅";
}

MyFriend::MyFriend()
{
    building = new Building;
}

void MyFriend::visit()
{
    cout << "visit " << endl;
    cout << "visit " << endl;
}

int main()
{
    MyFriend mf;
    mf.visit();
    return 0;
}