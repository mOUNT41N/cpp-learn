#include "worker_manager.h"
#include "worker.h"

WorkerManager::WorkerManager()
{
    ifstream ifs;
    ifs.open(FILE_NAME, ios::in);
    // 文件不存在
    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl;  // 测试输出
        this->m_employee_num = 0;      // 初始化人数
        this->m_employee_array = NULL; // 初始化数组指针
        this->file_empty_flag = 0;     // 初始化文件标志
        ifs.close();                   // 关闭文件
        return;
    }

    // 文件存在,但没内容
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "文件内容为空" << endl; // 测试输出
        this->m_employee_num = 0;       // 初始化人数
        this->m_employee_array = NULL;  // 初始化数组指针
        this->file_empty_flag = 0;      // 初始化文件标志
        ifs.close();                    // 关闭文件
        return;
    }

    // 文件存在且有内容
    cout << "文件有内容，需要读取" << endl; // 测试输出
    this->m_employee_num = 0;               // 初始化人数
    this->m_employee_array = NULL;          // 初始化数组指针
    this->file_empty_flag = 1;              // 初始化文件标志
    ReadFile();
}
WorkerManager::~WorkerManager()
{
    if (this->m_employee_array != nullptr)
    {
        delete[] this->m_employee_array;
    }
}

int WorkerManager::get_employee_num()
{
    return this->m_employee_num;
}

int WorkerManager::get_file_empty_flag()
{
    return this->file_empty_flag;
}

void WorkerManager::ShowMenu()
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
void WorkerManager::ExitSys()
{
    cout << "欢迎下次使用" << endl;
    exit(0);
}
void WorkerManager::Select()
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
            AddEmployee();
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
void WorkerManager::AddEmployee()
{
    cout << "请输入增加职工数量:" << endl;
    int add_num = 0;
    cin >> add_num;
    if (add_num > 0)
    {
        int new_size = this->m_employee_num + add_num;
        Worker **new_space = new Worker *[new_size];
        if (this->m_employee_array != nullptr)
        {
            for (int i = 0; i < this->m_employee_num; ++i)
            {
                new_space[i] = this->m_employee_array[i];
            }
        }

        for (int i = 0; i < add_num; ++i)
        {
            int id;
            string name;
            int select;
            string introduction;

            cout << "请输入第 " << i + 1 << " 个新职工编号:" << endl;
            cin >> id;

            cout << "请输入第 " << i + 1 << " 个新职工姓名:" << endl;
            cin >> name;

            cout << "请选择该职工的岗位：" << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> select;

            cout << "请输入第 " << i + 1 << " 个新职工的介绍:" << endl;
            cin >> introduction;

            Worker *worker = NULL;

            switch (select)
            {
            case EMPLOYEE_DEPT_ID: // 普通员工
                worker = new Employee(id, EMPLOYEE_DEPT_ID, name, introduction);
                break;
            case MANAGER_DEPT_ID: // 经理
                worker = new Manager(id, MANAGER_DEPT_ID, name, introduction);
                break;
            case BOSS_DEPT_ID: // 老板
                worker = new Boss(id, BOSS_DEPT_ID, name, introduction);
                break;
            default:
                break;
            }

            new_space[this->m_employee_num + i] = worker;
        }
        delete[] this->m_employee_array;    // 释放原有空间
        this->m_employee_array = new_space; // 更改新空间的指向
        this->m_employee_num = new_size;    // 更新新的个数
        this->file_empty_flag = 1;          // 更新文件标志
        cout << "成功添加" << add_num << "名新职工！" << endl;
        this->SaveFile();
    }
    else
    {
        cout << "输入有误" << endl;
    }
}
void WorkerManager::SaveFile()
{
    ofstream ofs;
    ofs.open(FILE_NAME, ios::out);
    ofs << this->get_employee_num() << endl;
    for (int i = 0; i < this->m_employee_num; ++i)
    {
        ofs << this->m_employee_array[i]->m_name << " "
            << this->m_employee_array[i]->m_id << " "
            << this->m_employee_array[i]->m_dept_id << " "
            << this->m_employee_array[i]->m_introduction << endl;
    }
    ofs.close();
}

void WorkerManager::ReadFile()
{
    ifstream ifs;
    ifs.open(FILE_NAME, ios::in);

    int id;              // 职工编号
    string name;         // 职工姓名
    int dept_id;         // 职工部门编号
    string introduction; // 职工自我介绍

    int index_num = 0;
    ifs >> index_num;
    this->m_employee_num = index_num;
    this->m_employee_array = new Worker *[index_num];

    for (int i = 0; (i < index_num) && (ifs >> name >> id >> dept_id >> introduction); ++i)
    {
        Worker *worker = NULL;
        if (dept_id == 1)
            worker = new Employee(id, dept_id, name, introduction);
        else if (dept_id == 2)
            worker = new Manager(id, dept_id, name, introduction);
        else if (dept_id == 3)
            worker = new Boss(id, dept_id, name, introduction);
        this->m_employee_array[i] = worker;
    }

    ifs.close();
}
void WorkerManager::ShowEmployee()
{
    // if (this->m_employee_array == nullptr)
    if (file_empty_flag != 1 || this->m_employee_array == nullptr)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else
    {
        for (int i = 0; i < this->m_employee_num; ++i)
        {
            this->m_employee_array[i]->showInfo();
        }
    }
}
