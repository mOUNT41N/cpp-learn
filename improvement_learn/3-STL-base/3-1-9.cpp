#include <iostream>
#include <string>
using namespace std;

//子串
void test01()
{

	string str = "abcdefg";
	string subStr = str.substr(1, 3);
	cout << "subStr = " << subStr << endl;

	string email = "hello@sina.com";
	int pos = email.find("@");
	string username = email.substr(0, pos);
	cout << "username: " << username << endl;

}

int main() {
    string str = "Moutain";
    string sub_str = str.substr(0,4);
    cout << "sub_str = " << sub_str << endl;

    string email = "mountian@126.com";
    int pos = email.find("@");
    string username = email.substr(0, pos);
    cout << "username: " << username << endl;

	return 0;
}