// https://leetcode.com/problems/find-k-th-smallest-pair-distance/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &nums, int diff, int k)
    {
        int pairs = 0;
        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            while (j < nums.size() && nums[j] - nums[i] <= diff)
            {
                j++;
            }
            pairs += (j - i - 1);
        }
        return pairs >= k;
    }

    int smallestDistancePair(vector<int> &nums, int k)
    {
        int low = 0;
        int high = 1e6;
        sort(nums.begin(), nums.end());
        while (low < high)
        {
            int mid = (low + high) / 2;
            if (isPossible(nums, mid, k) == true)
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {1, 3, 1};

    int k = 1;

    cout << obj.smallestDistancePair(nums, k) << endl;

    return 0;
}