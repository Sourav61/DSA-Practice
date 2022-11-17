// https://leetcode.com/problems/rectangle-area/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        int area = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);

        int left = max(ax1, bx1);
        int right = min(ax2, bx2);

        int xOverlap = right - left;

        int bottom = max(ay1, by1);
        int top = min(ay2, by2);

        int yOverlap = top - bottom;

        if (xOverlap > 0 && yOverlap > 0)
        {
            area -= xOverlap * yOverlap;
        }

        return area;
    }
};

int main()
{
    Solution obj;

    cout << obj.computeArea(-3, 0, 3, 4, 0, -1, 9, 2);

    return 0;
}