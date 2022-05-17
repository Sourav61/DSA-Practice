// https://leetcode.com/problems/find-the-winner-of-the-circular-game/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct node
    {
        int val;
        node *next;
    };
    int findTheWinner(int n, int k)
    {
        if (k == 1)
            return n;
        node *p;
        node *cur;
        for (int i = 1; i <= n; i++)
        {
            node *temp = new node;
            temp->val = i;
            temp->next = NULL;
            if (i == 1)
            {
                p = cur = temp;
            }
            else
            {
                cur->next = temp;
                cur = temp;
            }
        }
        cur->next = p;
        int i = 1;

        //         until only one node is left

        while (p != p->next)
        {
            if (i % (k - 1) == 0)
            {
                p->next = p->next->next;
            }
            p = p->next;
            i++;
        }
        return p->val;
    }
};