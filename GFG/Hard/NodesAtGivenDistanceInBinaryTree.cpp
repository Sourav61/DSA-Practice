// https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:

    // void subTreeNodes(Node* root, int k, vector<int>& res){
    //     if(root == NULL || k<0){
    //         return;
    //     }

    //     if(k == 0){
    //         res.push_back(root->data);
    //     }

    //     subTreeNodes(root->left, k-1);
    //     subTreeNodes(root->right, k-1);
    // }

    // int printNodesAtK(Node* root, vector<int>& res, int target, int k){
    //     if(root == NULL)
    //         return -1;

    //     if(root->data == target){
    //         subTreeNodes(root, k,res);
    //         return 0;
    //     }

    //     int dl = printNodesAtK(root->left, res,target, k);
    //     if(dl != -1){
    //         if(dl + 1 == k){
    //             res.push_back(root->data);
    //         }else{
    //             subTreeNodes(root->right, k-dl-2,res);
    //         }

    //         return dl+1;
    //     }

    //     int dr = printNodesAtK(root->right, res,target,k);
    //     if(dr != -1){
    //         if(dr+1 == k){
    //             res.push_back(root->data);
    //         }else{
    //             subTreeNodes(root->left, k-dr-2,res);
    //         }

    //         return 1+dr;
    //     }

    //     return -1;
    // }
    
    // vector <int> KDistanceNodes(Node* root, int target , int k)
    // {
    //     vector<int> res;
    //     printNodesAtK(root, res, target, k);
        

    //     return res;
    // }

    void markParents(Node* root, unordered_map<Node*, Node*> &parent_track, int target){
        if(!root)
            return;
        
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node* curr = q.front();
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

    Node* preorder(Node* root, int target){
        if(!root)
            return NULL;

        if(root->data == target)
            return root;

        Node* left = preorder(root->left, target);
        Node* right = preorder(root->right, target);

        if(left != NULL)
            return left;
        if(right != NULL)
            return right;
    }

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        unordered_map<Node*, Node*> parent_track;
        markParents(root, parent_track, k);

        unordered_map<Node*, bool> vis;

        Node* t = preorder(root, target);

        queue<Node*> q;
        q.push(t);

        vis[t] = true;

        int cur_level = 0;

        while(!q.empty()){
            int size = q.size();
            if(cur_level++ == k)
                break;

            for(int i=0;i<size;i++){
                Node* curr = q.front();
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
            Node* curr = q.front();
            q.pop();
            res.push_back(curr->data);
        }
        
        sort(res.begin(),res.end());

        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends