// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == NULL){
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        bool lR = true;

        while(!q.empty()){
            int size = q.size();
            vector<int> temp(size);

            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();

                int index = lR ? i : (size - 1 - i);

                temp[index] = node->val;

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }

            lR = !lR;

            ans.push_back(temp);
        }

        return ans;
    }
};

int main(){

    Solution obj;

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> res = obj.zigzagLevelOrder(root);

    for(vector<int> v : res){
        for(auto x : v)
            cout<<x<<" ";
        cout<<endl;
    }

    return 0;
}