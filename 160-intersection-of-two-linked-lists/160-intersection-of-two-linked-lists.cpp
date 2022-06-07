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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       set<ListNode*>sedra;
        while(headA){
            sedra.insert(headA);
            headA=headA->next;
        }
        while(headB){
            if(sedra.find(headB) != sedra.end()){
                return headB;
            }
            headB=headB->next;
        }
        return headB;
    }
};