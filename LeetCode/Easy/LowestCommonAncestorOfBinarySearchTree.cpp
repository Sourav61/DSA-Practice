// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;

        int curr = root->val;

        if(curr < p->val && curr < q->val)
            return lowestCommonAncestor(root->right, p, q);
        if(curr > p->val && curr > q->val)
            return lowestCommonAncestor(root->left, p, q);

        return root;
    }
};

int main(){

    Solution obj;

    TreeNode* root = new TreeNode(6);

    root->left = new TreeNode(2);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    TreeNode* p = new TreeNode(2);
    TreeNode* q = new TreeNode(8);

    TreeNode* ans = obj.lowestCommonAncestor(root, p, q);

    cout<<ans->val<<endl;

    return 0;
}