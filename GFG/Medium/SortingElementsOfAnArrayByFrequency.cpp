// https : // practice.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency/0

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct Comp
    {
        bool operator()(const pair<int, string> &a, const pair<int, string> &b)
        {
            if (a.first == b.first)
                return a.second < b.second;

            return a.first > b.first;
        }
    };
    vector<int> frequencySort(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> maxH;

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }

        for (auto x : mp)
        {
            maxH.push({x.second, x.first});
        }

        while (maxH.size() > 0)
        {
            int freq = maxH.top().first;
            int ele = maxH.top().second;

            for (int i = 0; i < freq; i++)
            {
                ans.push_back(ele);
            }

            maxH.pop();
        }

        return ans;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums)
            cin >> i;
        Solution obj;
        vector<int> ans = obj.frequencySort(nums);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }

    return 0;
}