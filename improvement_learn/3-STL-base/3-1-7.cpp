#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "hello world";
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i];
    }
    cout << endl;

    for (int i = 0; i < str.size(); i++)
    {
        cout << str.at(i);
    }
    cout << endl;

    // 字符修改
    str[0] = 'm';
    str.at(2) = 'n';
    cout << str << endl;
    return 0;
}