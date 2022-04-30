// https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1/#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void permutate(string str, vector<string> &result, string ans = "")
    {
        if (str.length() == 0)
        {
            result.push_back(ans);
            return;
        }

        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];
            string ros = str.substr(0, i) + str.substr(i + 1);
            permutate(ros, result, ans + ch);
        }
    }

    vector<string> find_permutation(string S)
    {
        vector<string> result;
        permutate(S, result);
        sort(result.begin(), result.end());
        return result;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.find_permutation(S);
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends