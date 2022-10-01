// https://leetcode.com/problems/xor-queries-of-a-subarray/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        vector<int> res;

        for (int i = 1; i < arr.size(); i++)
        {
            arr[i] = arr[i] ^ arr[i - 1];
        }

        for (int i = 0; i < queries.size(); i++)
        {
            int start = queries[i][0];
            int end = queries[i][1];

            if (start == 0)
            {
                ans.push_back(arr[end]);
            }
            else
            {
                ans.push_back(arr[start - 1] ^ arr[end]);
            }
        }
        return ans;
    }
};

int main()
{

    Solution obj;

    vector<int> arr = {1, 3, 4, 8};

    vector<vector<int>> quaries = {{0, 1}, {1, 2}, {0, 3}, {3, 3}};

    vector<int> ans = obj.xorQueries(arr, quaries);

    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}