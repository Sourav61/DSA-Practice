// https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-Linked-lists/1

// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
   //Function to add two numbers represented by linked list.
    Node *reverseRecursive(Node *&head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        } 
        
        Node *newhead = reverseRecursive(head->next);
        
        head->next->next = head;
    
        head->next = NULL;
    
        return newhead;
    }
   
    struct Node* addTwoLists(struct Node* l1, struct Node* l2)
    {
        int ans = 0;
        Node newhead(0);
        Node *t = &newhead;
        
        l1 = reverseRecursive(l1);
        l2 = reverseRecursive(l2);
    
        while(ans || l1 || l2){
            ans += (l1 ? l1->data : 0) + (l2 ? l2->data : 0);
            t->next = new Node(ans%10);
            t = t->next;
            ans/=10;
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        
        newhead.next = reverseRecursive(newhead.next);
    
        return newhead.next;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends