// https://leetcode.com/problems/binary-search-tree-iterator/

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
private: stack<TreeNode*> myStack;
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    void pushAll(TreeNode* root){
        for(; root != NULL; myStack.push(root), root = root->left);
    }
    
    int next() {
        TreeNode* tmpNode = myStack.top();
        myStack.pop();
        if(tmpNode)
            pushAll(tmpNode->right);
        return tmpNode ? tmpNode->val : -1;
    }
    
    bool hasNext() {
        return !myStack.empty();   
    }
};

int main(){

    TreeNode* root = new TreeNode(7);

    root->left = new TreeNode(3);    
    root->right = new TreeNode(15);

    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator* obj = new BSTIterator(root);
    int param_1 = obj->next();
    bool param_2 = obj->hasNext();
    int param_3 = obj->next();
    int param_4 = obj->next();
    int param_5 = obj->next();
    bool param_6 = obj->hasNext();
    int param_7 = obj->next();
    bool param_8 = obj->hasNext();

    cout<<param_1<<" "<<param_2<<" "<<param_3<<" "<<param_4<<" "<<param_5<<" "<<param_6<<" "<<param_7<<" "<<param_8<<endl;

    return 0;
}

/**
Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */