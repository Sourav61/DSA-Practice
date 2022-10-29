// https://practice.geeksforgeeks.org/problems/phone-directory4628/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

struct Node
{
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;

        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }

        node->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return false;
            }

            node = node->get(word[i]);
        }

        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;

        for (int i = 0; i < prefix.length(); i++)
        {
            if (!node->containsKey(prefix[i]))
            {
                return false;
            }

            node = node->get(prefix[i]);
        }

        return true;
    }
};

class Solution
{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        map<string, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[contact[i]]++;
        }

        vector<vector<string>> ans;

        for (int i = 0; i < s.size(); i++)
        {
            vector<string> v;

            for (auto x : mp)
            {
                if (x.first.substr(0, i + 1) == s.substr(0, i + 1))
                {
                    v.push_back(x.first);
                }
            }

            if (v.size() == 0)
            {
                v.push_back("0");
            }

            ans.push_back(v);
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string contact[n], s;
        for (int i = 0; i < n; i++)
            cin >> contact[i];
        cin >> s;

        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for (int i = 0; i < s.size(); i++)
        {
            for (auto u : ans[i])
                cout << u << " ";
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends