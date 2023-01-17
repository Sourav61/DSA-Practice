// https://leetcode.com/problems/rotate-list/description/

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
    ListNode *rotateRight(ListNode *head, int k)
    {
        ListNode *tmp = head;
        ListNode *prev = head;

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

        int num = n - (k % n);

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

int main()
{

    Solution obj;

    ListNode *head = new ListNode(1);

    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    ListNode *res = obj.rotateRight(head, 2);

    while (res != NULL)
    {
        cout << res->val << " ";
        res = res->next;
    }

    return 0;
}