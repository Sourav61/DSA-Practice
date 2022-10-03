// https://leetcode.com/problems/mean-of-array-after-removing-some-elements/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double trimMean(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        double sum = 0;

        for (int i = 0.05 * n; i < n - 0.05 * n; i++)
        {
            sum += arr[i];
        }

        return sum / (0.9 * n);
    }
};

int main()
{

    Solution obj;
    vector<int> arr = {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3};

    cout << obj.trimMean(arr) << endl;

    return 0;
}