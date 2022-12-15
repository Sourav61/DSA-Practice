// https://leetcode.com/problems/design-memory-allocator/description/

#include <bits/stdc++.h>
using namespace std;

class Allocator
{
public:
    vector<int> mem;
    int N = 0;
    Allocator(int n)
    {
        N = n;
        mem.resize(n, -1);
    }

    int allocate(int size, int mID)
    {
        for (int i = 0; i < N; i++)
        {
            if (mem[i] == -1)
            {
                int len = 0, j = i;
                if (i + size > N)
                {
                    return -1;
                }

                for (; len < size;)
                {
                    if (mem[i] > 0)
                    {
                        break;
                    }
                    if (mem[i] == -1)
                    {
                        len++;
                        i++;
                    }
                }

                if (size == len)
                {
                    int ret = j;
                    while (size--)
                    {
                        mem[j++] = mID;
                    }

                    return ret;
                }
            }
        }

        return -1;
    }

    int free(int mID)
    {
        int cnt = 0;
        for (int k = 0; k < N; k++)
        {
            if (mem[k] == mID)
            {
                cnt++;
                mem[k] = -1;
            }
        }

        return cnt;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */

int main()
{
    Allocator *obj = new Allocator(10);
    int param_1 = obj->allocate(1, 1);
    int param_2 = obj->allocate(1, 2);
    int param_3 = obj->allocate(1, 3);

    int param_4 = obj->free(2);

    int param_5 = obj->allocate(3, 4);
    int param_6 = obj->allocate(1, 1);
    int param_7 = obj->allocate(1, 1);

    int param_8 = obj->free(1);

    int param_9 = obj->allocate(10, 2);
    int param_10 = obj->free(7);

    cout << param_1 << " " << param_2 << " " << param_3 << " " << param_4 << " " << param_5 << " " << param_6 << " " << param_7 << " " << param_8 << " " << param_9 << " " << param_10 << endl;

    return 0;
}