// https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/

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
    void helper(TreeNode *root, int &minDiff, int &prevVal)
    {
        if (root == nullptr)
            return;
        helper(root->left, minDiff, prevVal);
        if (prevVal != -1)
        {
            minDiff = min(minDiff, root->val - prevVal);
        }
        prevVal = root->val;
        helper(root->right, minDiff, prevVal);
    }
    int minDiffInBST(TreeNode *root)
    {
        int minDiff = INT_MAX;
        int prevVal = -1;
        helper(root, minDiff, prevVal);
        return minDiff;
    }
};

int main()
{

    Solution obj;

    TreeNode *root = new TreeNode(4);

    root->left = new TreeNode(2);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    cout << obj.minDiffInBST(root);

    return 0;
}