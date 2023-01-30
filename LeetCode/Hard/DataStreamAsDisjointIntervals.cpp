// https://leetcode.com/problems/data-stream-as-disjoint-intervals/description/

#include <bits/stdc++.h>
using namespace std;

class SummaryRanges
{
public:
    set<int> nums;
    SummaryRanges()
    {
    }

    void addNum(int value)
    {
        nums.insert(value);
    }

    vector<vector<int>> getIntervals()
    {
        vector<vector<int>> res;

        int start = -1, end = -1;

        for (auto &x : nums)
        {
            if (start == -1)
            {
                start = x;
                end = x;
            }
            else if (x == end + 1)
            {
                end = x;
            }
            else
            {
                res.push_back({start, end});
                start = x;
                end = x;
            }
        }
        if (start != -1)
        {
            res.push_back({start, end});
        }

        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

int main()
{

    SummaryRanges obj;

    obj.addNum(1);
    vector<vector<int>> res1 = obj.getIntervals();
    for (auto &v : res1)
    {
        for (auto &x : v)
            cout << x << " ";
        cout << endl;
    }
    cout << endl;

    obj.addNum(3);

    vector<vector<int>> res2 = obj.getIntervals();
    for (auto &v : res2)
    {
        for (auto &x : v)
            cout << x << " ";
        cout << endl;
    }
    cout << endl;

    obj.addNum(7);
    vector<vector<int>> res3 = obj.getIntervals();
    for (auto &v : res3)
    {
        for (auto &x : v)
            cout << x << " ";
        cout << endl;
    }
    cout << endl;

    obj.addNum(2);
    vector<vector<int>> res4 = obj.getIntervals();
    for (auto &v : res4)
    {
        for (auto &x : v)
            cout << x << " ";
        cout << endl;
    }
    cout << endl;

    obj.addNum(6);
    vector<vector<int>> res5 = obj.getIntervals();
    for (auto &v : res5)
    {
        for (auto &x : v)
            cout << x << " ";
        cout << endl;
    }
    cout << endl;

    return 0;
}