// https://leetcode.com/problems/kth-missing-positive-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int i = 1, j = 0, n = arr.size();

        while (j < n)
        {
            if (arr[j] == i)
            {
                j++;
                i++;
                continue;
            }
            k--;
            if (k == 0)
            {
                break;
            }
            i++;
        }

        return k > 0 ? i + k - 1 : i;
    }
};

int main()
{

    Solution obj;
    vector<int> arr = {2, 3, 4, 7, 11};

    cout << obj.findKthPositive(arr, 5);

    return 0;
}