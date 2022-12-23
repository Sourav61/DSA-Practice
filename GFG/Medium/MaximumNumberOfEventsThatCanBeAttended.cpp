// https://practice.geeksforgeeks.org/problems/ea8230731ccb057120bafb351c10c48b2d496125/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int maxEvents(int start[], int end[], int N)
    {
        // code here
        vector<pair<int, int>> events;
        int maxi = 0;
        for (int i = 0; i < N; i++)
        {
            events.push_back({start[i], end[i]});
        }

        sort(events.begin(), events.end());

        unordered_set<int> days;

        for (int i = N - 1; i >= 0; i--)
        {
            int start = events[i].first, end = events[i].second;
            if (days.find(end) == days.end())
            {
                days.insert(end);
            }
            else
            {
                while (end >= start)
                {
                    if (days.find(end) == days.end())
                    {
                        days.insert(end);
                        break;
                    }
                    end--;
                }
            }
        }

        return days.size();
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

        int start[N], end[N];
        for (int i = 0; i < N; i++)
            cin >> start[i];
        for (int i = 0; i < N; i++)
            cin >> end[i];

        Solution ob;
        cout << ob.maxEvents(start, end, N) << endl;
    }
    return 0;
}
// } Driver Code Ends