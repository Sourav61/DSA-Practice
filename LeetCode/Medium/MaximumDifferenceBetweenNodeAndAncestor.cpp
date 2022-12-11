// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/

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
    int maxAncestorDiff(TreeNode *root, int maxi = 0, int mini = INT_MAX)
    {
        if (!root)
            return maxi - mini;

        maxi = max(maxi, root->val);
        mini = min(mini, root->val);

        return max(maxAncestorDiff(root->left, maxi, mini), maxAncestorDiff(root->right, maxi, mini));
    }
};

int main()
{
    Solution obj;

    TreeNode *root = new TreeNode(1);

    root->right = new TreeNode(2);

    root->right->right = new TreeNode(0);

    root->right->right->left = new TreeNode(3);

    cout << obj.maxAncestorDiff(root);

    return 0;
}