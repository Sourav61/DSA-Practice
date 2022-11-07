// https://leetcode.com/problems/maximum-69-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximum69Number(int num)
    {
        string str = to_string(num);

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '6')
            {
                str[i] = '9';
                break;
            }
        }

        // cout<<stoi(str)<<endl;

        return stoi(str);
    }
};

int main()
{

    Solution obj;

    cout << obj.maximum69Number(9669);

    return 0;
}