/*
 * @description 逆序x的二进制状态
 * @link https://leetcode.cn/problems/reverse-bits/
 * @date   2024/5/18 10:43
 * @author zhc
 */
#include <iostream>

using namespace std;

uint32_t reverseBits(uint32_t n)
{
    // a , b , c , d , e , f , g , h

    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
    // => b a , d c , f e , h g

    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
    // => d c b a , h g f e

    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    // h g f e d c b a

    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);

    n = (n >> 16) | (n << 16);
    return n;
}

int main()
{

    return 0;
}
