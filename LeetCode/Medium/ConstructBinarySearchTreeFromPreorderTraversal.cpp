// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

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
    TreeNode* constructBST(vector<int> preorder, int* preorderIdx, int key, int min, int max, int n){
        if(*preorderIdx >= n)
            return NULL;

        TreeNode* root = NULL;

        if(key < max && key > min){
            root = new TreeNode(key);
            *preorderIdx = *preorderIdx + 1;

            if(*preorderIdx < n)
                root->left = constructBST(preorder, preorderIdx, preorder[*preorderIdx], min, key, n);
            
            if(*preorderIdx < n)
                root->right = constructBST(preorder, preorderIdx, preorder[*preorderIdx], key, max, n);
        }

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        int preorderIdx = 0;
        return constructBST(preorder, &preorderIdx, preorder[0], INT_MIN, INT_MAX, n);
    }
};

void printPreorder(TreeNode* root){
    if(root == NULL)
        return;
    
    cout<<root->val<<"->";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main(){
    vector<int> preorder = {8,5,1,7,10,12};

    Solution obj;

    TreeNode* root = obj.bstFromPreorder(preorder);

    printPreorder(root);
    cout<<"NULL"<<endl;
    return 0;
}