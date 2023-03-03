// https://leetcode.com/problems/find-duplicate-subtrees/description/

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

#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Os")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

class Solution
{
public:
    string inorder(TreeNode *root, unordered_map<string, int> &mp, vector<TreeNode *> &ans)
    {
        if (root == NULL)
        {
            return "";
        }
        string left = 'A' + inorder(root->left, mp, ans);
        string right = 'B' + inorder(root->right, mp, ans);

        string temp = left + to_string(root->val) + right;

        if (mp[temp] == 1)
        {
            ans.push_back(root);
        }

        mp[temp]++;

        return temp;
    }

    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        unordered_map<string, int> mp;
        vector<TreeNode *> ans;
        inorder(root, mp, ans);
        return ans;
    }
};

int main()
{

    Solution obj;

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);

    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);

    root->right->left->left = new TreeNode(4);

    vector<TreeNode *> res = obj.findDuplicateSubtrees(root);

    return 0;
}