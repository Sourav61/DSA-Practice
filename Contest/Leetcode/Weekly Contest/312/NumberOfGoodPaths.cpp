// https://leetcode.com/problems/number-of-good-paths/description/

struct DSU
{
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findParent(int x)
    {
        if (x == parent[x])
        {
            return x;
        }

        return (parent[x] = findParent(parent[x]));
    }

    void merge(int x, int y)
    {
        x = findParent(x);
        y = findParent(y);
        if (x == y)
            return;
        if (size[x] > size[y])
            swap(x, y);

        size[y] += size[x];
        parent[x] = y;
    }
};

class Solution
{
public:
    int numberOfGoodPaths(vector<int> &vals, vector<vector<int>> &edges)
    {
        int n = vals.size();
        vector<int> adj[n];

        for (auto &x : edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        map<int, vector<int>> val_to_nodes;

        for (int i = 0; i < n; i++)
        {
            val_to_nodes[vals[i]].push_back(i);
        }

        DSU dsu(n);
        int res = n;

        vector<bool> is_active(n);

        for (auto [_, indexes] : val_to_nodes)
        {
            for (auto i : indexes)
            {
                for (auto child : adj[i])
                {
                    if (is_active[child])
                    {
                        dsu.merge(i, child);
                    }
                }
                is_active[i] = true;
            }

            vector<int> leaders;
            for (auto x : indexes)
            {
                leaders.push_back(dsu.findParent(x));
            }
            sort(leaders.begin(), leaders.end());

            int sz = leaders.size();

            for (int i = 0; i < sz; i++)
            {
                long long cnt = 0;
                int cur = leaders[i];

                while (i < sz && leaders[i] == cur)
                {
                    i++;
                    cnt++;
                }
                i--;

                res += (cnt * (cnt - 1)) / 2;
            }
        }

        return res;
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 3}, {2, 4}};

    vector<int> vals = {1, 3, 2, 1, 3};

    cout << obj.numberOfGoodPaths(vals, edges);

    return 0;
}