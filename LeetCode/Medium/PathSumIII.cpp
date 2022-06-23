// https://leetcode.com/problems/path-sum-iii/

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
    long long ans = 0;

    void solve(TreeNode* root, long long target){
        if(!root)
            return;
        
        if(root->val == target)
            ans++;

        solve(root->left, target - root->val);
        solve(root->right, target - root->val);
    }

    int pathSum(TreeNode* root, long long targetSum) {
        if(root)
            solve(root, targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        return ans;
    }
};

int main(){

    Solution obj;

    TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);

    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);

    root->left->right->right = new TreeNode(1);

    root->right->right = new TreeNode(11);

    cout<<obj.pathSum(root, 8)<<endl;

    return 0;
}