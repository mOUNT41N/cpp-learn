#ifndef __1_3_9__
#define __1_3_9__

#include <iostream>
using namespace std;
template <class T>
class MyArray
{
private:
    T *pAddress;    // 指向一个堆空间，这个空间存储真正的数据
    int m_capacity; // 容量
    int m_size;     // 大小

public:
    // 构造函数
    MyArray(int capacity)
    {
        this->m_capacity = capacity;
        this->m_size = 0;
        this->pAddress = new T[capacity];
    }

    MyArray(const MyArray &arr)
    {
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        this->pAddress = new T[arr.m_capacity];
        // 如果T为对象，而且还包含指针，必须需要重载 = 操作符，因为这个等号不是 构造 而是赋值，
        // 普通类型可以直接 = 但是指针类型需要深拷贝
        for (int i = 0; i < this->m_size; ++i)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    // 重载 = 操作符  防止浅拷贝问题
    MyArray &operator=(const MyArray &myArr)
    {
        if (this->pAddress != nullptr)
            delete this->pAddress;
        this->m_capacity = myArr.m_capacity;
        this->m_size = myArr.m_size;

        this->pAddress = new T[myArr.m_capacity];
        for (int i = 0; i < this->m_Size; i++)
        {
            this->pAddress[i] = myArr.pAddress[i];
        }
        return *this;
    }

    // 重载[] 操作符  arr[0]
    T &operator[](int index)
    {
        return this->pAddress[index]; // 不考虑越界，用户自己去处理
    }

    // 尾插法
    void push_back(const T &val)
    {
        if (this->m_capacity == this->m_size)
            return;
        this->pAddress[this->m_size] = val;
        this->m_size++;
    }

    // 尾删法
    void pop_back()
    {
        if (this->m_size == 0)
            return;
        this->m_size--;
    }

    // 获取数组容量
    int getCapacity()
    {
        return this->m_capacity;
    }

    // 获取数组大小
    int getSize()
    {
        return this->m_size;
    }

    // 析构
    ~MyArray()
    {
        if (this->pAddress != nullptr)
        {
            delete[] this->pAddress;
            this->pAddress = nullptr;
        }
        this->m_capacity = 0;
        this->m_size = 0;
    }
};

#endif