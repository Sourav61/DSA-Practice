// https://practice.geeksforgeeks.org/problems/design-browser-history/1

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class BrowserHistory {
public:
     // constructor to initialize object with homepage
    stack<string> forw, hist;
    BrowserHistory(string homepage) {
        hist.push(homepage);
    }
    
    void visit(string url) {
        hist.push(url);
        while(!forw.empty()){
            forw.pop();
        }
    }
    
    string back(int steps) {
        while(hist.size() > 1 && steps--){
            forw.push(hist.top());
            hist.pop();
        }
        
        return hist.top();
    }
    
    string forward(int steps) {
        while(!forw.empty() && steps--){
            hist.push(forw.top());
            forw.pop();
        }
        
        return hist.top();
    }
};

//{ Driver Code Starts.

int main()
{
    string homepage;
    cin >> homepage;
    
    BrowserHistory obj(homepage);
    
    int total_queries;
    cin >> total_queries;
    while(total_queries--)
    {
        int query;
        cin >> query;
        
        // if query = 1, visit()
        // if query = 2, back()
        // if query = 3, forward()
        
        if(query == 1) {
            string url;
            cin >> url;
            obj.visit(url);
        }
        else if(query == 2) {
            int steps;
            cin >> steps;
            cout << obj.back(steps) << endl;
        }
        else {
            int steps;
            cin >> steps;
            cout << obj.forward(steps) << endl;
        }
    }
    return 0;
}
// } Driver Code Ends