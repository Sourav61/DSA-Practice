// https://leetcode.com/problems/copy-list-with-random-pointer/description/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Os")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *ptr = head;

        if (head == NULL)
        {
            return NULL;
        }

        while (ptr != NULL)
        {
            Node *temp = new Node(ptr->val);
            temp->next = ptr->next;
            ptr->next = temp;

            ptr = ptr->next->next;
        }

        ptr = head;
        Node *temp = ptr->next;
        while (ptr != NULL)
        {
            if (ptr->random)
            {
                temp->random = ptr->random->next;
            }

            ptr = ptr->next->next;
            if (temp->next)
                temp = temp->next->next;
        }

        ptr = head;
        temp = ptr->next;
        Node *res = temp;

        while (ptr != NULL)
        {
            ptr->next = ptr->next->next;
            if (temp->next)
                temp->next = temp->next->next;

            ptr = ptr->next;
            if (temp != NULL && temp->next)
                temp = temp->next;
        }

        return res;
    }
};

int main()
{
    Solution obj;

    Node *head = new Node(0);
    head->next = new Node(3);
    head->next->next = new Node(1);
    head->next->next->next = new Node(0);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next->next = new Node(0);

    Node *res = obj.copyRandomList(head);

    while (res)
    {
        cout << res->val << "->";
        res = res->next;
    }
    cout << "N" << endl;

    return 0;
}