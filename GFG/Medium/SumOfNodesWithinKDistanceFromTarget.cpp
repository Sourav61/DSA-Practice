// https://practice.geeksforgeeks.org/problems/ebb840c27b36a8c8ad121fd576a2fa6f2bc1e6f2/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

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
    Node *root = newNode(stoi(ip[0]));

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

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

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
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/

class Solution
{
public:
    Node *findPar(Node *root, unordered_map<Node *, Node *> &parent, int &target)
    {
        queue<Node *> q;
        q.push(root);
        Node *temp = root;

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            if (curr->data == target)
            {
                temp = curr;
            }

            if (curr->left)
            {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right)
            {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }

        return temp;
    }

    int sum_at_distK(Node *root, int target, int k)
    {
        if (!root)
        {
            return 0;
        }

        unordered_map<Node *, Node *> mp;
        unordered_map<Node *, bool> vis;
        Node *tar = findPar(root, mp, target);

        queue<Node *> q;
        q.push(tar);

        vis[tar] = true;
        int dis = 0, sum = 0;
        while (!q.empty())
        {
            int sz = q.size();

            if (dis == k + 1)
            {
                break;
            }

            while (sz--)
            {
                auto curr = q.front();
                q.pop();

                sum += curr->data;

                if (mp[curr] && !vis[mp[curr]])
                {
                    vis[mp[curr]] = true;
                    q.push(mp[curr]);
                }

                if (curr->left && !vis[curr->left])
                {
                    vis[curr->left] = true;
                    q.push(curr->left);
                }

                if (curr->right && !vis[curr->right])
                {
                    vis[curr->right] = true;
                    q.push(curr->right);
                }
            }
            dis++;
        }

        return sum;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    getchar();

    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);

        int target, k;
        cin >> target >> k;
        getchar();

        Solution ob;
        cout << ob.sum_at_distK(root, target, k) << endl;
    }
    return 0;
}

// } Driver Code Ends