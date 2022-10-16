// https://leetcode.com/problems/reorder-list/

#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        vector<int> v;
        ListNode *temp = head;
        while (temp != NULL)
        {
            v.push_back(temp->val);
            temp = temp->next;
        }
        int start = 0;
        int end = v.size() - 1;
        while (start < end)
        {
            if (start + 2 == end)
            {
                head->val = v[start];
                head->next->val = v[end--];
                head->next->next->val = v[start + 1];
                break;
            }
            head->val = v[start++];
            head->next->val = v[end--];
            head = head->next->next;
        }
    }
};