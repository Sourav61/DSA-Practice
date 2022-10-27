// https://leetcode.com/problems/determine-if-two-events-have-conflict/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool haveConflict(vector<string> &event1, vector<string> &event2)
    {
        return event1[0] <= event2[1] && event2[0] <= event1[1];
    }
};

int main()
{
    Solution obj;

    vector<string> event1 = {"01:15", "02:00"};
    vector<string> event2 = {"02:00", "03:00"};

    cout << obj.haveConflict(event1, event2);

    return 0;
}