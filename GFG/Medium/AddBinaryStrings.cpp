// https://practice.geeksforgeeks.org/problems/add-binary-strings3805/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    // string addBinary(string A, string B)
    // {
    //     int n = A.length();
    //     int m = B.length();

    //     string num = "";
    //     int idx = 0;
    //     char prev_carry;
    //     while (n-- && m--)
    //     {
    //         // A[n] and B[m]

    //         char a = A[n];
    //         char b = B[m];

    //         if (prev_carry == '1')
    //         {
    //             if (a == '1' && b == '1')
    //             {
    //                 num += '1';
    //                 prev_carry = '1';
    //             }
    //             else if ((a == '1' && b == '0') || (a == '0' && b == '1'))
    //             {
    //                 num += '0';
    //                 prev_carry = '1';
    //             }
    //             else
    //             {
    //                 num += '1';
    //                 prev_carry = '0';
    //             }
    //         }
    //         else
    //         {
    //             if (a == '1' && b == '1')
    //             {
    //                 num += '0';
    //                 prev_carry = '1';
    //             }
    //             else if ((a == '1' && b == '0') || (a == '0' && b == '1'))
    //             {
    //                 num += '1';
    //                 prev_carry = '0';
    //             }
    //             else
    //             {
    //                 num += '0';
    //                 prev_carry = '0';
    //             }
    //         }

    //         cout << idx << "->>" << a << " " << b << " " << prev_carry << " " << num << endl;

    //         idx++;
    //     }

    //     // cout<<num<<endl;

    //     while (n >= 0)
    //     {
    //         // A[n] and B[m]

    //         char a = A[n];

    //         if (prev_carry == '1')
    //         {
    //             if (a == '1')
    //             {
    //                 num += '0';
    //                 prev_carry = '1';
    //             }
    //             else
    //             {
    //                 num += '1';
    //                 prev_carry = '0';
    //             }
    //         }
    //         else
    //         {
    //             if (a == '1')
    //             {
    //                 num += '1';
    //                 prev_carry = '0';
    //             }
    //             else
    //             {
    //                 num += '0';
    //                 prev_carry = '0';
    //             }
    //         }

    //         cout << idx << "->>" << a << " " << prev_carry << " " << num << endl;

    //         idx++;
    //         n--;
    //     }

    //     while (m >= 0)
    //     {
    //         // A[n] and B[m]

    //         char b = A[m];

    //         if (prev_carry == '1')
    //         {
    //             if (b == '1')
    //             {
    //                 num += '0';
    //                 prev_carry = '1';
    //             }
    //             else
    //             {
    //                 num += '1';
    //                 prev_carry = '0';
    //             }
    //         }
    //         else
    //         {
    //             if (b == '1')
    //             {
    //                 num += '1';
    //                 prev_carry = '0';
    //             }
    //             else
    //             {
    //                 num += '0';
    //                 prev_carry = '0';
    //             }
    //         }

    //         // cout<<idx<<"->>"<<b<<" "<<prev_carry<<" "<<num<<endl;

    //         idx++;
    //         m--;
    //     }
    //     cout << prev_carry << endl;
    //     if (prev_carry == '1')
    //     {
    //         num += '1';
    //     }
    //     cout << num << endl;
    //     reverse(num.begin(), num.end());
    //     int id = 0;
    //     string res = "";
    //     while (id < num.length())
    //     {
    //         // cout<<num[id]<<" "<<id<<endl;
    //         if (num[id] == '1')
    //         {
    //             // cout<<num.substr(id)<<endl;
    //             res = num.substr(id);
    //             break;
    //         }
    //         id++;
    //     }
    //     // cout<<num<<endl;
    //     return res;
    // }

    string addBinary(string a, string b)
    {
        int n = a.size(), m = b.size();
        string sum;
        int carry = 0;

        int i = n - 1, j = m - 1;
        while (i >= 0 || j >= 0 || carry > 0)
        {
            if (i >= 0)
            {
                carry += a[i] - '0';
                i--;
            }
            if (j >= 0)
            {
                carry += b[j] - '0';
                j--;
            }
            sum += (carry % 2) + '0';
            carry /= 2;
        }

        j = sum.length() - 1;
        while (sum[j] != '1')
        {
            sum.pop_back();
            j--;
        }

        reverse(sum.begin(), sum.end());

        return sum;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends