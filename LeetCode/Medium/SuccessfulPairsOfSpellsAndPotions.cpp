// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int binarySearch(int spell, vector<int> &potions, int l, int r, long long success)
    {
        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            long long temp = (long long)potions[mid] * (long long)spell;

            if (temp < success)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return l;
    }

    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        vector<int> ans;
        int n = spells.size();
        int m = potions.size() - 1;
        sort(potions.begin(), potions.end());

        for (int i = 0; i < n; i++)
        {
            int res = binarySearch(spells[i], potions, 0, m, success);
            ans.push_back(m - res + 1);
        }

        return ans;
    }
};

int main()
{

    Solution obj;

    vector<int> spells = {5, 1, 3};

    vector<int> potions = {1, 2, 3, 4, 5};

    cout << obj.successfulPairs(spells, potions, 7);

    return 0;
}