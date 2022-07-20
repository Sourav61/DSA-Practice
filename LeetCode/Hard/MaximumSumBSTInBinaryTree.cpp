// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/

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

class NodeValue{
public:
    int maxNode,minNode,maxSum;

    NodeValue(int minNode,int maxNode, int maxSum){
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSum = maxSum;
    }
};

class Solution {
private:
    NodeValue maxSumBSTHelper(TreeNode* root){
        if(!root)
            return NodeValue(INT_MAX, INT_MIN, 0);

        auto left = maxSumBSTHelper(root->left);
        auto right = maxSumBSTHelper(root->right);

        if(left.maxNode < root->val && root->val < right.minNode){
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), (root->val + left.maxSum + right.maxSum));
        }

        return NodeValue(INT_MIN, INT_MAX, max(left.maxSum, right.maxSum));
    }

public:
    int maxSumBST(TreeNode* root) {
        return maxSumBSTHelper(root).maxSum;
    }
};

int main(){

    Solution obj;

    TreeNode* root = new TreeNode(4);

    root->left = new TreeNode(3);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    cout<<obj.maxSumBST(root)<<endl;

    return 0;
}