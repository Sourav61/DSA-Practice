// https://www.codingninjas.com/codestudio/problems/floor-from-bst_920457

#include<bits/stdc++.h>
using namespace std;    

class BinaryTreeNode {
public:
    T val;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        if (left) {
          delete left;
        }
        if (right) {
          delete right;
        }
    }
};

int floorInBST(TreeNode<int> * root, int X)
{
    int floor = -1;
    while(root){
        if(root->val == X){
            floor = root->val;
            return floor;
        }

        if(X < root->val){
            root = root->left;
        }else{
            floor = root->val;
            root = root->right;
        }
    }

    return floor;
}