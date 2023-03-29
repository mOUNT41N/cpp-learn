#ifndef __WORKER_MANAGER__
#define __WORKER_MANAGER__

#include <iostream>
#include <fstream>
#include "worker.h"
using namespace std;

const string FILE_NAME = "employee_file.txt";
const int EMPLOYEE_DEPT_ID = 1;
const int MANAGER_DEPT_ID = 2;
const int BOSS_DEPT_ID = 3;

class WorkerManager
{
private:
    int m_employee_num;        // 记录文件中的人数个数
    Worker **m_employee_array; // 员工数组的指针
    int file_empty_flag;       // 0为空 1为有内容

public:
    WorkerManager();  // 构造函数
    ~WorkerManager(); // 析构函数

    int get_employee_num();
    int get_file_empty_flag();

    void ShowMenu();     // 显示菜单
    void Select();       // 选择菜单
    void ExitSys();      // 退出
    void AddEmployee();  // 添加职工
    void SaveFile();     // 保存文件
    void ReadFile();     // 读文件, 返回读了多少个数
    void ShowEmployee(); // 显示员工
};

#endif