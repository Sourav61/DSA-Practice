// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *findPar(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent, int &target)
    {
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *temp = root;

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            if (curr->val == target)
            {
                temp = curr;
            }

            if (curr->left)
            {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right)
            {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }

        return temp;
    }

    int amountOfTime(TreeNode *root, int start)
    {
        unordered_map<TreeNode *, TreeNode *> mp;
        unordered_map<TreeNode *, bool> vis;
        TreeNode *tar = findPar(root, mp, start);

        queue<TreeNode *> q;
        q.push(tar);

        vis[tar] = true;
        int min = 0;
        while (!q.empty())
        {
            int sz = q.size();

            while (sz--)
            {
                auto curr = q.front();
                q.pop();

                if (mp[curr] && !vis[mp[curr]])
                {
                    vis[mp[curr]] = true;
                    q.push(mp[curr]);
                }

                if (curr->left && !vis[curr->left])
                {
                    vis[curr->left] = true;
                    q.push(curr->left);
                }

                if (curr->right && !vis[curr->right])
                {
                    vis[curr->right] = true;
                    q.push(curr->right);
                }
            }
            min++;
        }

        return min - 1;
    }
};

int main()
{

    Solution obj;

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);

    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    root->right->left->left = new TreeNode(7);

    cout << obj.amountOfTime(root, 4);

    return 0;
}