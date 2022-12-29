// https://leetcode.com/problems/asteroid-collision/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> res;
        stack<int> st;

        for (auto &x : asteroids)
        {
            if (!st.empty() && x < 0 && st.top() > 0)
            {
                int temp = abs(x);

                while (!st.empty() && st.top() < temp && st.top() > 0)
                {
                    st.pop();
                }

                if (!st.empty() && st.top() == temp)
                {
                    st.pop();
                    continue;
                }
                else if (!st.empty() && st.top() > temp)
                {
                    continue;
                }

                st.push(x);
            }
            else
            {

                st.push(x);
            }
        }

        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};

int main()
{

    Solution obj;

    vector<int> asteroids = {5, 10, -5};

    cout << obj.asteroidCollision(asteroids);

    return 0;
}