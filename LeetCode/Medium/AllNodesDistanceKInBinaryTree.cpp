// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track, int target){
        if(!root)
            return;
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(curr->left){
                parent_track[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent_track[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markParents(root, parent_track, k);

        unordered_map<TreeNode*, bool> vis;

        queue<TreeNode*> q;
        q.push(target);

        vis[target] = true;

        int cur_level = 0;

        while(!q.empty()){
            int size = q.size();
            if(cur_level++ == k)
                break;

            for(int i=0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left] = true;
                }

                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right] = true;
                }

                if(parent_track[curr] && !vis[parent_track[curr]]){
                    q.push(parent_track[curr]);
                    vis[parent_track[curr]] = true;
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            res.push_back(curr->val);
        }
        
        sort(res.begin(),res.end());

        return res;
    }
};

int main(){

    Solution obj;

    TreeNode* root = new TreeNode(20);
    
    root->left = new TreeNode(7);
    root->right = new TreeNode(24);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(3);

    root->left->right->left = new TreeNode(1);

    return 0;
}