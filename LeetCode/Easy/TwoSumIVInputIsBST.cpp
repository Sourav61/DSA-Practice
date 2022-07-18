// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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

class BSTIterator {
    stack<TreeNode*> myStack;

    bool reverse = true;
public:
    BSTIterator(TreeNode* root, bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }

    bool hasNext() {
        return !myStack.empty();
    }

    int next(){
        TreeNode* tmpNode = myStack.top();
        myStack.pop();
        if(!reverse)
            pushAll(tmpNode->right);
        else
            pushAll(tmpNode->left);
        
        return tmpNode->val;
    }

private: 
    void pushAll(TreeNode* node){
        for(;node != NULL;){
            myStack.push(node);
            if(reverse == true)
                node = node->right;
            else
                node = node->left;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return false;

        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();

        while(i < j){
            if(i + j == k)
                return true;
            else if(i + j < k)
                i = l.next();
            else
                j = r.next();
        }

        return false;
    }
};

int main(){

    Solution obj;

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    // root->right->left = new TreeNode();
    root->right->right = new TreeNode(7);

    cout<<obj.findTarget(root, 9);

    return 0;
}