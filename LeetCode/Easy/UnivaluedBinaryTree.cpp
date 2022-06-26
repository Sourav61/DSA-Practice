// https://leetcode.com/problems/univalued-binary-tree/

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
    bool isUnivalTree(TreeNode* root) {
        if(!root){
            return true;
        }

        if(root->left && root->val != root->left->val)
            return false;

        if(root->right && root->val != root->right->val)
            return false;

        return isUnivalTree(root->left) 
            && isUnivalTree(root->right);
    }
};

int main(){

    Solution obj;

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(1);
    root->right = new TreeNode(1);

    cout<<obj.isUnivalTree(root)<<endl;

    return 0;
}