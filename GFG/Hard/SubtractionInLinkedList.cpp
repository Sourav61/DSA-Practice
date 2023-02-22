// https://practice.geeksforgeeks.org/problems/subtraction-in-linked-list/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
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

struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

Node *subLinkedList(Node *l1, Node *l2);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node *first = buildList(n);

        cin >> m;
        Node *second = buildList(m);

        Node *res = subLinkedList(first, second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends

/* Structure of linked list Node

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

int length(Node *n)
{
    int len = 0;
    while (n)
    {
        len++;
        n = n->next;
    }

    return len;
}

Node *reverse(Node *head)
{

    Node *prev = NULL;
    Node *forward = NULL;

    while (head != NULL)
    {
        if (head->next)
            forward = head->next;
        else
            forward = NULL;
        head->next = prev;
        prev = head;
        head = forward;
    }

    return prev;
}

// You are required to complete this method
Node *subLinkedList(Node *l1, Node *l2)
{
    Node *res = new Node(-1);
    Node *temp = res;

    while (l1 && l1->data == 0)
    {
        l1 = l1->next;
    }

    while (l2 && l2->data == 0)
    {
        l2 = l2->next;
    }

    int len1 = length(l1);
    int len2 = length(l2);

    Node *h1 = NULL;
    Node *h2 = NULL;

    // cout<<len1<<" "<<len2<<endl;

    if (len1 == len2)
    {
        while (true)
        {
            if (l2->data > l1->data)
            {
                swap(l1, l2);
                // cout<<l1->data<<" "<<l2->data<<endl;
                break;
            }
            else if (l2->data < l1->data)
            {
                break;
            }

            l2 = l2->next;
            l1 = l1->next;

            if (!l1)
                return new Node(0);
        }
    }
    else if (len1 < len2)
    {
        swap(l1, l2);
    }

    h1 = reverse(l1);
    h2 = reverse(l2);

    while (h1 != NULL)
    {
        int sec = 0;
        if (h2 != NULL)
        {
            sec = h2->data;
        }

        if (h1->data < sec)
        {
            if (h1->next)
                h1->next->data = h1->next->data - 1;
            h1->data = h1->data + 10;
        }

        temp->next = new Node(h1->data - sec);
        temp = temp->next;

        h1 = h1->next;
        if (h2)
            h2 = h2->next;
    }

    res = res->next;

    res = reverse(res);

    while (res->next && res->data == 0)
    {
        res = res->next;
    }

    return res;
}