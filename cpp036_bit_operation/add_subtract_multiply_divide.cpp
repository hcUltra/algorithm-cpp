/*
 * @description 
 * @date   2024/5/18 16:19
 * @author zhc
 */
#include <iostream>

using namespace std;

// 3 + 5
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

// -x = ~x + 1
int subtract(int x, int y)
{
    return add(x, add(~y, 1));
}

int multiply(int x, int y)
{
    int ans = 0;
    // 3 * 5
    // 0000 0011
    // 0000 0101
    // 乘数的当前位为1，收集答案
    while(y)
    {
        if((1 & y) != 0) ans = add(ans, x);
        x <<= 1;
        y >>= 1;
    }

    return ans;
}

int neg(int n)
{
    return add(~n, 1);
}

// 此处必须保证a和b都不是整数最小值
int divide_(int a, int b)
{
    // 有溢出风险，符号位单独考虑
    int x = a < 0 ? neg(a) : a;
    int y = b < 0 ? neg(b) : b;
    int ans = 0;
    for(int i = 30; i >= 0; i = subtract(i, 1))
    {
        // y左移有溢出风险，此处将x右移
        // 相当于 x / 2^i >= y   =>  x >= y * 2^i
        if((x >> i) >= y)
        {
            ans |= (1 << i);
            x = subtract(x, y << i);
        }
    }
    return (a < 0) ^ (b < 0) ? neg(ans) : ans;
}
// 防止溢出
int divide__(int a, int b)
{
    if(a == INT_MIN && b == INT_MIN)
    {
        // a和b都是整数最小
        return 1;
    }
    if(a != INT_MIN && b != INT_MIN)
    {
        // a和b都不是整数最小，那么正常去除
        return divide_(a, b);
    }
    if(b == INT_MIN)
    {
        // a不是整数最小，b是整数最小
        return 0;
    }
    // a是整数最小，b是-1，返回整数最大，因为题目里明确这么说了
    if(b == neg(1))
    {
        return INT_MAX;
    }
    // a是整数最小，b不是整数最小，b也不是-1
    a = add(a, b > 0 ? b : neg(b));
    int ans = divide_(a, b);
    int offset = b > 0 ? neg(1) : 1;
    return add(ans, offset);
}

int main()
{
    cout << add(222, 111) << endl;
    cout << subtract(222, 111) << endl;
    cout << multiply(222, 111) << endl;
    return 0;
}
