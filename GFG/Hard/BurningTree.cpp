// https://practice.geeksforgeeks.org/problems/burning-tree/1/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    // =============================      Approach-1 (BFS Level-Order)              ============================
    
    Node* makeParent(Node* root, map<Node*, Node*>&parent_map, int target){
        queue<Node*> q;
        q.push(root);
        Node* res=NULL;
        parent_map[root] = NULL;

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            if(curr->data == target){
                res = curr;
            } 

            if(curr->left){
                parent_map[curr->left] = curr;
                q.push(curr->left);
            }

            if(curr->right){
                parent_map[curr->right] = curr;
                q.push(curr->right);
            }
        }

        return res;
    }

    int findMaxDistance(map<Node*, Node*> &parent_map, Node* target){
        queue<Node*> q;
        q.push(target);

        map<Node*, int> vis;
        vis[target] = true;
        int maxi = 0;
        while(!q.empty()){
            int size = q.size();
            bool fl = 0;

            for(int i=0;i<size;i++){
                Node* node = q.front();
                q.pop();

                if(node->left && !vis[node->left]){
                    fl = 1;
                    q.push(node->left);
                    vis[node->left] = true;
                }
                if(node->right && !vis[node->right]){
                    fl = 1;
                    q.push(node->right);
                    vis[node->right] = true;
                }

                if(parent_map[node] && !vis[parent_map[node]]){
                    fl = 1;
                    q.push(parent_map[node]);
                    vis[parent_map[node]] = true;
                }
            }

            if(fl == 1)
                maxi++;
        }

        return maxi;
    }

    int minTime(Node* root, int target) 
    {
        map<Node*, Node*> parent_map;
        Node* t = makeParent(root, parent_map, target);

        int maxi = findMaxDistance(parent_map, t);

        return maxi;
    }

    // =============================      Approach-2 (DFS)              ============================

    // int ans=0;
    
    // int helper(int h,Node* root,int target){
    //     if(!root)
    //         return 0;
    //     if(root->data==target)
    //     {
    //         helper(1,root->left,target);
    //         helper(1,root->right,target);
    //         return 1;
    //     }
    //     if(h){
    //         ans=max(ans,h);
    //         helper(h+1,root->left,target);
    //         helper(h+1,root->right,target);
    //         return 0;
    //     }
    //     int l=helper(0,root->left,target);
    //     int r=helper(0,root->right,target);
        
    //     ans=max(ans,max(l,r));
    //     if(l){
    //         helper(l+1,root->right,target);
    //         return l+1;
    //     }
    //     if(r){
    //         helper(r+1,root->left,target);
    //         return r+1;
    //     }
    // }
  
    // int minTime(Node* root, int target) 
    // {
    //     ans=0;
    //     helper(0,root,target);
    //     return ans;
    // }

};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends