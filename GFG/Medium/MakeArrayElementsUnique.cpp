// https://practice.geeksforgeeks.org/problems/6e63df6d2ebdf6408a9b364128bb1123b5b13450/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    long long int minIncrements(vector<int> arr, int N)
    {
        // -----------------------------      O(N*N) Approach      -------------------------------

        // unordered_map<int,int> mp;
        // int res = 0;
        // int n = nums.size();

        // for(auto &x : nums){
        //     mp[x]++;
        // }

        // for(int i=0;i<n;i++){
        //     mp[nums[i]]--;
        //     while(mp[nums[i]]){
        //         nums[i]++;
        //         res++;
        //     }
        //     mp[nums[i]] = 1;
        // }

        // return res;

        // -----------------------------      O(N*log(N)) Approach      -------------------------------

        long count = 0;
        sort(arr.begin(), arr.end());
        for (int i = 1; i < N; i++)
        {
            if (arr[i] <= arr[i - 1])
            {
                cout << arr[i] << " " << arr[i - 1] << endl;
                int val = arr[i - 1] - arr[i] + 1;
                count += val;
                arr[i] += val;
            }
        }
        return count;
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
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends