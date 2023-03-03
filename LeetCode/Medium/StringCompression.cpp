// https://leetcode.com/problems/string-compression/description/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Os")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int n = chars.size();
        if (n == 1)
        {
            return 1;
        }

        int i = 0, j = 0;
        while (i < n)
        {
            int count = 1;
            while (i < n - 1 && chars[i] == chars[i + 1])
            {
                count++;
                i++;
            }

            chars[j++] = chars[i++];
            if (count > 1)
            {
                string countStr = to_string(count);
                for (auto &c : countStr)
                {
                    chars[j++] = c;
                }
            }
        }

        return j;
    }
};

int main()
{

    Solution obj;

    vector<char> chars = {"a", "a", "b", "b", "c", "c", "c"};

    cout << obj.compress(chars);

    return 0;
}