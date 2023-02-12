// https://leetcode.com/problems/fruit-into-baskets/description/

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
    // ListNode *merge(ListNode *start, ListNode *res, int sum)
    // {
    //     if (start == NULL)
    //     {
    //         return res;
    //     }

    //     while (start->val != 0)
    //     {
    //         sum += start->val;
    //         start = start->next;
    //     }

    //     if (res == NULL)
    //     {
    //         ListNode *temp = new ListNode(sum);
    //         res = temp;
    //     }
    //     else
    //     {
    //         ListNode *temp = new ListNode(sum);
    //         res->next = temp;
    //         res = res->next;
    //     }

    //     merge(start->next, res, 0);

    //     return res;
    // }

    // ListNode *mergeNodes(ListNode *head)
    // {
    //     ListNode *start = head->next;
    //     ListNode *res = NULL;

    //     return merge(start, res, 0);
    // }

    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *ptr = new ListNode(0);
        ListNode *dummy = ptr;
        ListNode *temp = head->next;

        int sum = 0;

        while (temp != NULL)
        {
            while (temp->val != 0)
            {
                sum += temp->val;
                temp = temp->next;
            }

            ptr->next = new ListNode(sum);
            ptr = ptr->next;
            temp = temp->next;
            sum = 0;
        }

        return dummy->next;
    }
};
int main()
{
    Solution obj;

    ListNode *head = new ListNode(0);
    head->next = new ListNode(3);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(0);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next->next = new ListNode(0);

    ListNode *res = obj.mergeNodes(head);

    while (res)
    {
        cout << res->val << "->";
        res = res->next;
    }
    cout << "N" << endl;

    return 0;
}