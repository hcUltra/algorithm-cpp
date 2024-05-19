/*
 * @description 
 * @date   2024/5/18 16:19
 * @author zhc
 */
#include <iostream>

using namespace std;

// 3 + 5
// 3
// 5
int add(int x, int y)
{
    // x = 3 -> 0000 0011
    // y = 5 -> 0000 0101
    int ans = 0;

    while(y)
    {
        // 无进位相加信息
        // ans -> 0000 0110
        ans = x ^ y;
        // 进位信息 (1 + 1 才会产生进位)
        // x & y            -> 0000 0001
        // (x & y) << 1     -> 0000 0010
        y = (x & y) << 1;
        x = ans;
    }
    return ans;
}

int main()
{
    cout << add(111, 222) << endl;
    return 0;
}
