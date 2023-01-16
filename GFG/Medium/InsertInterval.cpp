// https://practice.geeksforgeeks.org/problems/insert-interval-1666733333/1?page=1&sortBy=accuracy

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<vector<int>> insertNewEvent(int N, vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int n = intervals.size();
        vector<vector<int>> res;

        if (n == 0)
        {
            res.push_back(newInterval);
            return res;
        }

        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (intervals[mid][0] < newInterval[0])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        while (high >= 0 && intervals[high][1] >= newInterval[0])
        {
            newInterval[0] = min(newInterval[0], intervals[high][0]);
            newInterval[1] = max(newInterval[1], intervals[high][1]);
            high--;
        }

        while (low < n && intervals[low][0] <= newInterval[1])
        {
            newInterval[1] = max(newInterval[1], intervals[low][1]);
            low++;
        }

        int i = 0;
        while (high >= 0 && i <= high)
        {
            res.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }

        res.push_back({newInterval[0], newInterval[1]});

        i = low;

        while (i < n)
        {
            res.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }

        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++)
        {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        vector<int> newEvent(2);
        cin >> newEvent[0] >> newEvent[1];

        Solution obj;
        vector<vector<int>> ans = obj.insertNewEvent(N, intervals, newEvent);
        cout << "[";
        for (int i = 0; i < ans.size(); i++)
        {
            cout << "[" << ans[i][0] << ',' << ans[i][1] << ']';
            if (i != (ans.size() - 1))
                cout << ",";
        }
        cout << "]" << endl;
    }
    return 0;
}
// } Driver Code Ends