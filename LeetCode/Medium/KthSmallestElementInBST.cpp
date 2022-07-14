// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    int solve(TreeNode* root, int &k){
        if(!root)
            return 0;
            
        int left = solve(root->left, k);
        if(left)
            return left;

        k--;
        if(k == 0)
            return root->val;

        int right = solve(root->right, k);
        return right;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        return solve(root, k);
    }
};

int main(){

    Solution obj;

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(1);
    root->right = new TreeNode(4);

    // root->left->left = new TreeNode();
    root->left->right = new TreeNode(2);

    // root->right->left = new TreeNode();
    // root->right->right = new TreeNode();

    cout<<obj.kthSmallest(root, 1)<<endl;

    return 0;
}