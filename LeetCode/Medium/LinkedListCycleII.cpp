// https://leetcode.com/problems/linked-list-cycle-ii/

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        if (slow == NULL && fast == NULL)
        {
            return NULL;
        }
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                while (head != fast)
                {
                    fast = fast->next;
                    head = head->next;
                }
                return head;
            }
        }
        return NULL;
    }
};