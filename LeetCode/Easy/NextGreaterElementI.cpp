// https://leetcode.com/problems/next-greater-element-i/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        int ind = 0;

        stack<int> st;
        vector<int> ans(m, -1);
        vector<int>::iterator it;

        for (int i = m - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums2[i])
            {
                st.pop();
            }

            if (i < m)
            {
                if (!st.empty())
                {
                    ans[i] = st.top();
                }
            }

            st.push(nums2[i]);
        }
        
        for(auto x : ans){
            cout<<x<<" ";
        }

        for (int i = 0; i < n; i++)
        {
            it = find(nums2.begin(), nums2.end(), nums1[i]);
            ind = it - nums2.begin();
            nums1[i] = ans[ind];
        }

        return nums1;
    }
};

int main()
{

    Solution obj;

    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> res = obj.nextGreaterElement(nums1, nums2);

    for (auto x : res)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}