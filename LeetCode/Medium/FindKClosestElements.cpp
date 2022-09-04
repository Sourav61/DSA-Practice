// https://leetcode.com/problems/find-k-closest-elements/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        priority_queue<pair<int, int>> maxH;

        int n = arr.size();
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            maxH.push({abs(arr[i] - x), arr[i]});
            if (maxH.size() > k)
                maxH.pop();
        }

        while (maxH.size() > 0)
        {
            ans.push_back(maxH.top().second);
            maxH.pop();
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{

    Solution obj;

    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    int x = 3;

    vector<int> ans = obj.findClosestElements(arr, k, x);

    for (auto x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}