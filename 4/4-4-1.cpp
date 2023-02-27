#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Building
{
private:
    string m_BedRoom;

public:
    string m_SittingRoom;

    Building()
    {
        this->m_SittingRoom = "客厅";
        this->m_BedRoom = "卧室";
    }

    friend void goodFriend(Building &building)
    {
        cout << "好基友正在访问： " << building.m_SittingRoom << endl;
        cout << "好基友正在访问： " << building.m_BedRoom << endl;
    }
};

int main()
{
    Building b;
    goodFriend(b);
    return 0;
}