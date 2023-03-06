#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream ofs;
    ofs.open("5-1-1.txt", ios::out);
    ofs << "Name:mountain" << endl;
    ofs << "Age: 23" << endl;
    ofs.close();
    return 0;
}