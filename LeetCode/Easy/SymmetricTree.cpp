// https://leetcode.com/problems/symmetric-tree/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root == NULL || isSymmetry(root->left, root->right);
    }

    bool isSymmetry(TreeNode* left, TreeNode* right){
        if(left == NULL || right == NULL){
            return left == right;
        }

        if(left->val != right->val)
            return false;

        return isSymmetry(left->left, right->right)
            && isSymmetry(left->right, right->left);
    }
};

int main(){

    Solution obj;

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    cout<<obj.isSymmetric(root);

    return 0;
}