// https://leetcode.com/problems/check-completeness-of-a-binary-tree/

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
    bool isCompleteTree(TreeNode* root) {
        if(!root)
            return NULL;

        queue<TreeNode*> q;
        q.push(root);

        bool flag = false;

        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left){
                    if(flag)
                        return false;
                    
                    q.push(curr->left);
                }else
                    flag = true;

                if(curr->right){
                    if(flag)
                        return false;
                    
                    q.push(curr->right);
                }else
                    flag = true;
            }
        }

        return true;
    }
};

int main(){
    
    Solution obj;

    TreeNode* root = new TreeNode(1);
    
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);

    cout<<obj.isCompleteTree(root);
    
    return 0;
}