// https://leetcode.com/problems/range-sum-of-bst/description/

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
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        queue<TreeNode *> q;
        int sum = 0;
        q.push(root);

        while (q.size())
        {
            auto curr = q.front();
            q.pop();

            if (curr && curr->val < low)
            {
                q.push(curr->right);
                continue;
            }
            else if (curr && curr->val > high)
            {
                q.push(curr->left);
                continue;
            }
            else
            {
                if (curr)
                {
                    sum += curr->val;
                }

                if (curr && curr->left)
                    q.push(curr->left);

                if (curr && curr->right)
                    q.push(curr->right);
            }
        }

        return sum;
    }

    // int helper(TreeNode* root,int &low, int &high){
    //     if(!root){
    //         return NULL;
    //     }
    //     if(root->val < low){
    //         return helper(root->right, low, high);
    //     }else if(root->val > high){
    //         return helper(root->left, low ,high);
    //     }

    //     return root->val + helper(root->left, low,high) + helper(root->right, low, high);
    // }

    // int rangeSumBST(TreeNode* root, int low, int high) {
    //     return helper(root,low,high);
    // }
};

int main()
{

    Solution obj;

    TreeNode *root = new TreeNode(10);

    root->left = new TreeNode(5);
    root->right = new TreeNode(15);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);

    root->right->right = new TreeNode(18);

    cout << obj.rangeSumBST(root, 7, 15);

    return 0;
}