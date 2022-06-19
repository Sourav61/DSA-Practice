// https://leetcode.com/problems/count-complete-tree-nodes/

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
    int countNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        int hl=0, hr=0;

        TreeNode *l=root, *r=root;

        while(l) {
            hl++;
            l=l->left;
        }

        while(r) {
            hr++;
            r=r->right;
        }

        if(hl==hr) 
            return pow(2,hl)-1;


        return countNodes(root->left) + countNodes(root->right) + 1;
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

    int ans = obj.countNodes(root);

    cout<<ans<<endl;

    return 0;
}