/*
 * @description 不用任何判断语句和比较操作，返回两个数的最大值
 * @link https://www.nowcoder.com/practice/d2707eaf98124f1e8f1d9c18ad487f76
 * @date   2024/5/17 20:25
 * @author zhc
 */
#include <iostream>

using namespace std;

int flip(int number)
{
    return number ^ 1;
}

// 正数返回 1
// 负数返回 0
int sign(int number)
{
    return flip(((number >> 31) & 1));
}


// 有溢出风险的实现
int getMax1(int a, int b)
{
    int c = a - b;
    // 如果c <= 0 返回 b,让a的系数为0
    // 如果c >  0 返回 a,让b的系数为0
    // c >  0, c的符号位1,b的符号为0
    // c <= 0, c的符号位0,b的符号为1
    int return_a = sign(c);
    int return_b = flip(return_a);
    return a*return_a + b*return_b;
}

int getMax2(int a, int b)
{
    // c可能是溢出的
    int c = a - b;
    // a的符号
    int sa = sign(a);
    // b的符号
    int sb = sign(b);
    // c的符号
    int sc = sign(c);
    // 判断A和B，符号是不是不一样，如果不一样diffAB=1，如果一样diffAB=0
    int diff_ab = sa ^ sb;
    // 判断A和B，符号是不是一样，如果一样sameAB=1，如果不一样sameAB=0
    int same_ab = flip(diff_ab);

    int return_a = diff_ab*sa + same_ab*sc;
    int return_b = flip(return_a);
    return a*return_a + b*return_b;
}

int main()
{

    return 0;
}
