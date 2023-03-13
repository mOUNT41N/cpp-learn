#ifndef __WORKER_MANAGER__
#define __WORKER_MANAGER__

#include <iostream>
using namespace std;
class WorkerManager
{
public:
    WorkerManager();  // 构造函数
    ~WorkerManager(); // 析构函数

    void ShowMenu(); // 显示菜单
    void Select();   // 选择菜单
    void ExitSys();  // 退出
};

#endif