// https://leetcode.com/problems/k-closest-points-to-origin/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<vector<int>> ans;

        int n = points.size();

        priority_queue<pair<int, vector<int>>> maxH;

        for (vector<int> v : points)
        {
            int euclid = 0;
            for (auto x : v)
                euclid += x * x;

            maxH.push({euclid, v});

            if (maxH.size() > k)
                maxH.pop();
        }

        while (!maxH.empty())
        {
            ans.push_back(maxH.top().second);
            maxH.pop();
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    vector<vector<int>> points = {{1, 3}, {-2, 2}};

    int k = 1;

    vector<vector<int>> ans = obj.kClosest(points, k);

    for (vector<int> v : ans)
    {
        for (auto x : v)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}