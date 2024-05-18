/*
 * @description 返回[l,r]内所有数字相与（ & ） 的结果
 * @link https://leetcode.cn/problems/bitwise-and-of-numbers-range/
 * @date   2024/5/18 10:40
 * @author zhc
 */
#include <iostream>

using namespace std;

// 递减逼近相与后的真实值的二进制1的状态
int rangeBitwiseAnd(int l, int r)
{
    while(l < r)
    {
        r -= r & -r;
    }
    return r;
}

int main()
{

    return 0;
}
