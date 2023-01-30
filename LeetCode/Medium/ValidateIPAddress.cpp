// https://leetcode.com/problems/validate-ip-address/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string validIPAddress(string queryIP)
    {
        regex v4("(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])"), v6("((([0-9a-fA-F]){1,4})\\:){7}([0-9a-fA-F]){1,4}");
        ;

        if (regex_match(queryIP, v4))
        {
            return "IPv4";
        }

        if (regex_match(queryIP, v6))
        {
            return "IPv6";
        }

        return "Neither";
    }
};

int main()
{

    Solution obj;

    cout << obj.validIPAddress("172.16.254.1");

    return 0;
}