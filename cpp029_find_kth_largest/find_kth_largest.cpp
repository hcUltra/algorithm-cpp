#include <iostream>
#include <vector>
#include <random>

using namespace std;

double random(double l, double r)
{
    // 使用mersenne_twister_engine作为随机数生成引擎
    std::random_device rd;
    // 获取一个真正的随机数作为种子
    std::mt19937 gen(rd());
    // 使用Mersenne Twister算法生成随机数  在[l, r]之间的均匀分布  [l,r+1) => [l,r]
    std::uniform_real_distribution<> dis(l, r + 1);
    return dis(gen); // 生成并返回一个在[0, 1)范围内的随机浮点数
}

/**
 * 划分数组 <x  ==x  >x
 * @param nums  数组
 * @param l     左边界
 * @param r     右边界
 * @param x     划分值
 * @return      返回==x 的区间
 */
static int* partition(vector<int> &arr, int l, int r, int x)
{
    int* ret = new int[2];
    ret[0] = l;
    ret[1] = r;
    int i = l;
    while(i <= ret[1])
    {
        if(arr[i] == x)
        {
            i++;
        } else if(arr[i] < x)
        {
            swap(arr[i++], arr[ret[0]++]);
        } else
        {
            swap(arr[i], arr[ret[1]--]);
        }
    }
    return ret;
}

/**
 *
 * @param nums 无序数组
 * @param i    位置
 * @return     返回如果数组有序，那么 i 位置上的数
 */
int randomizedSelect(vector<int> &nums, int i)
{
    int l = 0, r = nums.size() - 1;
    while(l <= r)
    {
        int* pairs = partition(nums, l, r, nums[(int) random(l, r)]);
        int left = pairs[0];
        int right = pairs[1];
        if(i < left)
        {
            r = left - 1;
        } else if(i > right)
        {
            l = right + 1;
        } else
        {
            return nums[i];
        }
        delete[] pairs; // 释放内存
    }
    return 0;
}

int findKthLargest(vector<int> &nums, int k)
{
    return randomizedSelect(nums, nums.size() - k);
}

int main()
{
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(4);

    int k = 4; // 第K大的元素

    cout << findKthLargest(nums, k) << endl;
    return 0;
}
