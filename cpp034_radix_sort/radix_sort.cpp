/*
 * @description 基数排序
 * @link https://leetcode.cn/problems/sort-an-array/description/
 * @date   2024/5/17 19:19
 * @author zhc
 */
#include <iostream>

using namespace std;

// 计算number，在base进制下的位数
int bits(int number, int base)
{
    int ans = 0;
    while(number > 0)
    {
        ++ans;
        number /= base;
    }
    return ans;
}

/**
 * 基数排序
 * @param nums 数组
 * @param bits 最大位数
 * @param base 进制
 */
void radix_sort(vector<int> &nums, int bits, int base)
{
    // 统计词频
    vector<int> cnts(base);
    // 存放中间结果
    vector<int> help(nums.size());
    int offset = 1;// 偏移值
    while(bits > 0)
    {
        // 刷新词频统计表
        for(int i = 0; i < base; i++) cnts[i] = 0;
        // 统计词频
        for(int i = 0; i < nums.size(); ++i) cnts[(nums[i]/offset)%10]++;
        // 统计词频的前缀和，表示 <= nums[i] 的数字有多少个
        for(int i = 1; i < cnts.size(); ++i) cnts[i] += cnts[i - 1];
        // 按照该位的权重，从后往前进行排序
        for(int i = nums.size() - 1; i >= 0; --i) help[--cnts[(nums[i]/offset)%10]] = nums[i];
        // 将本次本权重的排序结果刷回到原数组
        for(int i = 0; i < nums.size(); ++i) nums[i] = help[i];

        // 本权重的排序已经完成，排序的轮次减一，排序的权重增加，继续进行下一个权重的排序
        --bits;
        offset *= 10;
    }
}

void radix_sort(vector<int> &nums)
{
    if(nums.size() > 1)
    {
        int min = nums[0], max = nums[0];
        for(int i = 0; i < nums.size(); ++i) min = nums[i] < min ? nums[i] : min, max = nums[i] > max ? nums[i] : max;
        // 数组可能出现负数，将数组中的每个数减去最小值，转换为正数进行排序，排序完成后再加回来
        for(int i = 0; i < nums.size(); ++i) nums[i] -= min;
        // 获取数组最大值，在base进制下有多少位，这里写10位,注意这里的max是在减去最小值之前统计的，所以max也需要减去最小值
        int bit = bits(max - min, 10);
        radix_sort(nums, bit, 10);
        // 将减去的数加回来
        for(int i = 0; i < nums.size(); ++i) nums[i] += min;
    }
}

int main()
{
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(8);
    nums.push_back(-10);
    radix_sort(nums);
    for(int num: nums) cout << num << " ";
    cout << endl;

    return 0;
}
