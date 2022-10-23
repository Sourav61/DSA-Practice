// https://leetcode.com/problems/house-robber-iii/

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
    int tryRob(TreeNode *root, int &l, int &r)
    {
        if (root == NULL)
            return 0;

        int LL = 0, LR = 0, RL = 0, RR = 0;
        l = tryRob(root->left, LL, LR);
        r = tryRob(root->right, RL, RR);

        int rob = root->val + LL + LR + RL + RR;
        int notRob = L + R;

        return max(rob, notRob);
    }

    int rob(TreeNode *root)
    {
        int l = 0, r = 0;
        return tryRob(root, l, r);
    }
};

int main()
{

    Solution obj;

    TreeNode *root = new TreeNode(3);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->right = new TreeNode(3);

    root->right->right = new TreeNode(1);

    cout << obj.rob(root);

    return 0;
}