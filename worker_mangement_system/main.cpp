#include "worker.h"
#include "worker_manager.h"

void test_worker()
{
    Worker *worker = NULL;
    worker = new Employee(101, 1, "employee-mountain");
    // worker->setIntroduction("employee");
    worker->showInfo();
    delete worker;

    worker = new Manager(11, 2, "manager-mountain");
    // worker->setIntroduction("manager");
    worker->showInfo();
    delete worker;

    worker = new Boss(1, 3, "boss-mountain");
    // worker->setIntroduction("boss");
    worker->showInfo();

    delete worker;
}

int main()
{
    cout << "main" << endl;
    test_worker();
}
