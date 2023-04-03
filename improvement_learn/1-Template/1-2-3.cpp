#include <iostream>
using namespace std;

// 交换的函数模板
template <typename T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T> // 也可以替换成typename
// 利用选择排序，进行对数组从大到小的排序
void mySort(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int max = i; // 最大数的下标
        for (int j = i + 1; j < len; j++)
        {
            if (arr[max] < arr[j])
            {
                max = j;
            }
        }
        if (max != i) // 如果最大数的下标不是i，交换两者
        {
            mySwap(arr[max], arr[i]);
        }
    }
}

template <typename T>
void printArr(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    // 测试char数组
    cout << "----- test char -----" << endl;
    char charArr[] = "bdcfeagh";
    int num = sizeof(charArr) / sizeof(char);
    mySort(charArr, num);
    printArr(charArr, num);

    // 测试int数组
    cout << "----- test int -----" << endl;
    int intArr[] = {7, 5, 8, 1, 3, 9, 2, 4, 6};
    num = sizeof(intArr) / sizeof(int);
    mySort(intArr, num);
    printArr(intArr, num);

    return 0;
}