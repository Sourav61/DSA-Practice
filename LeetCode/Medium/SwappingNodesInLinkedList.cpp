// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

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
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *fast = head, *slow = head;

        for (int i = 0; i < k - 1; i++)
        {
            fast = fast->next;
        }

        ListNode *temp = fast;

        while (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        swap(temp->val, slow->val);

        return head;
    }
};

int main()
{

    Solution obj;

    ListNode *head = 1;
    head->next = 2;
    head->next->next = 3;
    head->next->next->next = 4;
    head->next->next->next->next = 5;

    int k = 2;

    ListNode *res = obj.swapNodes(head, k);

    return 0;
}