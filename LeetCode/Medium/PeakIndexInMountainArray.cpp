// https://leetcode.com/problems/peak-index-in-a-mountain-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int n = arr.size();

        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            {
                return mid;
            }
            else if (arr[mid] < arr[mid + 1])
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }

        return -1;
    }
};

int main()
{

    Solution obj;

    vector<int> arr = {0, 10, 5, 2};

    cout << obj.peakIndexInMountainArray(arr) << endl;

    return 0;
}