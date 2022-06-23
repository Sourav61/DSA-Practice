// https://leetcode.com/problems/leaf-similar-trees/

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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string a, b;
        DFS(root1, a);
        DFS(root2, b);
        return a==b;
    }
    
    void DFS(TreeNode* root, string& s) {
        if(root==NULL) 
            return;
        if(root->left==NULL && root->right==NULL) 
            s+=to_string(root->val)+" ";
        DFS(root->left, s);
        DFS(root->right, s);
    }
};

int main(){

    Solution obj;

    TreeNode* root1 = new TreeNode(1);
    
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    TreeNode* root2 = new TreeNode(1);

    root2->left = new TreeNode(3);
    root2->right = new TreeNode(2);

    cout<<obj.leafSimilar(root1, root2)<<endl;

    return 0;
}