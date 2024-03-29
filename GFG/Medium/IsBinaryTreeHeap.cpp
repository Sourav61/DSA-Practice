// https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/0

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str)
{
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
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

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
        if (currVal != "N")
        {

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
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution
{
public:
    // bool flag = true;
    // int dfs(struct Node* node){
    //     if(node == NULL || flag == false){
    //         return 0;
    //     }

    //     int left = dfs(node->left);
    //     int right = dfs(node->right);
    //     cout<<node->data<<" "<<left<<" "<<right<<endl;
    //     if(node->data < left || node->data < right){

    //         flag = false;
    //         return 0;
    //     }

    //     return node->data;
    // }

    bool isHeap(struct Node *tree)
    {
        queue<Node *> q;

        if (tree == NULL)
        {
            return true;
        }

        q.push(tree);

        bool seen = false;

        while (!q.empty())
        {
            auto node = q.front();
            q.pop();

            if (node->left != NULL)
            {
                if (seen || node->left->data > node->data)
                    return false;

                q.push(node->left);
            }
            else
            {
                seen = true;
            }

            if (node->right != NULL)
            {
                if (seen || node->right->data > node->data)
                    return false;

                q.push(node->right);
            }
            else
            {
                seen = true;
            }
        }

        return true;
    }
};

//{ Driver Code Starts.

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc--)
    {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
// } Driver Code Ends