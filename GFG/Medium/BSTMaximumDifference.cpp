// https://practice.geeksforgeeks.org/problems/e841e10213ddf839d51c2909f1808632a19ae0bf/1

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node *right;
    Node *left;

    Node(int x)
    {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val)
{
    Node *temp = NULL;
    if (tree == NULL)
        return new Node(val);

    if (val < tree->data)
    {
        tree->left = insert(tree->left, val);
    }
    else if (val > tree->data)
    {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool found = false;
    Node *fNode = NULL;
    int Usum = 0, Dsum = 1e9;

    void dfs(Node *root, int target)
    {
        if (!root)
        {
            return;
        }

        if (found == true || root->data == target)
        {
            if (!found)
                fNode = root;
            found = true;
            return;
        }

        Usum += root->data;

        if (root->data < target)
        {
            dfs(root->right, target);
        }
        else
        {
            dfs(root->left, target);
        }
    }

    void helper(Node *root, int sum)
    {
        if (!root)
        {
            return;
        }
        sum += root->data;

        if (root->left == NULL && root->right == NULL)
        {
            if (sum < Dsum)
            {
                Dsum = sum;
            }
            return;
        }

        helper(root->left, sum);
        helper(root->right, sum);
    }

    int maxDifferenceBST(Node *root, int target)
    {
        dfs(root, target);

        if (!found)
        {
            return -1;
        }

        helper(fNode, 0);

        Dsum -= fNode->data;
        return Usum - Dsum;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends