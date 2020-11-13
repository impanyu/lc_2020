/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* con;
        ListNode* tail;
        int i = 1;
        while(cur){
            if(i<m) {
                prev = cur;
                cur = cur->next;
            }
            else if(i>n) break;
            else{
                if(i==m){
                    con = prev;
                    tail = cur;
                }
                    
                ListNode* tmp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = tmp;
            }
            i++;
        }
        if(con)
            con->next = prev;
        else
            head = prev;
        tail -> next = cur;
        
        return head;
    }
};
