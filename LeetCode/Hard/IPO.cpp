// https://leetcode.com/problems/ipo/description/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Os")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        // int n = profits.size();

        // priority_queue<pair<int, int>> maxH;
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;

        // for (int i = 0; i < n; i++)
        // {
        //     minH.push({capital[i], profits[i]});
        // }

        // while (k > 0)
        // {
        //     while (!minH.empty() && minH.top().first <= w)
        //     {
        //         auto curr = minH.top();
        //         minH.pop();
        //         maxH.push({curr.second, curr.first});
        //     }

        //     if (!maxH.empty())
        //     {
        //         w += maxH.top().first;
        //         maxH.pop();
        //         k--;
        //     }
        //     else
        //     {
        //         break;
        //     }
        // }

        // return w;

        int n = profits.size();
        vector<pair<int, int>> temp(n);

        for (int i = 0; i < n; i++)
        {
            temp[i] = {capital[i], profits[i]};
        }

        sort(temp.begin(), temp.end());

        priority_queue<int> maxH;
        int i = 0;

        while (k--)
        {
            while (i < n && temp[i].first <= w)
            {
                maxH.push(temp[i].second);
                i++;
            }

            if (maxH.empty())
            {
                break;
            }

            w += maxH.top();
            maxH.pop();
        }

        return w;
    }
};

int main()
{

    Solution obj;

    vector<int> profits = {1, 2, 3};
    vector<int> capital = {0, 1, 1};

    cout << obj.findMaximizedCapital(2, 0, profits, capital);

    return 0;
}