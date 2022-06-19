// https://leetcode.com/problems/path-sum-ii/

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
    void solve(TreeNode* root, vector<int> path, int targetSum, int currSum){
        if(!root){
            return;
        }
        currSum+=root->val;

        path.push_back(root->val);
        if(currSum == targetSum and !root->left and !root->right){
            res.push_back(path);
        }
        solve(root->left,path,targetSum,currSum);
        solve(root->right,path,targetSum,currSum);

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;

        solve(root,path,targetSum, 0);

        return res;
    }
};

int main(){
    Solution obj;

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);

    root->right = new TreeNode(3);

    vector<vector<int>> ans = obj.pathSum(root, 5);

    for(vector<int> v : ans){
        for(auto x : v){
            cout<<x<<" ";
        }cout<<endl;
    }

    return 0;
}