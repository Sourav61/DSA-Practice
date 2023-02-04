// https://leetcode.com/problems/sort-list/description/

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
    void findMiddle(ListNode *cur, ListNode **first, ListNode **second)
    {
        ListNode *slow = cur;
        ListNode *fast = cur->next;
        while (fast && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        *first = cur;
        *second = slow->next;
        slow->next = NULL;
    }

    ListNode *mergeBoth(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        if (l1->val <= l2->val)
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

    void merge(ListNode **head)
    {

        ListNode *cur = *head;
        ListNode *first, *second;

        if (!cur || !cur->next)
        {
            return;
        }

        findMiddle(cur, &first, &second);

        merge(&first);
        merge(&second);

        *head = mergeBoth(first, second);
    }

    ListNode *sortList(ListNode *head)
    {
        merge(&head);

        return head;
    }
};

int main()
{

    Solution obj;

    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    ListNode *res = obj.sortList(head);

    while (res != NULL)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;

    return 0;
}