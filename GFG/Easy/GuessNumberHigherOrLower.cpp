// https://leetcode.com/problems/guess-number-higher-or-lower/

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int guessNumber(int n)
    {
        long int low = 1;
        long int high = n;

        while (low <= high)
        {
            long int mid = (low + high) / 2;
            if (guess(mid) == 0)
            {
                return mid;
            }
            else if (guess(mid) == 1)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return -1;
    }
};

int main()
{

    Solution obj;

    cout << obj.guessNumber(10) << endl;

    return 0;
}