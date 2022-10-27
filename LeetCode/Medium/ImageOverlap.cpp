// https://leetcode.com/problems/image-overlap/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shift_count(vector<vector<int>> &img1, vector<vector<int>> &img2)
    {
        int n = img1.size(), count = 0;
        for (int x = 0; x < n; ++x)
        {
            for (int y = 0; y < n; ++y)
            {
                int temp = 0;
                for (int i = x; i < n; ++i)
                {
                    for (int j = y; j < n; ++j)
                    {
                        if (img1[i][j] == 1 && img2[i - y][j - x] == 1)
                        {
                            temp++;
                        }
                    }
                }
                count = max(count, temp);
            }
        }

        return count;
    }

    int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
    {
        return max(shift_count(img1, img2), shift_count(img2, img1));
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> img1{{1, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    vector<vector<int>> img2{{0, 0, 0}, {0, 1, 1}, {0, 0, 1}};

    cout << obj.largestOverlap(img1, img2);

    return 0;
}