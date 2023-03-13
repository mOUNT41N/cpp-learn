#include "worker_manager.h"
#include "worker.h"
WorkerManager::WorkerManager()
{
}
WorkerManager::~WorkerManager()
{
}

inline void WorkerManager::ShowMenu()
{
    cout << "--------------------------------------------" << endl;
    cout << "---------  WorkerManagementSystem ----------" << endl;
    cout << "-------------  0.退出管理程序  -------------" << endl;
    cout << "-------------  1.增加职工信息  -------------" << endl;
    cout << "-------------  2.显示职工信息  -------------" << endl;
    cout << "-------------  3.删除离职职工  -------------" << endl;
    cout << "-------------  4.修改职工信息  -------------" << endl;
    cout << "-------------  5.查找职工信息  -------------" << endl;
    cout << "-------------  6.按照编号排序  -------------" << endl;
    cout << "-------------  7.清空所有文档  -------------" << endl;
    cout << "--------------------------------------------" << endl;
    cout << endl;
}

inline void WorkerManager::ExitSys()
{
    cout << "欢迎下次使用" << endl;
    exit(0);
}
inline void WorkerManager::Select()
{
    ShowMenu();
    while (true)
    {
        // 展示菜单
        int choice = -1;
        cout << "请输入您的选择:" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0: // 退出系统
            ExitSys();
            break;
        case 1: // 添加职工
            break;
        case 2: // 显示职工
            break;
        case 3: // 删除职工
            break;
        case 4: // 修改职工
            break;
        case 5: // 查找职工
            break;
        case 6: // 排序职工
            break;
        case 7: // 清空文件
            break;
        default:

            break;
        }
        ShowMenu();
    }
}

// int main()
// {
//     WorkerManager worker_manager;
//     worker_manager.Select();
//     return 0;
// }