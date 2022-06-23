// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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
    // vector<vector<int>> verticalTraversal(TreeNode* root) {
    //     map<int, map<int, multiset<int>>> nodes;
    //     queue<pair<TreeNode*, pair<int, int>>> todo;

    //     todo.push({root, {0,0}});

    //     while(!todo.empty()){
    //         auto p = todo.front();
    //         todo.pop();

    //         TreeNode* node = p.first;
    //         int x = p.second.first;
    //         int y = p.second.second;

    //         nodes[x][y].insert(node->val);

    //         if(node->left)
    //             todo.push({node->left, {x-1, y+1}});

    //         if(node->right)
    //             todo.push({node->right, {x+1, y+1}});
    //     }

    //     vector<vector<int>> ans;

    //     for(auto p : nodes){
    //         vector<int> col;
    //         for(auto q : p.second)
    //             col.insert(col.end(), q.second.begin(), q.second.end());

    //         ans.push_back(col);
    //     }
        
    //     return ans; 
    // }

    vector<vector<int>> verticalTraversal(TreeNode* root){
        map<int, map<int, multiset<int>>> nodes;
        traverse(root, 0,0, nodes);

        vector<vector<int>> res;

        for(auto p : nodes){
            vector<int> col;
            for(auto q : p.second)
                col.insert(col.end(), q.second.begin(), q.second.end());

            res.push_back(col);
        }
        return res;
    }

    void traverse(TreeNode* root, int x ,int y, map<int, map<int, multiset<int>>> &nodes){
        if(root){
            nodes[x][y].insert(root->val);
            traverse(root->left, x-1, y+1, nodes);
            traverse(root->right, x+1, y+1, nodes);
        }
    }
};

int main(){

    Solution obj;

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> res = obj.verticalTraversal(root);

    for(vector<int> v : res){
        for(auto x : v){
            cout<<x<<" ";
        }cout<<endl;
    }

    return 0;
}