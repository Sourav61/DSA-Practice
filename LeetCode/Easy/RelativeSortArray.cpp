// https://leetcode.com/problems/relative-sort-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        vector<int> res;
        unordered_map<int, int> mp;
        for (auto x : arr1)
        {
            mp[x]++;
        }
        vector<int>::iterator it;

        for (auto x : arr2)
        {
            for (int i = 0; i < mp[x]; i++)
            {
                res.push_back(x);
            }
        }
        sort(arr1.begin(), arr1.end());

        for (auto x : arr1)
        {
            it = find(arr2.begin(), arr2.end(), x);
            if (it - arr2.begin() == arr2.size())
            {
                res.push_back(x);
            }
        }

        return res;
    }
};

int main()
{

    Solution obj;

    vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vector<int> arr2 = {2, 1, 4, 3, 9, 6};

    vector<int> res = obj.relativeSortArray(arr1, arr2);

    for (auto x : res)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}