// https://practice.geeksforgeeks.org/problems/asteroid-collision/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids)
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

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++)
            cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans)
            cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends