#include <iostream>
#include <string>
using namespace std;
// string查找和替换
int main()
{ // 查找
    string str1 = "abcdefgde";
    string str = "de";
    char *s = "cd";
    char c = 'd';
    cout << str1.find(str) << endl;
    cout << str1.find(c) << endl;
    cout << str1.find(c, 4) << endl;
    cout << str1.find(s, 0, 1) << endl;

    // 替换
    str1 = "abcdefgde";
    str1.replace(1, 3, "1111");
    cout << "str1 = " << str1 << endl;

    return 0;
}