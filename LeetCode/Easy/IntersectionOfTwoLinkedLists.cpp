// https://leetcode.com/problems/intersection-of-two-linked-lists/submissions/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
    // My Solution

    // private:
    //     int length(ListNode *head)
    //     {
    //         int count = 0;
    //         ListNode *temp = head;
    //         while (temp != NULL)
    //         {
    //             temp = temp->next;
    //             count++;
    //         }

    //         return count;
    //     }
    // public:
    //     ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
    //         int l1 = length(head1);
    //         int l2 = length(head2);

    //         int d = 0;

    //         ListNode *ptr1;
    //         ListNode *ptr2;

    //         if (l1 > l2)
    //         {
    //             d = l1 - l2;
    //             ptr1 = head1;
    //             ptr2 = head2;
    //         }
    //         else
    //         {
    //             d = l2 - l1;
    //             ptr1 = head2;
    //             ptr2 = head1;
    //         }

    //         while (d)
    //         {

    //             ptr1 = ptr1->next;

    //             if (ptr1 == NULL)
    //             {
    //                 return NULL;
    //             }

    //             d--;
    //         }

    //         while (ptr1 != NULL && ptr2 != NULL)
    //         {
    //             if (ptr1 == ptr2)
    //             {
    //                 return ptr1;
    //             }

    //             ptr1 = ptr1->next;
    //             ptr2 = ptr2->next;
    //         }

    //         return NULL;
    //     }
    // };

    // Modified Solution
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *p1 = headA;
        ListNode *p2 = headB;

        if (p1 == NULL || p2 == NULL)
            return NULL;

        while (p1 != NULL && p2 != NULL && p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;

            if (p1 == p2)
                return p1;

            if (p1 == NULL)
                p1 = headB;
            if (p2 == NULL)
                p2 = headA;
        }

        return p1;
    }
};