// https://leetcode.com/contest/weekly-contest-321/problems/find-the-pivot-integer/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int pivotInteger(int n)
    {
        unordered_map<int, int> mp;
        if (n == 1)
        {
            return 1;
        }
        int a = n;
        int i = 1, sum = 0;
        while (i < n)
        {
            sum += i;
            mp[sum] = i;
            i++;
        }
        sum = n;
        while (n--)
        {
            sum += n;
            if (mp[sum] != 0 && mp[sum] == n)
            {
                return mp[sum];
            }
        }
        return -1;
    }
};

int main()
{
    Solution obj;

    cout << obj.pivotInteger(10);

    return 0;
}