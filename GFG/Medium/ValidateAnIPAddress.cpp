// https://practice.geeksforgeeks.org/problems/validate-an-ip-address-1587115621/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution
{
public:
    int isValid(string s)
    {
        int n = s.length();
        int cnt = 0, i = 0;
        int temp = -1;
        for (auto &x : s)
        {
            if (x != '.' && !isdigit(x))
            {
                return 0;
            }
        }
        for (int j = n - 1; j >= 0; j--)
        {
            if (s[j] == '.' || j == 0)
            {
                if (j == 0)
                {
                    temp += (s[j] - '0') * pow(10, i);
                    if (temp > 255)
                    {
                        return 0;
                    }
                    cnt++;
                    if (s[j] == '0' && i != 0)
                    {
                        return 0;
                    }
                    break;
                }
                else
                {
                    if (s[j + 1] == '0' && i != 1)
                    {
                        return 0;
                    }
                }

                if (temp > 255 || temp == -1)
                {
                    return 0;
                }
                temp = -1;
                i = 0;
                cnt++;
                continue;
            }
            if (temp == -1)
                temp++;

            temp += (s[j] - '0') * pow(10, i);
            i++;
        }

        return cnt == 4 ? 1 : 0;
    }
};

//{ Driver Code Starts.

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends