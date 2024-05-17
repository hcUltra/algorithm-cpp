/*
 * @description
 * @link https://leetcode.cn/problems/single-number/
 * @date   2024/5/17 21:04
 * @author zhc
 */
#include <iostream>
#include <vector>

using namespace std;

int single_number(vector<int> &nums)
{
    int eor = 0;
    for(int x: nums) eor ^= x;
    return eor;
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(1);

    cout << "The number that appears odd times is " << single_number(nums) << endl;
    return 0;
}
