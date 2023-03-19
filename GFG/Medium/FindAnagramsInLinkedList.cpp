// https://practice.geeksforgeeks.org/problems/de6f6a196aecdfb3e4939ba7729809a5a4bdfe90/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    struct Node *next;

    Node(char x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}

// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution
{
public:
    void flush(vector<int> &arr)
    {
        for (int i = 0; i < 26; i++)
        {
            arr[i] = 0;
        }
    }

    vector<Node *> findAnagrams(struct Node *head, string s)
    {
        // code here
        int len = s.size();
        vector<int> f1(26, 0), f2(26, 0);

        vector<Node *> res;

        for (int i = 0; i < len; i++)
        {
            f1[s[i] - 'a']++;
        }

        Node *prev = head, *nex = head, *justprev = NULL;

        int cnt = 0;

        while (nex)
        {
            if (cnt < len)
            {
                f2[nex->data - 'a']++;
                cnt++;
            }
            else
            {
                if (f2 == f1)
                {
                    res.push_back(prev);
                    justprev->next = NULL;

                    justprev = NULL;

                    prev = nex;
                    flush(f2);

                    if (!nex)
                    {
                        break;
                    }
                    cnt = 1;
                    f2[nex->data - 'a']++;
                }
                else
                {
                    f2[prev->data - 'a']--;
                    f2[nex->data - 'a']++;
                    prev = prev->next;
                }
            }

            justprev = nex;
            nex = nex->next;
        }

        if (f2 == f1)
        {
            res.push_back(prev);
            if (justprev)
            {
                justprev->next = NULL;
            }
        }

        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++)
        {
            printList(res[i]);
        }

        if (res.size() == 0)
            cout << "-1\n";
    }
}

// } Driver Code Endss