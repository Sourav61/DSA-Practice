// https://leetcode.com/problems/validate-binary-search-tree/

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
    bool validBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode){
        if(!root)
            return true;
        
        if(minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
            return false;

        return validBST(root->left, minNode, root) && validBST(root->right, root, maxNode);
    }
    
    bool isValidBST(TreeNode* root) {
        return validBST(root, NULL, NULL);
    }
};

int main(){

    TreeNode* root = new TreeNode();

    root->left = new TreeNode();
    root->right = new TreeNode();

    root->left->left = new TreeNode();
    root->left->right = new TreeNode();

    root->right->left = new TreeNode();
    root->right->right = new TreeNode();

    return 0;
}