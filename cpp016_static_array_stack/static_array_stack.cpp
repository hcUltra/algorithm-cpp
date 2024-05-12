/*
 * @description 静态数组实现栈
 * @date   2024/5/12 09:51
 * @author zhc
 */
#include <iostream>

using namespace std;

class Stack
{
private:
    int max_sz;
    int sz;
    int* arr;
public:
    // constructor & destructor
    /**
     * @param size 同时在栈内的元素个数最多为size
     */
    Stack(int size) : sz(0), max_sz(size)
    {
        arr = new int[size];
    }

    ~Stack()
    {
        delete arr;
    }

    // size
    bool empty() const
    {
        return sz == 0;
    }

    size_t size() const
    {
        return sz;
    }

    // read
    int peek()
    {
        return arr[sz - 1];
    }

    // write
    void push(int x)
    {
        if(sz >= max_sz)
        {
            cout << "stack is full" << endl;
            return;
        }
        arr[sz++] = x;
    }

    int pop()
    {
        if(empty())
        {
            cout << "stack is empty" << endl;
            return -1;
        }
        return arr[--sz];
    }

    void print()
    {
        for(int i = 0; i < sz; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    // 创建一个大小为5的栈
    Stack myStack(5);

    // 测试空栈情况
    cout << "Is the stack empty? " << (myStack.empty() ? "Yes" : "No") << endl;

    // 压栈操作
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // 输出当前栈的大小
    cout << "Current stack size: " << myStack.size() << endl;

    // 查看栈顶元素但不移除
    cout << "Top element is: " << myStack.peek() << endl;

    // 弹栈操作并输出弹出的元素
    cout << "Popped: " << myStack.pop() << endl;
    cout << "Popped: " << myStack.pop() << endl;

    // 再次检查栈是否为空及大小
    cout << "Is the stack empty after pops? " << (myStack.empty() ? "Yes" : "No") << endl;
    cout << "Final stack size: " << myStack.size() << endl;
    return 0;
}
