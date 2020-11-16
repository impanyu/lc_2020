/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    unordered_map<Node*,Node*> oldtonew;
    Node* copyRandomList(Node* head) {      
        if(head==NULL) return head;
        if(oldtonew.count(head)>0) return oldtonew[head];
        Node* newnode=new Node(head->val,NULL,NULL);
        oldtonew[head]=newnode;
        newnode->next=copyRandomList(head->next);
        newnode->random=copyRandomList(head->random);
        return newnode;
    }
};
