// https://leetcode.com/problems/find-mode-in-binary-search-tree/

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
    // We know All nodes in left Subtree <= rootNode <= All nodes in right subtree and leftNode <= rootNode <= rightNode
    // Therefore if there are duplicates in the tree, they will always be next to each other in the inOrder traversal of the tree.

    // Initialize max_count to keep track of maximum frequency of any element.
    // Initialize curr_count to know how many times each node occurs.
    
    int max_count = INT_MIN;
    int curr_count = 0;
    TreeNode* prev = NULL;
    vector<int> ans;

    void inorder(TreeNode* root, bool getlist){
        if(!root)
            return;

        // Calling inorder function recursively to reach leftmost node and to check each node for it's duplicates in it's surrounding

        inorder(root->left, getlist);

        // If there are any duplicates then only curr_count will increment

        if(prev && prev->val == root->val)
            curr_count++;
        else
            curr_count = 1;

        // If getlist is false i.e. calling inorder function for first time, we will only update max_count of duplicates
        // If getlist is true i.e. calling inorder function for second time, we will push that node to our vector ans!

        if(!getlist)
            max_count = max(max_count, curr_count);
        else if(curr_count == max_count)
            ans.push_back(root->val);

        // Updating prev vector so that we can check each node for it's surrounding duplicates

        prev = root;
        inorder(root->right, getlist);
    }

    vector<int> findMode(TreeNode* root) {
        if(!root)
            return ans;

        // Calling inorder function very first time just to know maximum count of any node i.e. to update max count

        inorder(root, false);

        // Reset curr counter to 0 and prev pointer to NULL so that we could identify nodes with maximum frequency

        prev = NULL;
        curr_count = 0;

        // Calling inorder function second time just to push back modes to our vector ans.

        inorder(root, true);

        return ans;
    }
};

int main(){

    Solution obj;

    TreeNode* root = new TreeNode(1);

    // root->left = new TreeNode();
    root->right = new TreeNode(2);

    // root->left->left = new TreeNode();
    // root->left->right = new TreeNode();

    root->right->left = new TreeNode(2);
    // root->right->right = new TreeNode();

    vector<int> ans = obj.findMode(root);

    for(auto x : ans)
        cout<<x<<" ";
    cout<<endl;

    return 0;
}