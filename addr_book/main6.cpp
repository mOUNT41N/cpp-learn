#include <iostream>
using namespace std;

// 宏定义
const int MAX_NUM = 1000; // 最大人数

// 结构体
struct Person // 人
{
    string m_Name;  // 名称
    int m_Sex;      // 性别
    int m_Age;      // 年龄
    string m_Phone; // 电话
    string m_Addr;  // 地址
};

struct Addressbook // 通讯录
{
    struct Person personArray[MAX_NUM]; // 通讯录中保存的联系人数组
    int m_Size;                         // 通讯录中人员个数
};
void init(Addressbook &addr_book);                                 // 初始化
void showMenu();                                                   // 菜单界面
void select(Addressbook &addr_book);                               // 选择界面
void addPerson2AddrBook(Addressbook &addr_book, int person_index); // 添加条目
void addAddrBook(Addressbook &addr_book);                          // 通讯录添加
void showAddrBook(Addressbook addr_book);                          // 通讯录展示
void deletePerson(Addressbook &addr_book);                         // 删除指定联系人信息
int isExist(Addressbook addr_book, string name);                   // 判断是否存在查询的人员
void findPerson(Addressbook &addr_book);                           // 查找指定联系人

int main()
{
    // 创建通讯录
    Addressbook addr_book; // 通讯录

    init(addr_book);
    showMenu();
    select(addr_book);
    return 0;
}

void init(Addressbook &addr_book)
{ // 初始化
    // 初始化通讯录中人数
    addr_book.m_Size = 0;
}

void showMenu()
{ // 菜单界面
    cout << "***************************" << endl;
    cout << "*****  1、添加联系人  *****" << endl;
    cout << "*****  2、显示联系人  *****" << endl;
    cout << "*****  3、删除联系人  *****" << endl;
    cout << "*****  4、查找联系人  *****" << endl;
    cout << "*****  5、修改联系人  *****" << endl;
    cout << "*****  6、清空联系人  *****" << endl;
    cout << "*****  0、退出通讯录  *****" << endl;
    cout << "***************************" << endl;
}

void select(Addressbook &addr_book)
{ // 选择界面
    int select = 0;
    while (true)
    {
        cin >> select;
        switch (select)
        {
        case 1: // 添加联系人
            addAddrBook(addr_book);
            break;
        case 2: // 显示联系人
            showAddrBook(addr_book);
            break;
        case 3: // 删除联系人
            deletePerson(addr_book);
            break;
        case 4: // 查找联系人
            findPerson(addr_book);
            break;
        case 5: // 修改联系人
            break;
        case 6: // 清空联系人
            break;
        case 0: // 退出通讯录
            cout << "退出通讯录 欢迎下次使用" << endl;
            return;
            break;
        default:
            break;
        }
        showMenu();
    }
}

void addPerson2AddrBook(Addressbook &addr_book, int person_index)
{ // 添加条目 可以增加空格输入条件
    // 姓名
    string name;
    cout << "----------姓名----------" << endl;
    cout << "请输入姓名：";
    cin >> name;
    addr_book.personArray[person_index].m_Name = name;

    // 性别
    cout << "----------性别----------" << endl;
    cout << "1 -- 男 ";
    cout << "2 -- 女" << endl;
    cout << "请输入性别：" << endl;
    int sex = -1;
    cin >> sex;
    // 判断性别是否符合输入
    while (true)
    {
        if (sex == 1 || sex == 2)
        {
            addr_book.personArray[person_index].m_Sex = sex;
            break;
        }
        cout << "输入有误，请重新输入:" << endl;
        cin >> sex;
    }

    // 年龄 可以增加判断（>=0）
    cout << "请输入年龄：" << endl;
    int age = 0;
    cin >> age;
    addr_book.personArray[person_index].m_Age = age;

    // 联系电话 可以增加电话合理性判断（正则表达式）
    cout << "请输入联系电话：" << endl;
    string phone = "";
    cin >> phone;
    addr_book.personArray[person_index].m_Phone = phone;

    // 家庭住址
    cout << "请输入家庭住址：" << endl;
    string address;
    cin >> address;
    addr_book.personArray[person_index].m_Addr = address;

    // 更新通讯录
    addr_book.m_Size++;
    cout << "添加成功" << endl;
    // system("cls"); // 清屏
}

void addAddrBook(Addressbook &addr_book)
{ // 通讯录添加
    // 满了
    int person_index = addr_book.m_Size;
    if (person_index == MAX_NUM)
    {
        cout << "通讯录已满，无法添加" << endl;
    }
    else // 没满
    {    // 添加 结构体Person
        addPerson2AddrBook(addr_book, person_index);
    }
}

void showAddrBook(Addressbook addr_book)
{ // 通讯录展示
    int num = addr_book.m_Size;
    if (num == 0)
    {
        cout << "当前记录为空" << endl;
    }
    else
    {
        cout << "姓名\t性别\t年龄\t电话\t住址\t" << endl;
        for (int i = 0; i < num; ++i)
        {
            cout << addr_book.personArray[i].m_Name << "\t";
            cout << addr_book.personArray[i].m_Sex << "\t";
            cout << addr_book.personArray[i].m_Age << "\t";
            cout << addr_book.personArray[i].m_Phone << "\t";
            cout << addr_book.personArray[i].m_Addr << "\t";
            cout << endl;
        }
    }
}

void deletePerson(Addressbook &addr_book)
{ // 删除指定联系人信息
    cout << "请输入您要删除的联系人:";
    string name;
    cin >> name;

    int ret = isExist(addr_book, name);
    if (ret == -1)
    {
        cout << "查无此人" << endl;
    }
    else
    {
        for (int i = ret; i < addr_book.m_Size; ++i)
        {
            addr_book.personArray[i] = addr_book.personArray[i + 1];
        }
        addr_book.m_Size--;
        cout << "删除成功" << endl;
    }
}
int isExist(Addressbook addr_book, string name)
{ // 判断是否存在查询的人员,存在返回在数组中索引位置，不存在返回-1
    for (int i = 0; i < addr_book.m_Size; ++i)
    {
        if (addr_book.personArray[i].m_Name == name)
        {
            return i;
        }
    }
    return -1;
}

void findPerson(Addressbook &addr_book)
{ // 查找指定联系人
    cout << "请输入您要查找的联系人:";
    string name;
    cin >> name;

    int ret = isExist(addr_book, name);
    if (ret == -1)
    {
        cout << "查无此人" << endl;
    }
    else
    {
        cout << "姓名\t性别\t年龄\t电话\t住址\t" << endl;
        cout << addr_book.personArray[ret].m_Name << "\t";
        cout << addr_book.personArray[ret].m_Sex << "\t";
        cout << addr_book.personArray[ret].m_Age << "\t";
        cout << addr_book.personArray[ret].m_Phone << "\t";
        cout << addr_book.personArray[ret].m_Addr << "\t";
        cout << endl;
    }
}