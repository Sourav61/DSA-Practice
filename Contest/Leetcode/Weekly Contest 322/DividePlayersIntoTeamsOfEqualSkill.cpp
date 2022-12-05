// https://leetcode.com/contest/weekly-contest-322/problems/divide-players-into-teams-of-equal-skill//

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long dividePlayers(vector<int> &skill)
    {
        sort(skill.begin(), skill.end());

        int n = skill.size();

        int start = 0;
        int end = n - 1;

        long long sum = skill[0] + skill[n - 1];

        long long product = 0;

        while (start < end)
        {
            if (skill[start] + skill[end] == sum)
            {
                product += (skill[start] * skill[end]);
            }
            else
            {
                return -1;
            }

            start++;
            end--;
        }

        return product;
    }
};

int main()
{
    Solution obj;

    vector<int> skill = {3, 2, 5, 1, 3, 4};

    cout << obj.dividePlayers(skill);

    return 0;
}