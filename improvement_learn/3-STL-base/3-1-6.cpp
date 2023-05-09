#include <iostream>
#include <string>
using namespace std;
// 字符串比较

int main()
{
    string s1 = "hello";
    string s2 = "aello";
    string s3 = "hello";
    string s4 = "zello";

    int ret1 = s1.compare(s2);
    int ret2 = s1.compare(s3);
    int ret3 = s1.compare(s4);
    cout << "ret1\tret2\tret3" << endl;
    cout << ret1 << "\t" << ret2 << "\t" << ret3 << endl;

    return 0;
}