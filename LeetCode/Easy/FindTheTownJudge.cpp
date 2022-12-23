// https://leetcode.com/problems/find-the-town-judge/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> degree(n + 1, 0);

        for (auto &x : trust)
        {
            degree[x[0]]--;
            degree[x[1]]++;
        }

        for (int i = 1; i <= n; i++)
        {
            if (degree[i] == n - 1)
                return i;
        }

        return -1;
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> trust = {{1, 3}, {2, 3}};

    cout << obj.findJudge(3, trust);

    return 0;
}