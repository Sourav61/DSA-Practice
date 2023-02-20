// https://leetcode.com/problems/invert-binary-tree/description/

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
    void swap(TreeNode *node)
    {
        if (!node)
        {
            return;
        }

        swap(node->left);
        swap(node->right);

        TreeNode *temp;
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }

    TreeNode *invertTree(TreeNode *root)
    {
        swap(root);
        return root;
    }
};

int main()
{

    Solution obj;

    TreeNode *root = new TreeNode(2);

    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    TreeNode *res = obj.invertTree(root);

    return 0;
}