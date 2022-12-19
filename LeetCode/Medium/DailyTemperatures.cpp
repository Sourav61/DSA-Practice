// https://leetcode.com/problems/daily-temperatures/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> st;

        vector<int> ans(temperatures.size(), 0);
        ans[temperatures.size() - 1] = 0;

        for (int i = temperatures.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && temperatures[st.top()] <= temperatures[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                ans[i] = (st.top() - i);
            }
            st.push(i);
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};

    cout << obj.dailyTemperatures(temperatures);

    return 0;
}