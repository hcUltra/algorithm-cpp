/*
 * @description 三的幂
 * @link https://leetcode.cn/problems/power-of-three/
 * @date   2024/5/18 10:26
 * @author zhc
 */
#include <iostream>

using namespace std;

// 如果一个数字是3的某次幂，那么这个数一定只含有3这个质数因子
// 1162261467是int型范围内，最大的3的幂，它是3的19次方
// 1162261467只含有3这个质数因子，如果n也是只含有3这个质数因子，那么 1162261467 % n == 0
// 反之如果1162261467 % n != 0 说明n一定含有其他因子
bool isPowerOfThree(int n)
{
    return n > 0 && 1162261467%n == 0;
}

int main()
{

    return 0;
}
