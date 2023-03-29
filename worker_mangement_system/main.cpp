#include "worker.h"
#include "worker_manager.h"

void test_worker()
{
    cout << "----------worker_test----------";
    Worker *worker1 = NULL;
    worker1 = new Employee(101, 1, "employee-mountain", "i'm employee");
    // worker1->setIntroduction("employee");
    Worker *worker2 = NULL;
    worker2 = new Manager(11, 2, "manager-mountain", "i'm manager");
    // worker2->setIntroduction("manager");
    Worker *worker3 = NULL;
    worker3 = new Boss(1, 3, "boss-mountain", "i'm boss");
    // worker3->setIntroduction("boss");

    worker1->showInfo();
    worker2->showInfo();
    worker3->showInfo();

    delete worker1;
    delete worker2;
    delete worker3;
}

void test_show()
{
    cout << "----------show test----------" << endl;
    WorkerManager wm;
    wm.ShowEmployee();
}

void test_func()
{
    cout << "----------test----------" << endl;
    WorkerManager wm;
    wm.Select();
}

int main()
{
    cout << "main" << endl;
    // test_worker();
    // test_func();
    test_show();
    return 0;
}
