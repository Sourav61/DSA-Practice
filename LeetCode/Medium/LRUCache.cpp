// https://leetcode.com/problems/lru-cache/

#include<bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    class node{
        public:
            int key;
            int val;

            node* prev;
            node* next;

        node(int _key, int _val){
            key = _key;
            val = _val;
        }
    };

    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);

    int cap;
    unordered_map<int, node*>m;

    LRUCache(int capacity)
    {
        // code here
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(node* newnode){
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(node* delnode){
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key)
    {
        if(m.find(key) != m.end()){
            node* resnode = m[key];
            int res = resnode->val;
            m.erase(key);
            deletenode(resnode);
            addnode(resnode);
            m[key] = head->next;
            return res;
        }

        return -1;
    }
    
    void put(int key, int value)
    {
        if(m.find(key) != m.end()){
            node* existingNode = m[key];
            m.erase(key);
            deletenode(existingNode);
        }

        if(m.size() == cap){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        addnode(new node(key, value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){

    LRUCache *obj = new LRUCache(2);

    obj->put(1,1);
    obj->put(2,2);
    cout<<obj->get(1)<<endl;

    obj->put(3,3);
    cout<<obj->get(2)<<endl;

    obj->put(4,4);

    cout<<obj->get(1)<<endl;
    cout<<obj->get(3)<<endl;
    cout<<obj->get(4)<<endl;

    return 0;
}