// #include "1-3-7.h"
// #include "1-3-7.cpp" //解决方式1，包含cpp源文件

// 解决方式2，将声明和实现写到一起，文件后缀名改为.hpp
#include "1-3-7.hpp"

int main()
{
    Person<string, int> p("mt", 22);
    p.showPerson();
    return 0;
}