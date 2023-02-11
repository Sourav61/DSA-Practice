// https://leetcode.com/problems/linked-list-components/description/

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
    int numComponents(ListNode *head, vector<int> &nums)
    {
        unordered_map<int, int> mp;

        for (auto &x : nums)
        {
            mp[x] = 1;
        }
        int res = 0;

        while (head != NULL)
        {
            int temp = head->val;
            if (mp[temp] == 1)
            {
                while (head && mp[temp] == 1)
                {
                    head = head->next;
                    if (head)
                        temp = head->val;
                }
                res++;
            }

            if (head)
                head = head->next;
        }

        return res;
    }
};

int main()
{

    Solution obj;

    ListNode *head = new ListNode(0);
    head->next = new ListNode(3);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next->next = new ListNode(7);

    vector<int> nums = {0, 2, 3, 6, 7};

    cout << obj.numComponents(head, nums);

    return 0;
}