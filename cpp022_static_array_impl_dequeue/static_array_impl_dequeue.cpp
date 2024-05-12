/*
 * @description 
 * @date   2024/5/12 16:11
 * @author zhc
 */
#include <iostream>

using namespace std;

class MyCircularDeque
{
private:
    int* dequeue;
    int sz;
    int max_sz;
    int l;
    int r;
public:
    MyCircularDeque(int k) : max_sz(k), sz(0), l(0), r(0)
    {
        dequeue = new int[k];
    }

    bool insertFront(int value)
    {
        if(isFull())
        {
            return false;
        }
        if(isEmpty())
        {
            l = r = sz = 0;
            dequeue[0] = value;
            sz++;
            return true;
        }

        l = l == 0 ? (max_sz - 1) : (l - 1);
        dequeue[l] = value;
        sz++;
        return true;
    }

    bool insertLast(int value)
    {
        if(isFull())
        {
            return false;
        }

        if(isEmpty())
        {
            l = r = sz = 0;
            dequeue[0] = value;
            sz++;
            return true;
        }

        r = r == max_sz - 1 ? (0) : (r + 1);
        dequeue[r] = value;
        sz++;
        return true;
    }

    bool deleteFront()
    {
        if(isEmpty())
        {
            return false;
        }

        // 将数字从区间[l,r]排除
        l = l == max_sz - 1 ? (0) : (l + 1);
        sz--;
        return true;
    }

    bool deleteLast()
    {
        if(isEmpty())
        {
            return false;
        }

        // 将数字从区间[l,r]排除
        r = r == 0 ? (max_sz - 1) : (r - 1);
        sz--;
        return true;
    }

    int getFront()
    {
        if(isEmpty())
        {
            return -1;
        }

        return dequeue[l];
    }

    int getRear()
    {
        if(isEmpty())
        {
            return -1;
        }

        return dequeue[r];
    }

    bool isEmpty()
    {
        return sz == 0;
    }

    bool isFull()
    {
        return sz == max_sz;
    }
};

int main()
{

    return 0;
}
