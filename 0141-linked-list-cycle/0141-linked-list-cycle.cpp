/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* cpy = head;
        while( cpy  && cpy->next && cpy->next->next){
            cpy = cpy->next->next;
            head = head->next;
            if(head == cpy)return true;
        }
        return false;
     
    }
};