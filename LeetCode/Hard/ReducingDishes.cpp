// https://leetcode.com/problems/reducing-dishes/description/

#include <bitsstdc++.h>
using namespace std;

class Solution
{
public:
    int maxSatisfaction(vector<int> &sf)
    {
        sort(sf.begin(), sf.end());
        int n = sf.size();
        int i = 0, res = INT_MIN;
        while (i < n)
        {
            int temp = 0;
            for (int j = i; j < n; j++)
            {
                temp += (sf[j] * (j - i + 1));
            }

            res = max(res, temp);
            i++;
        }

        return res > 0 ? res : 0;
    }
};

int main()
{

    Solution obj;
    vector<int> sf = {-1, -8, 0, 5, -9};

    cout << obj.maxSatisfaction(sf);

    return 0;
}