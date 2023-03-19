// https://leetcode.com/problems/design-browser-history/description/

#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Os")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

class BrowserHistory
{
public:
    stack<string> forw, hist;
    BrowserHistory(string homepage)
    {
        hist.push(homepage);
    }

    void visit(string url)
    {
        hist.push(url);
        while (!forw.empty())
        {
            forw.pop();
        }
    }

    string back(int steps)
    {
        while (hist.size() > 1 && steps--)
        {
            forw.push(hist.top());
            hist.pop();
        }

        return hist.top();
    }

    string forward(int steps)
    {
        while (!forw.empty() && steps--)
        {
            hist.push(forw.top());
            forw.pop();
        }

        return hist.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

int main()
{

    BrowserHistory *obj = new BrowserHistory("leetcode.com");

    obj->visit("google.com");
    obj->visit("facebook.com");
    obj->visit("youtube.com");

    string param_1 = obj->back(1);
    string param_2 = obj->back(1);
    string param_3 = obj->forward(1);

    obj->visit("linkedin.com");

    string param_4 = obj->forward(1);
    string param_5 = obj->back(2);
    string param_6 = obj->back(7);

    cout << param_1 << " " << param_2 << " " << param_3 << " " << param_4 << " " << param_5 << " " << param_6 << endl;

    return 0;
}