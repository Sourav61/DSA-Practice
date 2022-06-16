// https://practice.geeksforgeeks.org/problems/construct-tree-1/1/

// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int idx = 0;
    int search(int in[],int curr,int start,int end){
        for(int i=start;i<=end;i++){
            if(in[i] == curr){
                return i;
            }
        }

        return -1;
    }

    Node* Tree(int in[],int pre[],int start, int n)
    {
        if(start > n){
            return NULL;
        }

        int curr = pre[idx];
        idx++;
        Node* node = new Node(curr);

        if(start == n){
            return node;
        }

        int pos = search(in,curr,start,n);

        node->left = Tree(in,pre,start,pos-1);
        node->right = Tree(in, pre, pos+1,n);

        return node;
    }

    Node* buildTree(int in[],int pre[], int n)
    {
        Node* ans = Tree(in, pre, 0, n-1);
        return ans;    
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends