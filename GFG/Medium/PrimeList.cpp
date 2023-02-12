// https://practice.geeksforgeeks.org/problems/6cb0782855c0f11445b8d70e220f888e6ea8e22a/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int num)
    {
        val = num;
        next = NULL;
    }
};

// } Driver Code Ends
// User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Os")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

class Solution
{
public:
    bool isPrime(int n)
    {
        if (n == 1)
            return false;

        if (n == 2 || n == 3)
            return true;

        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }

        return true;
    }

    Node *primeList(Node *head)
    {
        // Node *temp = head;

        // while (temp)
        // {
        //     if (temp->val == 1)
        //     {
        //         temp->val = 2;
        //         temp = temp->next;
        //         continue;
        //     }

        //     int x = temp->val;
        //     int y = temp->val;

        //     while (!isPrime(x))
        //     {
        //         x--;
        //     }

        //     while (!isPrime(y))
        //     {
        //         y++;
        //     }

        //     if (temp->val - x > y - temp->val)
        //     {
        //         temp->val = y;
        //     }
        //     else
        //     {
        //         temp->val = x;
        //     }

        //     temp = temp->next;
        // }

        // return head;

        Node *temp = head;

        int n = 1e5;

        vector<bool> isPrime(n, true);

        for (int i = 2; i * i < n; i++)
        {
            if (isPrime[i] == true)
            {
                for (int j = i * i; j < n; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }

        while (temp)
        {
            if (temp->val == 1)
            {
                temp->val = 2;
                temp = temp->next;
                continue;
            }

            int x = temp->val;
            int y = temp->val;

            while (!isPrime[x])
            {
                x--;
            }

            while (!isPrime[y])
            {
                y++;
            }

            if (temp->val - x > y - temp->val)
            {
                temp->val = y;
            }
            else
            {
                temp->val = x;
            }

            temp = temp->next;
        }

        return head;
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
        Node *head, *tail;
        int num;
        cin >> num;
        head = tail = new Node(num);
        for (int i = 0; i < n - 1; i++)
        {
            int num;
            cin >> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        Solution ob;
        Node *temp = ob.primeList(head);
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends