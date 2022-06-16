// https://leetcode.com/problems/binary-tree-preorder-traversal/

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

    void helper(vector<int> &ans, TreeNode* root){
        if(root != NULL){
            ans.push_back(root->val);
            helper(ans, root->left);
            helper(ans, root->right);
        }
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(ans, root);
        return ans;
    }
};

int main(){

    Solution obj;

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    vector<int> res = obj.preorderTraversal(root);

    for(auto x : res){
        cout<<x<<" ";
    }cout<<endl;

    return 0;
}