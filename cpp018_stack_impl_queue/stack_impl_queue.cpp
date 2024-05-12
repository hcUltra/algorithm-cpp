/*
 * @description 力扣232. 用栈实现队列 src: https://leetcode.cn/problems/implement-queue-using-stacks/description/
 * @date   2024/5/12 14:59
 * @author zhc
 */
#include <iostream>
#include <stack>

using namespace std;

class MyQueue
{
public:
    stack<int> in;// 进数据
    stack<int> out;// 出数据

    MyQueue()
    {
    }

    void push(int x)
    {
        in.push(x);
    }

    int pop()
    {
        if(out.empty())
        {
            // 倒数据
            while(!in.empty())
            {
                int t = in.top();
                in.pop();
                out.push(t);
            }
        }
        int val = out.top();
        out.pop();
        return val;
    }

    int peek()
    {
        if(out.empty())
        {
            // 倒数据
            while(!in.empty())
            {
                int t = in.top();
                in.pop();
                out.push(t);
            }
        }
        return out.top();;
    }

    bool empty()
    {
        return in.empty() && out.empty();
    }
};

int main()
{
    // pass
    return 0;
}
