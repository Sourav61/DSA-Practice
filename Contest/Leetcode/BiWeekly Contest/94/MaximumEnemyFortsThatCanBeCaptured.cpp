// https://leetcode.com/problems/maximum-enemy-forts-that-can-be-captured/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int captureForts(vector<int> &forts)
    {
        int n = forts.size();
        int maxi = 0;

        for (int i = 0; i < n; i++)
        {
            if (forts[i] == 1)
            {
                int cnt = 0;
                for (int j = i + 1; j < n; j++)
                {
                    if (forts[j] == 1)
                    {
                        break;
                    }
                    if (forts[j] == -1)
                    {
                        maxi = max(maxi, cnt);
                        break;
                    }
                    if (forts[j] == 0)
                    {
                        cnt++;
                    }
                }
                cnt = 0;
                for (int j = i - 1; j >= 0; j--)
                {
                    if (forts[j] == 1)
                    {
                        break;
                    }
                    if (forts[j] == -1)
                    {
                        maxi = max(maxi, cnt);
                        break;
                    }
                    if (forts[j] == 0)
                    {
                        cnt++;
                    }
                }
            }
        }

        return maxi;
    }
};

int main()
{
    Solution obj;

    vector<int> forts = {1, 0, 0, -1, 0, 0, 0, 0, 1};

    cout << obj.captureForts(forts) << endl;

    return 0;
}