// https://practice.geeksforgeeks.org/problems/insertion-sort-for-singly-linked-list/1/?page=1&difficulty[]=1&status[]=unsolved&category[]=Arrays&category[]=Strings&category[]=Linked%20List&category[]=Stack&category[]=Recursion&category[]=Backtracking&sortBy=accuracy#

// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}




 // } Driver Code Ends
//User function Template for C++

/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* insertionSort(struct Node* head_ref)
    {
        Node *dummy = new Node(0);
        
        while(head_ref){
            Node *next = head_ref->next;
            Node *temp = dummy;

            // cout<<temp->next->data<<endl;
            
            while(temp->next && temp->next->data < head_ref->data){
                temp = temp->next;
            }
            
            head_ref->next = temp->next;
            temp->next = head_ref;
            head_ref = next;
        }
        
        return dummy->next;
    }
    
};

// { Driver Code Starts.
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

        Solution ob;

		head = ob.insertionSort(head);
		printList(head);

		cout << "\n";



	}
	return 0;
}  // } Driver Code Endss