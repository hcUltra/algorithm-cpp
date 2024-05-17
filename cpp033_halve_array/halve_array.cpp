/*
 * @description 将数组和减半的最少操作次数
 * @link https://leetcode.cn/problems/minimum-operations-to-halve-array-sum/description/
 * @date   2024/5/17 18:05
 * @author zhc
 */
#include <iostream>
#include<queue>
#include <vector>
#include <algorithm>

using namespace std;

int halve_array(vector<int> &nums)
{
    int ans = 0;
    priority_queue<double> pq(nums.begin(), nums.end());
    double sum = 0;

    for(double num: nums)sum += (num/2);


    for(double i = 0; i < sum; ++ans)
    {
        double x = pq.top();
        pq.pop();

        i += (x/2);
        pq.push(x/2);
    }

    return ans;
}

int main()
{
    vector<int> nums;
    nums.push_back(5);
    nums.push_back(19);
    nums.push_back(8);
    nums.push_back(1);

    cout << "times: " << halve_array(nums) << endl;
    return 0;
}
