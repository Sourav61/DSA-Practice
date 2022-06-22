// https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
    int sumNumbers(TreeNode* root) {
        string sum = to_string(root->val);
        int ans = 0;
        sumNum(root, sum, ans);
        return ans;
    }

    int sumNum(TreeNode* root, string sum, int &ans){
        if(root->left == NULL && root->right == NULL){
            ans+=stoi(sum);
            return 0;
        }
        
        if(root->left != NULL)
            int left = sumNum(root->left, sum+to_string(root->left->val),ans);
        if(root->right != NULL)
            int right = sumNum(root->right, sum+to_string(root->right->val),ans);

        return stoi(sum);
    }
};

int main(){

    Solution obj;

    TreeNode* root = new TreeNode(4);

    root->left = new TreeNode(9);
    root->right = new TreeNode(0);

    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);

    int ans = obj.sumNumbers(root);

    cout<<ans<<endl;

    return 0;
}