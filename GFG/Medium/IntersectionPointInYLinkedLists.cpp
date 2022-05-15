// https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1#
// { Driver Code Starts
#include <iostream>

#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
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

int intersectPoint(struct Node *head1, struct Node *head2);

Node *inputList(int size)
{
    if (size == 0)
        return NULL;

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

/* Driver program to test above function*/
int main()
{
    int T, n1, n2, n3;

    cin >> T;
    while (T--)
    {
        cin >> n1 >> n2 >> n3;

        Node *head1 = inputList(n1);
        Node *head2 = inputList(n2);
        Node *common = inputList(n3);

        Node *temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends

/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

// Function to find intersection point in Y shaped Linked Lists.

// My Approach TC=O(N)

// int length(Node *head)
// {
//     int count = 0;
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         temp = temp->next;
//         count++;
//     }
//     return count;
// }

// int intersectPoint(Node *head1, Node *head2)
// {
//     int l1 = length(head1);
//     int l2 = length(head2);
//     int d = 0;

//     Node *ptr1;
//     Node *ptr2;

//     if (l1 > l2)
//     {
//         d = l1 - l2;
//         ptr1 = head1;
//         ptr2 = head2;
//     }
//     else
//     {
//         d = l2 - l1;
//         ptr1 = head2;
//         ptr2 = head1;
//     }

//     while (d)
//     {
//         ptr1 = ptr1->next;
//         if (ptr1 == NULL)
//         {
//             return -1;
//         }
//         d--;
//     }

//     while (ptr1 != NULL && ptr2 != NULL)
//     {
//         if (ptr1 == ptr2)
//         {
//             return ptr1->data;
//         }
//         ptr1 = ptr1->next;
//         ptr2 = ptr2->next;
//     }

//     return -1;
// }

// Modified Approach TC=O(N)

int intersectPoint(Node *head1, Node *head2)
{
    Node *p1 = head1;
    Node *p2 = head2;
    if (p1 == NULL || p2 == NULL)
        return -1;
    while (p1 != NULL && p2 != NULL && p1 != p2)
    {
        p1 = p1->next;
        p2 = p2->next;

        if (p1 == p2)
            return p1->data;

        if (p1 == NULL)
            p1 = head2;
        if (p2 == NULL)
            p2 = head1;
    }
    return p1->data;
}
