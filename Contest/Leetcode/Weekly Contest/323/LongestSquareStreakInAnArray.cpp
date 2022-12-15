// https://leetcode.com/contest/weekly-contest-323/problems/longest-square-streak-in-an-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSquareStreak(vector<int> &nums)
    {
        int n = nums.size();
        int sz = 100001;
        vector<int> temp(sz, 0);

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            temp[nums[i]] = 1;
        }

        int maxi = 1;

        for (long long int i = 1; i < sz; i++)
        {
            if (temp[i] == 1)
            {

                int cnt = 1;
                for (long long int j = i * i; j <= sz;)
                {
                    if (temp[j] == 1)
                    {
                        cnt++;
                        j *= j;
                    }
                    else
                    {
                        break;
                    }
                }

                maxi = max(cnt, maxi);
            }
        }

        return maxi == 1 ? -1 : maxi;
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {4, 3, 6, 16, 8, 2};

    cout << obj.longestSquareStreak(nums) << endl;

    return 0;
}