// https://leetcode.com/problems/recover-binary-search-tree/

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
private:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;

private:
    void inorder(TreeNode* root){
        if(root == NULL)
            return;

        inorder(root->left);

        if(prev != NULL && (root->val < prev->val)){
            if(first == NULL){
                first = prev;
                middle = root;
            }
            else
                last = root;
        }

        prev = root;
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        first = prev = middle = last = NULL;

        prev = new TreeNode(INT_MIN);
        inorder(root);

        if(first && last)
            swap(first->val, last->val);
        else if(first && middle)
            swap(first->val, middle->val);
    }
};

void inorderPrint(TreeNode* root){
    if(root == NULL)
        return;

    inorderPrint(root->left);
    cout<<root->val;
    inorderPrint(root->right);
}

int main(){

    Solution obj;

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(3);

    root->left->right = new TreeNode(2);

    cout<<obj.recoverTree(root);

    inorderPrint(root);

    return 0;
}