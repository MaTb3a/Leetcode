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
    
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *cur = new ListNode();
        ListNode *head1 = cur;
        
        for(int i = 0 ; i < a;i ++){
            cur->next = new ListNode(list1->val);
            cur = cur->next;
            list1 = list1->next;
        }
        for(int i = a ; i <= b ; i++)list1 = list1->next;
        
        
        while(list2){
            cur->next = new ListNode(list2->val);
            cur = cur->next;
            list2 = list2->next;
        }
        while(list1){
            cur->next = new ListNode(list1->val);
            cur = cur->next;
            list1 = list1->next;
        }
        
        
        return head1->next;
            
    
    }
};