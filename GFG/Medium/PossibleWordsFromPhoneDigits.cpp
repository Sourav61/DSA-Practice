// https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1/#

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Function to find list of all words possible by pressing given numbers.
    vector<string> ans;

    string btn[10] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void solve(int a[], int n, string s, int idx)
    {
        if (idx == n)
        {
            ans.push_back(s);
            return;
        }

        string alpha = btn[a[idx] - 2]; // 2 no btn ka idx 0 pr data present
        for (int i = 0; i < alpha.length(); i++)
        {
            solve(a, n, s + alpha[i], idx + 1);
        }
    }

    // Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int n)
    {
        // Your code here

        int idx = 0;
        string s = "";
        solve(a, n, s, 0);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{

    int T;

    cin >> T; // testcases

    while (T--)
    { // while testcases exist
        int N;

        cin >> N; // input size of array

        int a[N]; // declare the array

        for (int i = 0; i < N; i++)
        {
            cin >> a[i]; // input the elements of array that are keys to be pressed
        }

        Solution obj;

        vector<string> res = obj.possibleWords(a, N);
        for (string i : res)
            cout << i << " ";
        cout << endl;
    }

    return 0;
} // } Driver Code Ends