// https://leetcode.com/problems/split-linked-list-in-parts/description/

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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        vector<ListNode *> res;
        ListNode *tmp = head;
        int count = 0;

        while (tmp)
        {
            count++;
            tmp = tmp->next;
        }

        int extra = count % k;

        vector<int> cnt(k, count / k);
        int i = 0;
        while (extra--)
        {
            cnt[i]++;
            i++;
        }

        for (auto &x : cnt)
        {
            if (x == 0)
            {
                res.push_back(NULL);
                continue;
            }
            ListNode *temp = head;
            while (--x && head->next)
            {
                head = head->next;
            }
            ListNode *temp2 = head->next;
            head->next = NULL;
            res.push_back(temp);
            head = temp2;
        }

        return res;
    }
};

int main()
{

    Solution obj;

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    vector<ListNode *> res = obj.splitListToParts(head, 5);

    for (auto &x : res)
    {
        if (x)
            cout << x->val << " ";
    }
    cout << endl;

    return 0;
}