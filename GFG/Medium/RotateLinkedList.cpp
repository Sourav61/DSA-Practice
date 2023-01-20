// https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
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

// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
public:
    // Function to rotate a linked list.
    Node *rotate(Node *head, int k)
    {
        Node *tmp = head;
        Node *prev = head;

        int n = 0;

        while (tmp != NULL)
        {
            n++;
            tmp = tmp->next;
        }

        if (n == 1 || head == NULL)
        {
            return head;
        }

        if (k == 0 || k % n == 0)
        {
            return head;
        }

        int num = (k % n);

        while (--num)
        {
            prev = prev->next;
        }

        if (prev && prev->next)
        {
            tmp = prev->next;
        }
        prev->next = NULL;
        prev = head;
        head = tmp;

        while (tmp && tmp->next != NULL)
        {
            tmp = tmp->next;
        }

        tmp->next = prev;

        return head;
    }
};

//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, val, k;
        cin >> n;

        cin >> val;
        Node *head = new Node(val);
        Node *tail = head;

        for (int i = 0; i < n - 1; i++)
        {
            cin >> val;
            tail->next = new Node(val);
            tail = tail->next;
        }

        cin >> k;

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends