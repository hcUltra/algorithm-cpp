/*
 * @description 返回二进制表示1的个数
 * @link https://leetcode.cn/problems/hamming-distance/
 * @date   2024/5/18 10:49
 * @author zhc
 */
#include <iostream>

using namespace std;

int cntOnes(int n)
{
    n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
    n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
    n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
    return n;
}

int hammingDistance(int x, int y)
{
    return cntOnes(x ^ y);
}

int main()
{

    return 0;
}
