// https://leetcode.com/problems/reward-top-k-students/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    class Compare
    {
    public:
        bool operator()(pair<int, int> &a, pair<int, int> &b)
        {
            if (a.first == b.first)
            {
                return a.second > b.second;
            }
            return a.first < b.first;
        }
    };

    vector<int> topStudents(vector<string> &positive_feedback, vector<string> &negative_feedback, vector<string> &report, vector<int> &student_id, int k)
    {
        unordered_map<string, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        vector<int> rank;
        vector<int> res;
        for (auto &x : positive_feedback)
        {
            mp[x] = 3;
        }
        for (auto &x : negative_feedback)
        {
            mp[x] = -1;
        }

        int n = report.size();

        for (int i = 0; i < n; i++)
        {
            string str = "";
            int rate = 0;
            for (int j = 0; j < report[i].size(); j++)
            {
                if ((int)report[i][j] == 32 || j == report[i].size() - 1)
                {
                    if (j == report[i].size() - 1)
                    {
                        str += report[i][j];
                    }
                    if (mp[str] != 0)
                    {
                        rate += mp[str];
                    }
                    str = "";
                    continue;
                }
                str += report[i][j];
            }
            pq.push({rate, student_id[i]});
        }

        while (k--)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};

int main()
{

    Solution obj;

    vector<string> positive_feedback = {"smart", "brilliant", "studious"};
    vector<string> negative_feedback = {"not"};
    vector<string> report = {"this student is studious", "the student is smart"};
    vector<int> student_id = {1, 2};

    vector<int> res = obj.topStudents(positive_feedback, negative_feedback, report, student_id, 2);

    for (auto &x : res)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}