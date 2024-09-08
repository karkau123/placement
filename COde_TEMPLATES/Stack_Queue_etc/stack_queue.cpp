#include <bits/stdc++.h>
using namespace std;

// 1. Stack USING QUEUE
class MyStack
{
    queue<int> q1, q2;

public:
    MyStack()
    {
    }
    void push(int x)
    {
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop()
    {
        int ele = q1.front();
        q1.pop();
        return ele;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};

// 2.QUEUE USING STACK

class MyQueue
{
    stack<int> s1, s2;

public:
    MyQueue() {}

    void push(int x)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop()
    {
        int ele = s1.top();
        s1.pop();
        return ele;
    }

    int peek() { return s1.top(); }

    bool empty() { return s1.empty(); }
};

int main()
{
    return 0;
}
