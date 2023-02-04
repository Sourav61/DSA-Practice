// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/

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
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        unordered_map<int, ListNode *> mp;
        ListNode *start = new ListNode(0);
        start->next = head;
        ListNode *pt = start, *temp = start;
        int sum = 0;

        while (pt != NULL)
        {
            sum += pt->val;

            if (mp[sum] != NULL)
            {
                temp = mp[sum]->next;

                int prevSum = sum + temp->val;
                while (temp && prevSum != sum)
                {
                    mp.erase(prevSum);
                    temp = temp->next;
                    if (temp)
                        prevSum += temp->val;
                }
                mp[sum]->next = pt->next;
            }
            else
            {
                mp[sum] = pt;
            }

            pt = pt->next;
        }

        return start->next;
    }
};

int main()
{

    Solution obj;

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(-3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(1);

    ListNode *res = obj.removeZeroSumSublists(head);

    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;

    return 0;
}