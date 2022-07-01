// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp == NULL)
                s.append("#,");
            else
                s.append(to_string(temp->val) + ",");

            if(temp != NULL){
                q.push(temp->left);
                q.push(temp->right);
            }
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0){
            return NULL;
        }

        stringstream s(data);
        string str;

        getline(s,str,',');

        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            getline(s,str,',');

            if(str == "#"){
                node->left = NULL;
            }else
            {
                TreeNode* left = new TreeNode(stoi(str));
                node->left = left;
                q.push(left);
            }
            
            getline(s,str,',');

            if(str == "#"){
                node->right = NULL;
            }else
            {
                TreeNode* right = new TreeNode(stoi(str));
                node->right = right;
                q.push(right);
            }
        }

        return root;
    }
};

void inorderPrint(Node* root){
    if(!root)
        return;

    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
};

void _deleteTree(Node* node)  
{  
    if (node == NULL) return;  
  
    /* first delete both subtrees */
    _deleteTree(node->left);  
    _deleteTree(node->right);  
  
    /* then delete the node */
    //cout << "Deleting node: " << node->data << endl;  
    delete node;  
}  

void deleteTree(Node** node_ref)  
{  
    _deleteTree(*node_ref);  
    *node_ref = NULL;  
}  

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main(){

    Codec ser,deser;

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string s = ser(root);

    deleteTree(&root);

    TreeNode* ans = deser(s);

    return 0;
}