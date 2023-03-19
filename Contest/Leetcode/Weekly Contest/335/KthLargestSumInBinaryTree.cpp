// https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        priority_queue<long long> pq;

        queue<TreeNode *> q;
        q.push(root);
        long long res = 0;

        while (!q.empty())
        {
            int sz = q.size();
            long long sum = 0;

            while (sz--)
            {
                auto curr = q.front();
                q.pop();

                sum += curr->val;

                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
            }

            pq.push(sum);
        }

        while (pq.size() > 0 && --k)
        {
            pq.pop();
        }

        return k > 0 ? -1 : pq.top();
    }
};

int main()
{

    Solution obj;

    TreeNode *root = new TreeNode(5);

    root->left = new TreeNode(8);
    root->right = new TreeNode(9);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(1);

    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(7);

    root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(6);

    cout << obj.kthLargestLevelSum(root, 2);

    return 0;
}