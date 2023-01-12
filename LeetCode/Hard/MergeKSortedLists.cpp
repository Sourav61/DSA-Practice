// https://leetcode.com/problems/merge-k-sorted-lists/description/

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
    struct compare
    {
        bool operator()(const ListNode *l, const ListNode *r)
        {
            return l->val > r->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, compare> minH;

        for (auto &x : lists)
        {
            if (x)
                minH.push(x);
        }
        if (minH.empty())
            return NULL;

        ListNode *res = minH.top();
        minH.pop();

        if (res->next)
            minH.push(res->next);

        ListNode *tail = res;

        while (!minH.empty())
        {
            tail->next = minH.top();
            minH.pop();

            tail = tail->next;

            if (tail->next)
                minH.push(tail->next);
        }

        return res;
    }
};

int main()
{

    Solution obj;

    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode *l3 = new ListNode(2);
    l3->next = new ListNode(6);

    vector<ListNode *> lists = {l1, l2, l3};

    ListNode *res = obj.mergeKLists(lists);

    while (res != NULL)
    {
        cout << res->val << " ";
        res = res->next;
    }

    return 0;
}