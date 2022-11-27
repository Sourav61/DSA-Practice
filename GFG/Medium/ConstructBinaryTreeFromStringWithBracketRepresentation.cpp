// https://practice.geeksforgeeks.org/problems/construct-binary-tree-from-string-with-bracket-representation/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// } Driver Code Ends
// User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/

class Solution
{
public:
    Node *dfs(int &idx, string &s)
    {
        if (idx >= s.length() || s[idx] == ')')
        {
            idx++;
            return NULL;
        }

        int num = 0;
        while (idx < s.length() && isdigit(s[idx]))
        {
            num = num * 10 + (s[idx] - '0');
            idx++;
        }

        Node *head = new Node(num);

        if (idx < s.length() && s[idx] == '(')
        {
            idx++;
            head->left = dfs(idx, s);
        }
        if (idx < s.length() && s[idx] == '(')
        {
            idx++;
            head->right = dfs(idx, s);
        }
        idx++;

        return head;
    }

    // function to construct tree from string
    Node *treeFromString(string str)
    {
        int idx = 0;

        return dfs(idx, str);
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends