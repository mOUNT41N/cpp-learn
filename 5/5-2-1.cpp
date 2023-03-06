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
    ofstream ofs("5-2-1.txt", ios::out | ios::binary);
    // ofs.open("5-2-1.txt", ios::out | ios::binary)
    Person p = {"mountain", "male", 23};
    ofs.write((const char *)&p, sizeof(p));
    ofs.close();
}