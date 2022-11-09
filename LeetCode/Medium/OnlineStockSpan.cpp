// https://leetcode.com/problems/online-stock-span/description/

#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
public:
    stack<pair<int, int>> st;
    int index;
    StockSpanner()
    {
        index = -1;
    }

    int next(int price)
    {
        index += 1;

        while (!st.empty() && st.top().second <= price)
        {
            st.pop();
        }

        if (st.empty())
        {
            st.push({index, price});
            return index + 1;
        }

        int idx = st.top().first;
        st.push({index, price});
        return index - idx;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main()
{
    StockSpanner *obj = new StockSpanner();
    int param_1 = obj->next(100);
    int param_2 = obj->next(80);
    int param_3 = obj->next(60);
    int param_4 = obj->next(70);
    int param_5 = obj->next(60);
    int param_6 = obj->next(75);
    int param_7 = obj->next(85);

    cout << param_1 << " " << param_2 << " " << param_3 << " " << param_4 << " " << param_5 << " " << param_6 << " " << param_7 << endl;

    return 0;
}