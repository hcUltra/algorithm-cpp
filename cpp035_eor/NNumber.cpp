/*
 * @description 只有1种数出现次数少于m次，其他数都出现了m次
 * @link https://leetcode.cn/problems/single-number-ii/description/
 * @date   2024/5/17 21:28
 * @author zhc
 */
#include <iostream>

using namespace std;

int find(vector<int> &arr, int m)
{
    vector<int> cnts(32);
    for(int i = 0; i < 32; ++i) cnts[i] = 0;
    // 位信息词频统计
    for(int num: arr)
    {
        for(int i = 0; i < 32; i++) cnts[i] += (num >> i) & 1;
    }
    int ans = 0;
    for(int i = 0; i < 32; i++)
    {
        if(cnts[i]%m != 0) ans |= 1 << i;
    }
    return ans;
}

int main()
{

    return 0;
}
