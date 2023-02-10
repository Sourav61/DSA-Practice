// https://leetcode.com/problems/fruit-into-baskets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size(), j = 0, res = 0;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[fruits[i]]++;

            while (mp.size() > 2 && j <= i)
            {
                mp[fruits[j]]--;
                if (mp[fruits[j]] == 0)
                {
                    mp.erase(fruits[j]);
                }
                j++;
            }

            res = max(res, i - j + 1);
        }

        return res;
    }
};

int main()
{

    Solution obj;

    vector<int> fruits = {1, 2, 1};

    cout << obj.totalFruit(fruits);

    return 0;
}