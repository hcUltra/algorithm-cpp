/*
 * @description 力扣225. 用队列实现栈 src: https://leetcode.cn/problems/implement-stack-using-queues/description/
 * @date   2024/5/12 15:13
 * @author zhc
 */
#include <iostream>
#include <queue>

using namespace std;

class MyStack
{
public:
    queue<int> q;

    MyStack()
    {
    }

    void push(int x)
    {
        int size = q.size();
        q.push(x);
        for(int i = 0; i < size; ++i)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int val = q.front();
        q.pop();
        return val;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};

int main()
{
    // pass
    return 0;
}
