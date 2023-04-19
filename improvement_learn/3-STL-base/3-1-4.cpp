#include <iostream>
#include <string>
using namespace std;

// 字符串拼接
int main()
{
    string str1 = "I";
    str1 += " am ";
    cout << "str1 = " << str1 << endl;

    string str2 = "iron man.";
    str1 += str2;
    cout << "str1 = " << str1 << endl;

    string str3;
    str3.append("I love you 3000 years");
    str3.append("!!!! ....", 4);
    cout << "str3 = " << str3 << endl;
    string str4;
    str4.append(str1, 5, 8);// 从下标5位置开始 ，截取8个字符，拼接到字符串末尾
    cout << "str4 = " << str4 << endl;

    return 0;
}