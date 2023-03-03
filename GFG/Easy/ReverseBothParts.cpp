// https://practice.geeksforgeeks.org/problems/bae68b4d6a2a77fb6bd459cf7447240919ebfbf5/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}

// } Driver Code Ends
// User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/

class Solution
{
public:
    Node *reverseList(Node *head)
    {
        if (head->next == NULL)
        {
            return head;
        }

        Node *newhead = reverseList(head->next);

        head->next->next = head;

        head->next = NULL;

        return newhead;
    }

    Node *reverse(Node *head, int k)
    {
        Node *temp = head;

        k--;
        while (k--)
        {
            temp = temp->next;
        }

        Node *head2 = temp->next;
        temp->next = NULL;

        head = reverseList(head);
        head2 = reverseList(head2);

        temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }

        temp->next = head2;

        return head;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}
// } Driver Code Ends