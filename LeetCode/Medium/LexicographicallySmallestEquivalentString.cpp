// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/description/

#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
    vector<int> rank;
    vector<int> parent;

    DSU(int n)
    {
        rank.resize(n);
        parent.resize(n);

        for (int i = 0; i < n; i++)
        {
            rank[i] = i;
            parent[i] = i;
        }
    }

    int findParent(int x)
    {
        if (x == parent[x])
        {
            return x;
        }

        return parent[x] = findParent(parent[x]);
    }

    void makeUnion(int x, int y)
    {
        int first = findParent(x);
        int sec = findParent(y);

        if (first != sec)
        {
            if (rank[first] < rank[sec])
            {
                parent[sec] = first;
            }
            else if (rank[sec] < rank[first])
            {
                parent[first] = sec;
            }
        }
    }
};

class Solution
{
public:
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        DSU dsu(26);

        for (int i = 0; i < s1.size(); i++)
        {
            dsu.makeUnion(s1[i] - 'a', s2[i] - 'a');
        }

        string res;

        for (auto &x : baseStr)
        {
            char ch = dsu.findParent(x - 'a') + 'a';
            res += ch;
        }

        return res;
    }
};

int main()
{

    Solution obj;

    cout << obj.smallestEquivalentString("parker", "morris", "parser");

    return 0;
}