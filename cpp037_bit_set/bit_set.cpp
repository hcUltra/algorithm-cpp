/*
 * @description 位图
 * @date   2024/5/18 11:00
 * @author zhc
 */
#include <iostream>
#include<unordered_set>
// Bitset(int size)
// void add(int num)
// void remove(int num)
// void reverse(int num)
// boolean contains(int num)
using namespace std;

class BitSet
{
private:
    int* bitset;
    int sz;
public:
    // 初始化位图 存放size个数字 下标映射为 0 ~ (n - 1)
    // 请保证 n > 0
    BitSet(int n)
    {
        // a / b 向上取整 (a + b - 1) / b => 要求a >= 0 && b >= 0
        int size = (n + 32 - 1)/32;
        bitset = new int[size]();
        sz = size;
    }

    ~BitSet()
    {
        delete[] bitset;
    }

    void add(int n)
    {
        // 将 n 映射到数组下标
        int index = n/32;
        // 找到 n 在 arr[index] 的第几位
        int bit = n%32;
        bitset[index] |= (1 << bit);
    }

    void remove(int n)
    {
        // 将 n 映射到数组下标
        int index = n/32;
        // 找到 n 在 arr[index] 的第几位
        int bit = n%32;

        bitset[index] &= ~(1 << bit);
    }

    /**
     * 反转 n 在位图中的状态，存在就删除，不存在就加入
     * @param n
     */
    void reverse(int n)
    {
        // 将 n 映射到数组下标
        int index = n/32;
        // 找到 n 在 arr[index] 的第几位
        int bit = n%32;

        bitset[index] ^= (1 << bit);
    }

    bool constains(int n)
    {
        // 将 n 映射到数组下标
        int index = n/32;
        // 找到 n 在 arr[index] 的第几位
        int bit = n%32;

        return ((bitset[index] >> bit) & 1) == 1;
    }


};

int main()
{

    return 0;
}
