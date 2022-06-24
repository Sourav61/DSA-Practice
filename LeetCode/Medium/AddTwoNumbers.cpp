// https://leetcode.com/problems/add-two-numbers/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void insertAtHead(ListNode*& head, int val){
    ListNode* n = new ListNode(val);

    n->next = head;

    head = n;
}

void deleteAtHead(ListNode*& head){
    ListNode* todelete = head;

    head = head->next;

    delete todelete;
}

void insertAtTail(ListNode*& head, int val){
    ListNode* n = new ListNode(val);
    
    if(head == NULL){
        head = n;
        return;
    }

    ListNode* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = n;
}

void deletion(ListNode*& head, int val){
    if(head == NULL){
        return;
    }

    if(head->next == NULL){
        deleteAtHead(head);
        return;
    }
    
    ListNode* temp = head;

    while(temp->next->val != val){
        temp = temp->next;
    }

    ListNode* todelete = temp->next;

    temp->next = temp->next->next;

    delete todelete;
}

void display(ListNode* head){
    ListNode* temp = head;

    while(temp != NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }

    cout<<"NULL"<<endl;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int ans = 0;
        ListNode newhead(0);
        ListNode *t = &newhead;

        while(ans || l1 || l2){
            ans += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            t->next = new ListNode(ans%10);
            t = t->next;
            ans/=10;
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }

        return newhead.next;
    }
};

int main(){
    Solution obj;

    ListNode* l1 = NULL;

    ListNode* l2 = NULL;

    insertAtHead(l1, 2);
    insertAtTail(l1, 4);
    insertAtTail(l1, 3);

    insertAtHead(l2, 5);
    insertAtTail(l2, 6);
    insertAtTail(l2, 4);

    ListNode* l3 = obj.addTwoNumbers(l1, l2);

    display(l3);

    return 0;
}