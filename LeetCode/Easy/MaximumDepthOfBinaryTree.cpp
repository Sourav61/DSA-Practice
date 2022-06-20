// https://leetcode.com/problems/maximum-depth-of-binary-tree/

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
    int maxDepth(TreeNode* root) {
        // ===========================           Level-Order Traversal            =================================
        
        // int depth = 0;

        // queue<TreeNode*> q;
        // q.push(root);

        // while(!q.empty()){
        //     int size = q.size();
        //     depth++;
        //     for(int i=0;i<size;i++){
        //         TreeNode* temp = q.front();
        //         q.pop();
        //         if(temp->left != NULL){
        //             q.push(temp->left);
        //         }
        //         if(temp->right != NULL){
        //             q.push(temp->right);
        //         }
        //     }
        // }

        // return depth;

        // ===========================           Recursive Approach            =================================

        if(root == NULL){
            return 0;
        }

        int lHeight = maxDepth(root->left);
        int rHeight = maxDepth(root->right);

        return max(lHeight, rHeight) + 1;
    }
};

int main(){

    Solution obj;

    TreeNode* root = new TreeNode(1);

    root->right = new TreeNode(2);

    cout<<obj.maxDepth(root)<<endl;

    return 0;
}