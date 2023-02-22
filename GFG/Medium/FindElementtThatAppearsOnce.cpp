// https://practice.geeksforgeeks.org/problems/element-appearing-once2552/1/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int search(int nums[], int n)
    {
        // int res = 0;
        // if(n == 1){
        //     return nums[0];
        // }

        // for(int i=0;i<n;i+=2){
        //     if(nums[i] != nums[i + 1]){
        //         return nums[i];
        //     }
        // }

        // return -1;
        int res = 0;
        if (n == 1)
        {
            return nums[0];
        }

        int low = 0, high = n - 1, mid = 0;

        if (high == 0)
        {
            return nums[high];
        }
        else if (nums[low] != nums[low + 1])
        {
            return nums[low];
        }
        else if (nums[high] != nums[high - 1])
        {
            return nums[high];
        }

        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            {
                return nums[mid];
            }
            else if ((nums[mid] == nums[mid - 1] && mid % 2 != 0) || (nums[mid] == nums[mid + 1] && mid % 2 == 0))
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return -1;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t, len;
    cin >> t;
    while (t--)
    {
        cin >> len;
        int arr[len];
        for (int i = 0; i < len; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.search(arr, len) << '\n';
    }
    return 0;
}

// } Driver Code Ends