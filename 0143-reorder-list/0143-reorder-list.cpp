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
    void reorderList(ListNode* head) {
        ListNode *cur = head;
        ListNode *rev = NULL;
                ListNode * ptr = head;

        int cnt = 0;
        while(cur){
            cnt++;
            ListNode *tmp = new ListNode(cur->val,rev);
            cur = cur->next;
            rev = tmp;
        }
        if(cnt<3)return;
        ListNode *ans = NULL,*ret = NULL;
        for(int i = 0 ; i < cnt/2 ;i++){
            ListNode * tmp = new ListNode(head->val);
            head = head->next;
            if(!ans){
                ans = tmp;
                ret = ans;
            }
            else {
                ans->next = tmp;
                ans = ans->next;
            }
            
            
            tmp = new ListNode(rev->val);

            rev = rev->next;
            ans->next = tmp;
            ans = ans->next;
            
        }
        if(cnt&1){
            ans->next = new ListNode(head->val);
        }
        while(ret){
            ptr->val = ret->val;
            ret = ret->next;
            ptr = ptr->next;
        }

        
        
    }
};