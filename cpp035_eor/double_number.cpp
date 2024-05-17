/*
 * @description 两种数出现了奇数次，其它数都出现了偶数次
 * @link https://leetcode.cn/problems/single-number-iii/description/
 * @date   2024/5/17 21:07
 * @author zhc
 */
#include <iostream>
#include <vector>

using namespace std;

vector<int> double_number(vector<int> &nums)
{
    // 出现奇数次的数字是 a b
    int all_eor = 0;
    for(int x: nums) all_eor ^= x; // all_eor = a ^ b; 出现偶数次的数字异或后为0
    int a = 0;

    // 提取出数字二进制中最右侧的1
    // 既然a,b出现奇数次且a != b 说明在两个数字在某一位二进制上一定是不同的，一个是1，另一个是0
    // 提取出 all_eor 最右侧的1，就可以区分出a 和 b
    int rightOne = all_eor == INT_MIN ? all_eor : all_eor & (-all_eor);// 此处负数最小值是没有相反数与之对应

    for(int x: nums) a ^= (x & rightOne) == 0 ? x : 0;// 提取出a
    
    vector<int> ret;
    ret.push_back(a);
    ret.push_back(all_eor ^ a);

    return ret;
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    vector<int> ret = double_number(nums);
    cout << ret[0] << " " << ret[1] << endl;
    return 0;
}
