// https://leetcode.com/problems/zigzag-conversion/description/

#include <bitsstdc++.h>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }

        string res = "";
        int increment = 0;

        for (int r = 0; r < numRows; r++)
        {
            increment = 2 * (numRows - 1);
            for (int i = r; i < s.size(); i += increment)
            {
                res += s[i];
                if (r > 0 && r < numRows - 1 &&
                    i + increment - 2 * r < s.size())
                {
                    res += s[i + increment - 2 * r];
                }
            }
        }

        return res;
    }
};

int main()
{

    Solution obj;

    string s = "PAYPALISHIRING";

    cout << obj.convert(s, 3);

    return 0;
}