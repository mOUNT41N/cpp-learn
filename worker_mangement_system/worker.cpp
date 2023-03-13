#include "worker.h"
void Worker::showInfo()
{
    cout << "编号:" << this->m_id
         << "\t 姓名: " << this->m_name
         << "\t 岗位:" << this->getDeptName()
         << "\t 介绍:" << this->m_introduction << endl;
}
string Worker::setIntroduction(string text)
{
    this->m_introduction = text;
    cout << "设置 " << this->m_name << " 的自我介绍为:" << text << endl;
    return text;
}

string Employee::getDeptName()
{
    return string("员工");
}
string Manager::getDeptName()
{
    return string("经理");
}
string Boss::getDeptName()
{
    return string("老板");
}
