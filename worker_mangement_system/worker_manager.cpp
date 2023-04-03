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
        this->file_exist_flag = 0;     // 初始化文件标志
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
        this->file_exist_flag = 0;      // 初始化文件标志
        ifs.close();                    // 关闭文件
        return;
    }

    // 文件存在且有内容
    cout << "文件有内容，需要读取" << endl; // 测试输出
    this->m_employee_num = 0;               // 初始化人数
    this->m_employee_array = NULL;          // 初始化数组指针
    this->file_exist_flag = 1;              // 初始化文件标志
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
    return this->file_exist_flag;
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
            ShowEmployee();
            break;
        case 3: // 删除职工
            DeleteEmployee();
            break;
        case 4: // 修改职工
            ModifyEmployee();
            break;
        case 5: // 查找职工
            FindEmployee();
            break;
        case 6: // 排序职工
            SortEmployee();
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
        this->file_exist_flag = 1;          // 更新文件标志
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
    if (file_exist_flag != 1 || this->m_employee_array == nullptr)
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
void WorkerManager::DeleteEmployee()
{
    if (!this->file_exist_flag)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else
    {
        // 按职工编号删除
        cout << "请输入想要删除的职工号：" << endl;
        int id = 0;
        cin >> id;

        int index = this->IsExist(id);

        if (index != -1) // 说明index上位置数据需要删除
        {
            for (int i = index; i < this->m_employee_num - 1; i++)
            {
                this->m_employee_array[i] = this->m_employee_array[i + 1];
            }
            this->m_employee_num--;
            SaveFile(); // 删除后数据同步到文件中
            cout << "删除成功！" << endl;
        }
        else
        {
            cout << "删除失败，未找到该职工" << endl;
        }
    }
}

int WorkerManager::IsExist(int id)
{
    int index = -1;
    for (int i = 0; i < this->m_employee_num; i++)
    {
        if (this->m_employee_array[i]->m_id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}

void WorkerManager::ModifyEmployee()
{
    if (!this->file_exist_flag)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else
    {
        cout << "请输入修改职工的编号：" << endl;
        int id;
        cin >> id;

        int ret = this->IsExist(id);
        if (ret == -1)
        {
            cout << "修改失败，查无此人" << endl;
        }
        else
        {
            // 查找到编号的职工
            delete this->m_employee_array[ret];

            int new_id = 0;
            string new_name = "";
            string new_introduction = "";
            int dept_id = 0;

            cout << "查到： " << id << "号职工，请输入新职工号： " << endl;
            cin >> new_id;

            cout << "请输入新姓名： " << endl;
            cin >> new_name;

            cout << "请输入岗位： " << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> dept_id;

            cout << "请输入职工的介绍:" << endl;
            cin >> new_introduction;

            Worker *worker = NULL;
            switch (dept_id)
            {
            case1:
                worker = new Employee(new_id, dept_id, new_name, new_introduction);
                break;
            case2:
                worker = new Manager(new_id, dept_id, new_name, new_introduction);
                break;
            case 3:
                worker = new Boss(new_id, dept_id, new_name, new_introduction);
                break;
            default:
                break;
            }

            // 更改数据 到数组中
            this->m_employee_array[ret] = worker;
            cout << "修改成功！" << endl;

            // 保存到文件中
            this->SaveFile();
        }
    }
}

void WorkerManager::FindEmployee()
{
    if (!this->file_exist_flag)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else
    {
        cout << "请输入查找的方式：" << endl;
        cout << "1、按职工编号查找" << endl;
        cout << "2、按姓名查找" << endl;

        int select = 0;
        cin >> select;

        if (select == 1) // 按职工号查找
        {
            int id;
            cout << "请输入查找的职工编号：" << endl;
            cin >> id;

            int ret = IsExist(id);
            if (ret != -1)
            {
                cout << "查找成功！该职工信息如下：" << endl;
                this->m_employee_array[ret]->showInfo();
            }
            else
            {
                cout << "查找失败，查无此人" << endl;
            }
        }
        else if (select == 2) // 按姓名查找
        {
            string name;
            cout << "请输入查找的姓名：" << endl;
            cin >> name;

            bool flag = false; // 查找到的标志
            for (int i = 0; i < m_employee_num; i++)
            {
                if (m_employee_array[i]->m_name == name)
                {
                    cout << "查找成功,职工编号为："
                         << m_employee_array[i]->m_id
                         << " 号的信息如下：" << endl;

                    flag = true;

                    this->m_employee_array[i]->showInfo();
                }
            }
            if (flag == false)
            {
                // 查无此人
                cout << "查找失败，查无此人" << endl;
            }
        }
        else
        {
            cout << "输入选项有误" << endl;
        }
    }
}

// 排序职工
void WorkerManager::SortEmployee()
{
    if (!this->file_exist_flag)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else
    {
        cout << "请选择排序方式： " << endl;
        cout << "1、按职工号进行升序" << endl;
        cout << "2、按职工号进行降序" << endl;

        int select = 0;
        cin >> select;

        for (int i = 0; i < m_employee_num; i++)
        {
            int minOrMax = i;
            for (int j = i + 1; j < m_employee_num; j++)
            {
                if (select == 1) // 升序
                {
                    if (m_employee_array[minOrMax]->m_id > m_employee_array[j]->m_id)
                    {
                        minOrMax = j;
                    }
                }
                else // 降序
                {
                    if (m_employee_array[minOrMax]->m_id < m_employee_array[j]->m_id)
                    {
                        minOrMax = j;
                    }
                }
            }

            if (i != minOrMax)
            {
                Worker *temp = m_employee_array[i];
                m_employee_array[i] = m_employee_array[minOrMax];
                m_employee_array[minOrMax] = temp;
            }
        }

        cout << "排序成功,排序后结果为：" << endl;
        this->SaveFile();
        this->ShowEmployee();
    }
}