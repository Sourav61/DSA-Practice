// https://practice.geeksforgeeks.org/problems/c670bf260ea9dce6c5910dedc165aa403f6e951d/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

// } Driver Code Ends
class Solution
{
public:
    vector<int> getDistinctDifference(int N, vector<int> &A)
    {
        vector<int> res;

        unordered_map<int, int> mL, mR;

        for (auto &x : A)
        {
            mR[x]++;
        }

        for (auto &x : A)
        {
            mR[x]--;
            if (mR[x] == 0)
            {
                mR.erase(x);
            }
            res.push_back(mL.size() - mR.size());
            mL[x]++;
        }

        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int N;
        scanf("%d", &N);

        vector<int> A(N);
        Array::input(A, N);

        Solution obj;
        vector<int> res = obj.getDistinctDifference(N, A);

        Array::print(res);
    }
}

// } Driver Code Ends