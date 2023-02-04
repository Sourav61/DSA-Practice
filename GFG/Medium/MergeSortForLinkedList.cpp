// https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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
/* Structure of the linked list node is as
struct Node
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

class Solution
{
public:
    // Function to sort the given linked list using Merge Sort.

    void findMiddle(Node *cur, Node **first, Node **second)
    {
        Node *slow = cur;
        Node *fast = cur->next;
        while (fast && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        *first = cur;
        *second = slow->next;
        slow->next = NULL;
    }

    Node *mergeBoth(Node *l1, Node *l2)
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        if (l1->data <= l2->data)
        {
            l1->next = mergeBoth(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeBoth(l2->next, l1);
            return l2;
        }
    }

    void merge(Node **head)
    {

        Node *cur = *head;
        Node *first, *second;

        if (!cur || !cur->next)
        {
            return;
        }

        findMiddle(cur, &first, &second);

        merge(&first);
        merge(&second);

        *head = mergeBoth(first, second);
    }

    Node *mergeSort(Node *head)
    {
        merge(&head);

        return head;
    }
};

//{ Driver Code Starts.

void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node **head_ref, int new_data)
{
    Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
    long test;
    cin >> test;
    while (test--)
    {
        struct Node *a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends