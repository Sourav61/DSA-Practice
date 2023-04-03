// https://practice.geeksforgeeks.org/problems/1e2f365be6114b671b915e145ec7dbcfdc432910/1

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    string removeReverse(string S)
    {
        int n = S.size();
        vector<int> freq(26);
        bool rev = false;
        for (int i = 0; i < n; i++)
            freq[S[i] - 'a']++;

        vector<int> arr(n, 0);

        int i = 0, j = n - 1;
        while (i <= j)
        {
            if (rev == false)
            {
                // cout<<1<<" "<<S[i]<<endl;
                if (freq[S[i] - 'a'] == 1)
                {
                    arr[i] = 1;
                }
                else
                {
                    freq[S[i] - 'a']--;
                    rev = true;
                }
                i++;
            }
            else
            {
                // cout<<2<<" "<<S[j]<<endl;
                if (freq[S[j] - 'a'] == 1)
                {
                    arr[j] = 1;
                }
                else
                {
                    freq[S[j] - 'a']--;
                    rev = false;
                }
                j--;
            }
        }

        string ans;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
                continue;
            ans.push_back(S[i]);
        }

        if (rev == true)
        {
            reverse(ans.begin(), ans.end());
            return ans;
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout << ans << endl;
    }
}
// } Driver Code Ends