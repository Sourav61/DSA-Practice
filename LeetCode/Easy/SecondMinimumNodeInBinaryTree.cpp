// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/

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
    void inorder(TreeNode* root, vector<int> &ans){
        if(root == NULL)
            return;

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }

    int findSecondMinimumValue(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        sort(ans.begin(),ans.end());
        for(auto x: ans){
            if(x != root->val)
                return x;
        };
        
        return -1;
    }
};

int main(){

    Solution obj;

    TreeNode* root = new TreeNode(2);

    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    cout<<obj.findSecondMinimumValue(root)<<endl;

    return 0;
}