// https://leetcode.com/problems/implement-stack-using-queues/

#include<bits/stdc++.h>
using namespace std;

class MyStack {
public:
    int N;
    queue<int> q1;
    queue<int> q2;
    
    MyStack() {
        N = 0;
    }
    
    void push(int x) {
        q2.push(x);
        N++;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    
    int pop() {
        int ans = q1.front();
        q1.pop();
        N--;
        return ans;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        if(N==0)
            return true;
            
        return false;
    }
};

// int main(){
//     MyStack* obj = new MyStack();
//     obj->push(1);
//     obj->push(2);
//     int param_3 = obj->top();
//     int param_2 = obj->pop();
//     bool param_4 = obj->empty();

//     cout<<param_2<<" "<<param_3<<" "<<param_4<<endl;
// }

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */