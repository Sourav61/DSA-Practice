// https://leetcode.com/problems/edit-distance/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;

    int f(int i, int j, string &s1, string &s2)
    {
        if (i < 0)
        {
            return j + 1;
        }

        if (j < 0)
        {
            return i + 1;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j])
        {
            return dp[i][j] = (0 + f(i - 1, j - 1, s1, s2));
        };

        return dp[i][j] = (1 + min(
                                   f(i, j - 1, s1, s2),         // Insert
                                   min(f(i - 1, j, s1, s2),     // Delete
                                       f(i - 1, j - 1, s1, s2)) // Replace
                                   ));
    }

    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        dp.resize(n, vector<int>(m, -1));
        return f(n - 1, m - 1, word1, word2);
    }
};

int main()
{

    Solution obj;

    cout << obj.minDistance("horse", "ros");

    return 0;
}