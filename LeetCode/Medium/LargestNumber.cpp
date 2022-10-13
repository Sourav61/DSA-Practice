// https://leetcode.com/problems/largest-number/

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> temp;
        for (auto x : nums)
            temp.push_back(to_string(x));
        sort(begin(temp), end(temp), [](string &s1, string &s2)
             { return s1 + s2 > s2 + s1; });

        string res;

        for (auto x : temp)
            res += x;

        while (res[0] == '0' && res.length() > 1)
            res.erase(0, 1);

        return res;
    }
};