/*
 * @description 位图设计
 * @link https://leetcode-cn.com/problems/design-bitset/
 * @date   2024/5/18 11:01
 * @author zhc
 */
#include <iostream>

using namespace std;

// Bitset是一种能以紧凑形式存储位的数据结构
// Bitset(int n) : 初始化n个位，所有位都是0
// void fix(int i) : 将下标i的位上的值更新为1
// void unfix(int i) : 将下标i的位上的值更新为0
// void flip() : 翻转所有位的值
// boolean all() : 是否所有位都是1
// boolean one() : 是否至少有一位是1
// int count() : 返回所有位中1的数量
// String toString() : 返回所有位的状态
class Bitset {
private:
    int* bitset;
    int size;
    int zeros;
    int ones;
    bool reversed;

public:
    Bitset(int size) : size(size), zeros(size), ones(0), reversed(false) {
        bitset = new int[(size + 31) / 32]();
    }

    ~Bitset() {
        delete[] bitset;
    }

    void fix(int idx) {
        int index = idx / 32;
        int bit = idx % 32;
        if (!reversed) {
            if ((bitset[index] & (1 << bit)) == 0) {
                bitset[index] |= (1 << bit);
                ones++;
                zeros--;
            }
        } else {
            if ((bitset[index] & (1 << bit)) != 0) {
                bitset[index] &= ~(1 << bit);
                ones++;
                zeros--;
            }
        }
    }

    void unfix(int idx) {
        int index = idx / 32;
        int bit = idx % 32;
        if (!reversed) {
            if ((bitset[index] & (1 << bit)) != 0) {
                bitset[index] &= ~(1 << bit);
                ones--;
                zeros++;
            }
        } else {
            if ((bitset[index] & (1 << bit)) == 0) {
                bitset[index] |= (1 << bit);
                ones--;
                zeros++;
            }
        }
    }

    void flip() {
        reversed = !reversed;
        int temp = zeros;
        zeros = ones;
        ones = temp;
    }

    bool all() {
        return ones == size;
    }

    bool one() {
        return ones > 0;
    }

    int count() {
        return ones;
    }

    string toString() {
        string s(size, '0');
        for (int i = 0; i < size; ++i) {
            int index = i / 32;
            int bit = i % 32;
            bool isSet = (bitset[index] & (1 << bit)) != 0;
            if (reversed) {
                isSet = !isSet;
            }
            s[i] = isSet ? '1' : '0';
        }
        return s;
    }
};

int main()
{

    return 0;
}
