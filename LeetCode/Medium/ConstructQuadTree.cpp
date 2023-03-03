// https://leetcode.com/problems/construct-quad-tree/description/

#include <bits/stdc++h>
using namespace std;

class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution
{
public:
    Node *constructQuad(vector<vector<int>> &grid, int rowStart, int rowEnd, int colStart, int colEnd)
    {
        if (rowStart > rowEnd || colStart > colEnd)
        {
            return NULL;
        }

        bool isLeaf = true;
        int val = grid[rowStart][colStart];

        for (int i = rowStart; i <= rowEnd; i++)
        {
            for (int j = colStart; j <= colEnd; j++)
            {
                if (grid[i][j] != val)
                {
                    isLeaf = false;
                    break;
                }
            }

            if (!isLeaf)
            {
                break;
            }
        }

        if (isLeaf)
        {
            return new Node(val, true);
        }

        int rowMid = (rowStart + rowEnd) / 2;
        int colMid = (colStart + colEnd) / 2;

        Node *topLeft = constructQuad(grid, rowStart, rowMid, colStart, colMid);
        Node *topRight = constructQuad(grid, rowStart, rowMid, colMid + 1, colEnd);
        Node *bottomLeft = constructQuad(grid, rowMid + 1, rowEnd, colStart, colMid);
        Node *bottomRight = constructQuad(grid, rowMid + 1, rowEnd, colMid + 1, colEnd);

        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }

    Node *construct(vector<vector<int>> &grid)
    {
        int n = grid.size();

        return constructQuad(grid, 0, n - 1, 0, n - 1);
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> grid = {{1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}};

    Node *res = obj.construct(grid);

    return 0;
}