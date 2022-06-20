// https://leetcode.com/problems/diameter-of-binary-tree/

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
    int calcDiameter(TreeNode* root, int& diameter){
        if(root == NULL){
            return 0;
        }

        int lh = calcDiameter(root->left, diameter);
        int rh = calcDiameter(root->right, diameter);

        diameter = max(diameter, lh+rh);

        return 1 + max(lh,rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        calcDiameter(root,diameter);
        return diameter;
    }
};

int main(){

    Solution obj;

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int ans = obj.diameterOfBinaryTree(root);

    return 0;
}