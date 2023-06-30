#include <iostream>
#include <string>
using namespace std;

// 字符串插入和删除
int main()
{
    string str = "hello world";
    str.insert(0, "mountain ");
    cout << str << endl;
    str.erase(0, 4);
    cout << str << endl;
    str.erase(5);
    cout << str << endl;
    return 0;
}