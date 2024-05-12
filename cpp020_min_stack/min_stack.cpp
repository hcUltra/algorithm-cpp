/*
 * @description 
 * @date   2024/5/12 15:57
 * @author zhc
 */
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

class MinStack
{
public:
    stack<int> min_stack;
    stack<int> data_stack;

    MinStack()
    {
        // 如果在最小栈为初始化（加入第一个元素）之前访问，会访问到错误的内存，因此，先压入一个数据，如果访问到这个数据表示当前没有最小值
        min_stack.push(INT_MAX);
    }

    void push(int val)
    {
        data_stack.push(val);
        min_stack.push(min(min_stack.top(), val));
    }

    void pop()
    {
        data_stack.pop();
        min_stack.pop();
    }

    int top()
    {
        return data_stack.top();
    }

    int getMin()
    {
        return min_stack.top();
    }
};

int main()
{
    return 0;
}
