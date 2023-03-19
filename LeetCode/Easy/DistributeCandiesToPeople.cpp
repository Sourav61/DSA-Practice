// https://leetcode.com/problems/distribute-candies-to-people/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> distributeCandies(int N, int K)
    {
        vector<int> res(K, 0);
        int i = 0;

        while (true)
        {
            if (N < (((i / K) * K) + (i % K) + 1))
            {
                res[i % K] += N;
                break;
            }

            N -= (((i / K) * K) + (i % K) + 1);
            res[i % K] += (((i / K) * K) + (i % K)) + 1;
            i++;
        }

        return res;
    }
};

int main()
{

    Solution obj;

    cout << obj.distributeCandies(10, 3);

    return 0;
}