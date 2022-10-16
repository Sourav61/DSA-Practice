// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head->next == NULL)
        {
            return NULL;
        }
        ListNode *temp = head;
        int len = 1;

        while (temp->next != NULL)
        {
            temp = temp->next;
            len++;
        }

        temp = head;

        int mid = len / 2;

        while (--mid)
        {
            head = head->next;
        }

        if (head->next != NULL)
        {
            head->next = head->next->next;
        }
        else
        {
            head->next = NULL;
        }
        return temp;
    }
};