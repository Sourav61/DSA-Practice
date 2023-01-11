// https://leetcode.com/problems/clone-graph/description/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    unordered_map<Node *, Node *> mp;

    Node *cloneGraph(Node *node)
    {
        if (!node)
            return NULL;

        Node *first = new Node(node->val, {});
        mp[node] = first;

        queue<Node *> q;
        q.push(node);

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();

            for (auto adj : curr->neighbors)
            {
                if (mp.find(adj) == mp.end())
                {
                    mp[adj] = new Node(adj->val, {});
                    q.push(adj);
                }

                mp[curr]->neighbors.push_back(mp[adj]);
            }
        }

        return mp[node];
    }
};

int main()
{

    Solution obj;

    Node *node = new Node(1, {});

    Node *res = obj.cloneGraph(node);

    cout << res->val << endl;

    return 0;
}