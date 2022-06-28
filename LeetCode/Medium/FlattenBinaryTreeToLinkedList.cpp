// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while(curr != NULL){
            if(curr->left != NULL){
                TreeNode* prev = curr->left;
                while(prev->right)
                    prev = prev->right;

                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};

int main(){

    Solution obj;

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(6);

    obj.flatten(root);

    inorderPrint(root);

    cout<<"NULL"<<endl;

    return 0;
}