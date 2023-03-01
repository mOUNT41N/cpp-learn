#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Animal
{
public:
    int m_Age;
};

// 继承前加virtual关键字后，变为虚继承
// 此时公共的父类Animal称为虚基类
class Sheep : virtual public Animal
{
};
class Tuo : virtual public Animal
{
};
class SheepTuo : public Sheep, public Tuo
{
};

int main()
{
    SheepTuo st;
    st.Sheep::m_Age = 11;
    cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
    cout << "st.Tuo::m_Age = " << st.Tuo::m_Age << endl;
    cout << "st.m_Age = " << st.m_Age << endl;

    st.Tuo::m_Age = 12;
    cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
    cout << "st.Tuo::m_Age = " << st.Tuo::m_Age << endl;
    cout << "st.m_Age = " << st.m_Age << endl;

    return 0;
}