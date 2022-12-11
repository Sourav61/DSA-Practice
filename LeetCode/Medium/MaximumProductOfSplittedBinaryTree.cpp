// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/

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
    long long int mod = 1e9 + 7;
    long long total = 0, ans = 0;

    int totSum(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        long long sum = totSum(root->left) + totSum(root->right) + root->val;

        ans = max(ans, (total - sum) * sum);

        return sum;
    }

    int maxProduct(TreeNode *root)
    {
        total = totSum(root);

        totSum(root);

        return ans % mod;
    }
};

int main()
{
    Solution obj;

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);

    cout << obj.maxProduct(root);

    return 0;
}