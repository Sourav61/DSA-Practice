// https://leetcode.com/problems/132-pattern/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool NGE(vector<int> &mini, vector<int> &arr, int n)
    {
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && mini[i] >= st.top())
            {
                st.pop();
            }
            if (!st.empty() && mini[i] < arr[i] && arr[i] > st.top())
                return true;

            st.push(arr[i]);
        }

        return false;
    }

    bool find132pattern(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> mini(n, 0);

        mini[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            mini[i] = min(nums[i], mini[i - 1]);
        }
        return NGE(mini, nums, n);
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {-1, 3, 2, 0};

    cout << obj.find132pattern(nums);

    return 0;
}