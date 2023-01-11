// https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minIncrementForUnique(vector<int> &arr)
    {
        long count = 0;
        int N = arr.size();

        sort(arr.begin(), arr.end());

        for (int i = 1; i < N; i++)
        {
            if (arr[i] == arr[i - 1])
            {
                int val = arr[i - 1] - arr[i] + 1;
                count += val;
                arr[i] += val;
            }
        }

        return count;
    }
};

int main()
{

    Solution obj;

    vector<int> arr = {1, 2, 2};

    cout << obj.minIncrementForUnique(arr);

    return 0;
}