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

    friend void goodFriend(Building &building)
    {
        cout << "好基友正在访问： " << building.m_SittingRoom << endl;
        cout << "好基友正在访问： " << building.m_BedRoom << endl;
    }
};