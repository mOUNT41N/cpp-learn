#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Animal
{
public:
    // Speak函数就是虚函数
    // 函数前面加上virtual关键字，变成虚函数，那么编译器在编译的时候就不能确定函数调用了。
    virtual void Speak()
    {
        cout << "Animal speaking" << endl;
    }
};

class Cat : public Animal
{
public:
    void Speak()
    {
        cout << "Cat speaking" << endl;
    }
};
class Dog : public Animal
{
public:
    void Speak()
    {
        cout << "Dog speaking" << endl;
    }
};

// 我们希望传入什么对象，那么就调用什么对象的函数
// 如果函数地址在编译阶段就能确定，那么静态联编
// 如果函数地址在运行阶段才能确定，就是动态联编

void DoSpeak(Animal &animal)
{
    animal.Speak();
}
// 多态满足条件：
// 1、有继承关系
// 2、子类重写父类中的虚函数
// 多态使用：
// 父类指针或引用指向子类对象
int main()
{
    Cat c;
    Dog d;
    DoSpeak(c);
    DoSpeak(d);
    return 0;
}