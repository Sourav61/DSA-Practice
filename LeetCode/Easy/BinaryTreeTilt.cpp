// https://leetcode.com/problems/binary-tree-tilt/

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
    int helper(TreeNode* root, int &tilt){
        if(root == NULL)
            return 0;
        
        int left = helper(root->left, tilt);
        int right = helper(root->right,tilt);
        
        tilt += abs(right - left);
        
        return root->val + left + right;
    }

    int findTilt(TreeNode* root) {
        int tilt = 0;
        helper(root, tilt);
        return tilt;
    }
};

int main(){

    Solution obj;

    TreeNode* root = new TreeNode(4);
    
    root->left = new TreeNode(2);
    root->right = new TreeNode(9);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);

    // root->right->left = new TreeNode();
    root->right->right = new TreeNode(7);

    cout<<obj.findTilt(root)<<endl;

    return 0;
}