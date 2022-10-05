// https://leetcode.com/problems/minimum-number-of-refueling-stops/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        int n = stations.size();
        sort(stations.begin(), stations.end());
        int ans = 0;
        int curr = startFuel;

        priority_queue<int, vector<int>> maxH;
        bool flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (curr >= target)
            {
                break;
            }

            while (curr < stations[i][0])
            {
                if (maxH.empty())
                {
                    flag = 1;
                    break;
                }
                ans++;
                curr += maxH.top();
                maxH.pop();
            }

            if (flag)
                break;

            maxH.push(stations[i][1]);
        }

        if (flag)
            return -1;

        while (!maxH.empty() && curr < target)
        {
            curr += maxH.top();
            maxH.pop();
            ans++;
        }

        if (curr < target)
            return -1;

        return ans;
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> stations = {{10, 60}, {20, 30}, {30, 30}, {60, 40}};
    int target = 100;
    int startFuel = 10;

    cout << obj.minRefuelStops(target, startFuel, stations);

    return 0;
}