// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> res(n, -1);

        if (n == 1)
        {
            return {-1};
        }

        int mx = 0;

        for (int i = n - 2; i >= 0; i--)
        {
            mx = max(arr[i + 1], mx);
            res[i] = mx;
        }

        res[n - 1] = -1;

        return res;
    }
};

int main()
{

    Solution obj;

    vector<int> arr = {17, 18, 5, 4, 6, 1};

    vector<int> res = obj.replaceElements(arr);

    for (auto x : res)
        cout << x << " ";

    cout << endl;

    return 0;
}
