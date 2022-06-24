// https://leetcode.com/problems/binary-tree-right-side-view/

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return res;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            for(int i=0;i<size;i++){
                Node* curr = q.front();
                q.pop();

                if(i == size-1){
                    res.push_back(curr->data);
                }

                if(curr->left)
                    q.push(curr->left);
                
                if(curr->right)
                    q.push(curr->right);
            }
        }

        return res;
    }
};

int main(){

    Solution obj;

    TreeNode* root = new TreeNode(1);

    root->right = new TreeNode(3);

    obj.rightSideView(root);

    return 0;
}