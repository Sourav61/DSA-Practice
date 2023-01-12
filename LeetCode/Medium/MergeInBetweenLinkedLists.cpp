// https://leetcode.com/problems/merge-in-between-linked-lists/description/

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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *st = list1;
        ListNode *en = list1;

        while (--a)
        {
            st = st->next;
        }

        while (b-- && en->next != NULL)
        {
            en = en->next;
        }

        st->next = list2;

        while (st->next != NULL)
        {
            st = st->next;
        }

        st->next = en->next;
        return list1;
    }
};

int main()
{

    Solution obj;

    ListNode *list1 = new ListNode(0);
    list1->next = new ListNode(1);
    list1->next->next = new ListNode(2);
    list1->next->next->next = new ListNode(3);
    list1->next->next->next->next = new ListNode(4);
    list1->next->next->next->next->next = new ListNode(5);

    ListNode *list2 = new ListNode(1000000);
    list2->next = new ListNode(1000001);
    list2->next->next = new ListNode(1000002);

    ListNode *res = obj.mergeInBetween(list1, 3, 4, list2);

    // cout << res->next->val << endl;

    return 0;
}