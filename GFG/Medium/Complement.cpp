// https://practice.geeksforgeeks.org/problems/complement3911/1

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> findRange(string str, int n)
    {
        vector<int> res;

        int isAllOne = -1;

        for (int i = 0; i < n; i++)
        {
            if (str[i] == '0')
            {
                isAllOne = 0;
                break;
            }
        }

        if (isAllOne == -1)
            return {-1};

        int max_so_far = INT_MIN, start = 0, end = 0;
        int s = 0, sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += str[i] == '1' ? -1 : 1;

            if (max_so_far < sum)
            {
                max_so_far = sum;
                start = s;
                end = i;
            }

            if (sum < 0)
            {
                sum = 0;
                s = i + 1;
            }
        }

        return {start + 1, end + 1};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution ob;
        auto ans = ob.findRange(s, n);

        if (ans.size() == 1)
        {
            cout << ans[0] << "\n";
        }
        else
        {
            cout << ans[0] << " " << ans[1] << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends