// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPath(root, maxi);
        return maxi;
    }
    
    int maxPath(TreeNode* node, int &maxi){
        if(node == NULL){
            return 0;
        }

        int left = max(0, maxPath(node->left, maxi));
        int right = max(0, maxPath(node->right, maxi));

        maxi = max(maxi, left+right+node->val);

        return max(left, right) + node->val;
    }
};

int main(){

    Solution obj;

    TreeNode* root = new TreeNode(-10);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    int ans = obj.maxPathSum(root);

    cout<<ans<<endl;

    return 0;
}