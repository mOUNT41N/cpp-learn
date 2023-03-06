#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// 抽象制作饮品
class AbstractDrinking
{
public:
    virtual void Boil() = 0;         // 烧水
    virtual void Brew() = 0;         // 冲泡
    virtual void PourInCup() = 0;    // 倒入杯中
    virtual void PutSomething() = 0; // 加入辅料
    void MakeDrink()
    { // 规定流程
        Boil();
        Brew();
        PourInCup();
        PutSomething();
    }
};

class Coffee : public AbstractDrinking
{
public:
    virtual void Boil()
    {
        cout << "Coffee Boil" << endl;
    }
    virtual void Brew()
    {
        cout << "Coffee Brew!" << endl;
    }
    virtual void PourInCup()
    {
        cout << "Coffee PouRInCup" << endl;
    }
    virtual void PutSomething()
    {
        cout << "Coffee PutSomething" << endl;
    }
};

void DoWork(AbstractDrinking &drink)
{
    drink.MakeDrink();
}

int main()
{
    Coffee c;
    DoWork(c);
    return 0;
}