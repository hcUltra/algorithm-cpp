/*
 * @description 大于等于 n 的二的幂
 * @date   2024/5/18 10:29
 * @author zhc
 */
#include <iostream>

using namespace std;

int near2power(int n)
{
    // 将 n - 1 后的 某一位1 右侧全部刷成1 最后在加上1成为2的次幂
    if(n <= 0)
    {
        return 1;
    }
    n--;
    // 将 n 的每对相邻位或起来。
    n |= n >> 1;
    // n 的每4个位或起来。
    n |= n >> 2;
    // n 的每4个位或起来。
    n |= n >> 4;
    // n 的每4个位或起来。
    n |= n >> 8;
    // n 的每4个位或起来。
    n |= n >> 16;

    // 将 n 的最右侧的1之后的每一位都刷成1
    return n + 1;
}


int main()
{
    cout << near2power(31) << endl;// 32
    cout << near2power(32) << endl;// 32
    cout << near2power(33) << endl;// 64
    return 0;
}
