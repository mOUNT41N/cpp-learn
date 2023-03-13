#ifndef __WORKER__
#define __WORKER__

#include <iostream>
#include <string>
using namespace std;

class Worker
{
public:
    int m_id;              // 职工编号
    string m_name;         // 职工姓名
    int m_dept_id;         // 职工部门编号
    string m_introduction; // 职工自我介绍

    Worker(const int id, const int dept_id, const string name) : m_id(id), m_dept_id(dept_id), m_name(name) {}
    void showInfo(); // 显示个人信息
    // string setIntroduction(string text); // 设置自我介绍
    virtual string getDeptName() = 0; // 获取岗位名称
};

class Employee : public Worker
{
public:
    Employee(const int id, const int dept_id, const string name) : Worker(id, dept_id, name) {}
    void showInfo();
    string getDeptName();
};

class Manager : public Worker
{
public:
    Manager(const int id, const int dept_id, const string name) : Worker(id, dept_id, name) {}
    void showInfo();
    string getDeptName();
};

class Boss : public Worker
{
public:
    Boss(const int id, const int dept_id, const string name) : Worker(id, dept_id, name) {}
    void showInfo();
    string getDeptName();
};

#endif