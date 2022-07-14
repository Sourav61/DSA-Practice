// https://leetcode.com/problems/insert-into-a-binary-search-tree/

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL)
            return new TreeNode(val);

        if(val < root->val){
            root->left = insertIntoBST(root->left, val);
        }else{
            root->right = insertIntoBST(root->right, val);
        }

        return root;
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