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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode* cur = nullptr;
        while(head){
            ListNode *nxt = new ListNode(head->val,cur);
            cur = nxt;
            head = head->next;
        }
        return cur;
        
        
    }
};