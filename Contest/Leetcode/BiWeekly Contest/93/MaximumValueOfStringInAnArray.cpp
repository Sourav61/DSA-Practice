// https://leetcode.com/contest/biweekly-contest-93/problems/maximum-value-of-a-string-in-an-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumValue(vector<string> &strs)
    {
        int n = strs.size();

        int maxi = 0;

        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < strs[i].length(); j++)
            {
                if (strs[i][j] >= 47 && strs[i][j] <= 59)
                {
                    cnt++;
                }
            }

            if (cnt == strs[i].length())
            {
                maxi = max(maxi, stoi(strs[i]));
            }
            else
            {
                if (strs[i].length() > maxi)
                {
                    maxi = strs[i].length();
                }
            }
        }

        return maxi;
    }
};

int main()
{
    Solution obj;

    vector<string> res = {"alic3", "bob", "3", "4", "00000"};

    cout << obj.maximumValue(strs);

    return 0;
}