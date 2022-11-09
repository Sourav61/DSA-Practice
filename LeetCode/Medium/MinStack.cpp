// https://leetcode.com/problems/min-stack/description/

#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    stack<int> s;
    stack<int> ss;
    MinStack()
    {
    }

    void push(int val)
    {
        s.push(val);

        if (ss.empty() || ss.top() >= val)
        {
            ss.push(val);
        }
    }

    void pop()
    {
        if (s.empty())
        {
            return;
        }

        int a = s.top();

        if (a == ss.top())
        {
            ss.pop();
        }

        s.pop();
    }

    int top()
    {
        if (s.empty())
        {
            return -1;
        }

        return s.top();
    }

    int getMin()
    {
        if (ss.empty())
        {
            return -1;
        }
        return ss.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{

    MinStack *obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(3);
    int param_1 = obj->getMin();
    obj->pop();
    int param_2 = obj->top();
    int param_3 = obj->getMin();

    cout << param_1 << " " << param_2 << " " << param_3 << endl;

    return 0;
}