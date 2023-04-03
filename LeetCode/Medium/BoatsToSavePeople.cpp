// https://leetcode.com/problems/boats-to-save-people/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        sort(people.begin(), people.end());

        int n = people.size(), res = 0;

        int l = 0, r = n - 1;

        while (l <= r)
        {
            int temp = people[l] + people[r];
            if (temp <= limit)
            {
                l++;
                r--;
            }
            else
            {
                r--;
            }
            res++;
        }

        return res;
    }
};

int main()
{

    Solution obj;

    vector<int> people = {3, 2, 2, 1};

    cout << obj.numRescueBoats(people, 3);

    return 0;
}