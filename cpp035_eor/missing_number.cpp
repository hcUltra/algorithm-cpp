/*
 * @description 消失的数字
 * @link https://leetcode.cn/problems/missing-number/
 * @date   2024/5/17 20:58
 * @author zhc
 */
#include <iostream>
#include <vector>

using namespace std;

int missing_number(vector<int> &nums)
{
    int eor = 0;
    for(int i = 0; i < nums.size(); ++i) eor ^= (nums[i] ^ i);
    return eor ^ nums.size();
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(2);
    cout << "missing number is " << missing_number(nums) << endl;
    return 0;
}
