#include <iostream>
#include <fstream>
using namespace std;

class Person
{
public:
    char m_name[64];
    char m_sex[64];
    int m_age;
};

int main()
{
    ifstream ifs("5-2-1.txt", ios::in | ios::binary);
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
    }
    Person p;
    ifs.read((char *)&p, sizeof(p));

    cout << "Name:" << p.m_name << " Sex:" << p.m_sex << " Age:" << p.m_age << endl;
    return 0;
}