// https://leetcode.com/problems/find-unique-binary-string/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        string res = "";
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            res += nums[i][i] == '0' ? '1' : '0';
        }

        return res;
    }
};

int main()
{

    Solution obj;

    vector<string> nums = {"01", "10"};

    cout << obj.findDifferentBinaryString(nums);

    return 0;
}