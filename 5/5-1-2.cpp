#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

int main()
{
    ifstream ifs;
    ifs.open("5-1-1.txt", ios::in);

    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return 0;
    }
    cout << "===== 1 =====" << endl;
    char buf1[1024] = {0};
    while (ifs >> buf1)
    {
        cout << buf1 << endl;
    }
    ifs.close();

    cout << "===== 2 =====" << endl;
    ifs.open("5-1-1.txt", ios::in);
    char buf2[1024] = {0};
    while (ifs.getline(buf2, sizeof(buf2)))
    {
        cout << buf2 << endl;
    }
    ifs.close();

    cout << "===== 3 =====" << endl;
    ifs.open("5-1-1.txt", ios::in);
    string buf3;
    while (getline(ifs, buf3))
    {
        cout << buf3 << endl;
    }
    ifs.close();

    cout << "===== 4 =====" << endl;
    ifs.open("5-1-1.txt", ios::in);
    char c;
    while ((c = ifs.get()) != EOF)
    {
        cout << c;
    }
    ifs.close();

    return 0;
}