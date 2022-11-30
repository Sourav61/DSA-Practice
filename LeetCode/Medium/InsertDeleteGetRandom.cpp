// https://leetcode.com/problems/insert-delete-getrandom-o1/description/

#include <bits/stdc++.h>
using namespace std;

class RandomizedSet
{
public:
    RandomizedSet()
    {
    }

    set<int> st;

    bool insert(int val)
    {
        if (st.count(val) == 0)
        {
            st.insert(val);
            return true;
        }
        else
        {
            return false;
        }
    }

    bool remove(int val)
    {
        if (st.count(val) != 0)
        {
            st.erase(val);
            return true;
        }
        else
        {
            return false;
        }
    }

    int getRandom()
    {
        // int n = st.size();

        // set<int>::iterator itr = st.begin();

        // for(int i=0;i<random() % n;i++){
        //     itr++;
        // };

        // return *itr;

        if (st.size() != 0)
        {
            return *next(st.begin(), rand() % st.size());
        }
        return 0;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{
    RandomizedSet *obj = new RandomizedSet();
    bool param_1 = obj->insert(1);
    bool param_2 = obj->remove(2);
    bool param_3 = obj->insert(2);
    int param_4 = obj->getRandom();

    bool param_5 = obj->remove(1);
    bool param_6 = obj->insert(2);
    int param_7 = obj->getRandom();

    cout << param_1 << " " << param_2 << " " << param_3 << " " << param_4 << " " << param_5 << " " << param_6 << " " << param_7 << " " << endl;

    return 0;
}