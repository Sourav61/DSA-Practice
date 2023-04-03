// https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1

//{ Driver Code Starts
// Initial template for C++

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
    cout << "\n";
}

// } Driver Code Ends
// User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
public:
    Node *divide(int N, Node *head)
    {
        Node *prev = new Node(-1);
        Node *curr = head;
        prev->next = curr;

        Node *end = head;

        while (end->next != NULL)
        {
            end = end->next;
        }

        while (N--)
        {
            if (curr->data % 2 != 0)
            {
                if (curr->next == NULL)
                    continue;
                if (curr == head)
                {
                    head = head->next;
                }
                prev->next = curr->next;
                curr->next = NULL;

                end->next = curr;
                end = end->next;

                curr = prev->next;
            }
            else
            {
                prev = prev->next;
                curr = curr->next;
            }
        }

        return head;
    }
};

//{ Driver Code Starts.

int main()
{
    // code
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int data;
        cin >> data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N - 1; ++i)
        {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans);
    }
    return 0;
}

// } Driver Code Ends