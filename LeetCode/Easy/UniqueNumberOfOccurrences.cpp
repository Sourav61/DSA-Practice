// https://leetcode.com/problems/unique-number-of-occurrences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> mp, mp2;

        for (auto &x : arr)
        {
            mp[x]++;
        }

        for (auto &x : mp)
        {
            if (mp2[x.second] > 0)
            {
                return false;
            }
            mp2[x.second]++;
        }

        return true;
    }
};

int main()
{
    Solution obj;

    vector<int> arr = {1, 2, 2, 1, 1, 3};

    cout << obj.uniqueOccurrences(arr);

    return 0;
}