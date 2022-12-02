// https://leetcode.com/problems/palindrome-linked-list/submissions/852764959/

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
    bool isPalindrome(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast != NULL)
        {
            slow = slow->next;
        }

        ListNode *p = slow, *prev = NULL, *nxt = NULL;

        while (p)
        {
            nxt = p->next;
            p->next = prev;
            prev = p;
            p = nxt;
        }

        while (prev && head)
        {
            if (prev->val != head->val)
                return false;

            prev = prev->next;
            head = head->next;
        }

        return true;
    }
};

int main()
{
    Solution obj;

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    cout << obj.isPalindrome(head);

    return 0;
}