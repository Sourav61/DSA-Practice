// https://leetcode.com/problems/first-bad-version/

#include <bits/stdc++.h>
using namespace std;
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        long int low = 0;
        long int high = n;
        long int ans;
        while (low <= high)
        {
            long int mid = ceil((low + high) / 2.0);

            if (isBadVersion(mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main()
{

    Solution obj;

    cout << obj.firstBadVersion(n);

    return 0;
}