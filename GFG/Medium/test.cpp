
// https://leetcode.com/problems/maximum-candies-allocated-to-k-children/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumCandies(vector<string> &a)
    {

        for (auto &x : a)
        {
            if (x.length > len)
            {
                len = x.length();
            }
        }
        string str = "";
        int k = 0;
        while (k < n)
        {
            for (int i = 0; i < n; i++)
            {
                if (arr[i].size() < k)
                {
                    str.push_back(arr[i][k]);
                }
            }
            k++;
        }

        return str;
    }
};

int main()
{

    Solution obj;
    vector<string> candies = {"Daisy", "Rose", "Hyacinth", "Poppy"};

    cout << obj.maximumCandies(candies);

    return 0;
}