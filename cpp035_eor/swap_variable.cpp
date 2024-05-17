/*
 * @description 使用异或运算交换两个变量的值
 * @date   2024/5/17 20:22
 * @author zhc
 */
#include <iostream>

using namespace std;

void swap(int &x, int &y)
{
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}

int main()
{
    int x = 1;
    int y = 2;
    cout << "交换前: x = " << x << ",y = " << y << endl;
    swap(x,y);
    cout << "交换后: x = " << x << ",y = " << y << endl;
    return 0;
}