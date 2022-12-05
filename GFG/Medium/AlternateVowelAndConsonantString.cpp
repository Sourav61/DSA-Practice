// https://practice.geeksforgeeks.org/problems/alternate-vowel-and-consonant-string2939/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string rearrange(string S, int N)
    {
        vector<int> vowel(26), conso(26);
        int nv = 0, nc = 0;
        for (int i = 0; i < N; i++)
        {
            if (S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u')
            {
                vowel[S[i] - 'a'] += 1;
                nv++;
            }
            else
            {
                conso[S[i] - 'a'] += 1;
                nc++;
            }
        }

        if (abs(nc - nv) > 1)
        {
            return "-1";
        }
        int v = 0, c = 1;

        string ans = "";
        bool isVowel = nv >= nc ? true : false;

        int i = 0, j = 0;

        while (i < 26 && j < 26)
        {
            if (isVowel)
            {
                if (vowel[i] > 0)
                {
                    ans += i + 'a';
                    vowel[i]--;
                    isVowel = !isVowel;
                }
                if (vowel[i] == 0)
                {
                    i++;
                }
            }
            else
            {
                if (conso[j] > 0)
                {
                    ans += j + 'a';
                    conso[j]--;
                    isVowel = !isVowel;
                }
                if (conso[j] == 0)
                {
                    j++;
                }
            }
        }

        if (ans.size() == N)
        {
            return ans;
        }

        if (i < 26 && isVowel)
        {
            ans += i + 'a';
        }

        if (j < 26 && !isVowel)
        {
            ans += j + 'a';
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
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution ob;
        cout << ob.rearrange(s, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends