// https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int closetTarget(vector<string> &words, string target, int startIndex)
    {
        int n = words.size();
        int mini = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (words[i] == target)
            {
                mini = min(mini, min(abs(i - startIndex), min(abs((n + i) - startIndex), abs((i - n) - startIndex))));
            }
        }

        return mini == INT_MAX ? -1 : mini;
    }
};

int main()
{
    Solution obj;

    vector<string> words = {"hello", "i", "am", "leetcode", "hello"};

    cout << obj.closetTarget(words, "hello", 1);

    return 0;
}