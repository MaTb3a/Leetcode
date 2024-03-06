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
        unordered_set<ListNode*>st;
        
        while(head){
            if(st.find(head)!=st.end())return true;
            st.insert(head);
            head = head->next;
        }
        return false;
     
    }
};