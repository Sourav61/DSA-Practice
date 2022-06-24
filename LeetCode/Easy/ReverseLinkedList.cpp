// https://leetcode.com/problems/reverse-linked-list/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* newhead = reverseList(head->next);
        
        head->next->next = head;
        head->next = NULL;
        
        return newhead;
    }
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

int main(){
    Solution obj;

    ListNode* head = NULL;

    insertAtHead(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);

    display(head);

    ListNode* newhead = obj.reverseList(head);

    display(newhead);

    return 0;
}