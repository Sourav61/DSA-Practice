// https://leetcode.com/problems/binary-tree-paths/

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
    void binaryPath(TreeNode* root, vector<string>& res, string ans){
        if(!root->left && !root->right){
            res.push_back(ans);
            return;
        }
        
        if(root->left)
            binaryPath(root->left, res, ans + "->" + to_string(root->left->val));
        if(root->right)
            binaryPath(root->right, res, ans + "->" + to_string(root->right->val));
    };
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root)
            return res;
        
        binaryPath(root,res,to_string(root->val));
        return res;
    };
};

int main(){

    Solution obj;

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->right = new TreeNode(5);

    vector<string> res = obj.binaryTreePaths(root);

    for(auto x : res)
        cout<<x<<" ";
    cout<<endl;

    return 0;
}