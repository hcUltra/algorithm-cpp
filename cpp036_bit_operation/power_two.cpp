/*
 * @description  二的幂
 * @link https://leetcode.cn/problems/power-of-two/
 * @date   2024/5/18 10:21
 * @author zhc
 */
#include <iostream>

using namespace std;

bool isPowerOfTwo(int n)
{
    // Brian Kernighan算法 提取出一个十进制数二进制表示中最右侧的1 x & -x
    return n > 0 && n == (n & -n);
}

int main()
{
    cout << "127:" << isPowerOfTwo(127) << endl;
    cout << "128:" << isPowerOfTwo(128) << endl;
    return 0;
}
