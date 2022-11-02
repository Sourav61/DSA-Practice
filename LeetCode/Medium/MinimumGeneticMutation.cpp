// https://leetcode.com/problems/minimum-genetic-mutation/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMutation(string start, string end, vector<string> &bank)
    {
        queue<string> q;
        unordered_set<string> vis;

        q.push(start);
        vis.insert(start);

        int cnt = 0;

        while (!q.empty())
        {
            int nodes = q.size();

            for (int j = 0; j < nodes; j++)
            {
                string node = q.front();
                q.pop();

                if (node == end)
                {
                    return cnt;
                }

                for (char ch : "ACGT")
                {
                    for (int i = 0; i < node.size(); i++)
                    {
                        string neighbor = node;
                        neighbor[i] = ch;
                        if (!vis.count(neighbor) && find(bank.begin(), bank.end(), neighbor) != bank.end())
                        {
                            q.push(neighbor);
                            vis.insert(neighbor);
                        }
                    }
                }
            }
            cnt++;
        }

        return -1;
    }
};

int main()
{

    Solution obj;

    string start = "AAAAACCC";
    string end = "AACCCCCC";
    vector<string> bank = {"AAAACCCC", "AAACCCCC", "AACCCCCC"};

    cout << obj.minMutation(start, end, bank);

    return 0;
}