// https://leetcode.com/problems/middle-of-the-linked-list/submissions/

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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

int main()
{
    Solution obj;

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(5);

    cout << obj.middleNode(head)->val;

    return 0;
}