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
    bool isPalindrome(ListNode* head) {
        ListNode* cur = head,*back = nullptr;
        while(cur){
            ListNode* tmp = new ListNode(cur->val,back);
            back = tmp;
            cur = cur->next;
        }
        while(head){
            if(head->val!=back->val)return false;
            head = head->next; back = back->next;
        }
        return true;
    }
};