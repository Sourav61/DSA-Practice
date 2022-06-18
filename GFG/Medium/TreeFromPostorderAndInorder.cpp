// { Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

    //Function to return a tree created from postorder and inoreder traversals.
    int search(int in[],int start,int end,int curr){
        for(int i=start;i<=end;i++){
            if(in[i] == curr){
                return i;
            }
        }

        return -1;
    }
    
    Node* Tree(int in[],int post[],int start,int end,int &postIdx){
        if(postIdx < 0){
            return NULL;
        }
        if(start > end){
            return NULL;
        }
    
        int curr = post[postIdx];
        postIdx--;
        Node* node = new Node(curr);
    
        int pos = search(in,start,end,curr);
    
        node->right = Tree(in,post,pos+1,end,postIdx);
        node->left = Tree(in,post,start,pos-1,postIdx);
    
        return node;
    }
    
    Node *buildTree(int in[], int post[], int n) {
        int postIdx = n-1;
        Node *ans = Tree(in,post,0,n-1, postIdx);
        return ans;
    }
