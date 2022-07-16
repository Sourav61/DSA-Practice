// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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
    vector<vector<int>> res;
    void dfs(TreeNode* root, int level){
        if(root == NULL)
            return;

        if(level == res.size())
            res.push_back(vector<int> ());
        
        res[level].push_back(root->val);
        dfs(root->left, level+1);
        dfs(root->right, level+1);
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};

int main(){

    Solution obj;

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> ans = obj.levelOrderBottom(root);

    for(vector<int> v : ans){
        for(auto x : v)
            cout<<x<<" ";
        cout<<endl;
    }

    return 0;
}