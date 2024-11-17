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
    ListNode* reverse(ListNode* head){
        ListNode *lst = nullptr;
        while(head){
            ListNode* tmp = new ListNode(head->val,lst);
            lst = tmp;
            head = head->next;
        }
        return lst;
    }
    ListNode* getList(ListNode* head,int len){
        if(!head)return nullptr;
        ListNode* top = new ListNode(head->val);
        ListNode* cur = top;
        while(--len && head->next){
            head = head->next;
            ListNode* tmp = new ListNode(head->val);
            cur->next = tmp;
            cur = cur->next;
        }
        return top;
    }
    int count(ListNode* head){
        int cnt = 0;
        while(head){
            cnt++;
            head = head->next;
        }
        return cnt;
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int n = count(head);
        ListNode* top = new ListNode(head->val);
        ListNode* cur = top;
        head = head->next;
        for(int i = 2; ;i++){
            
            ListNode* curList = getList(head,i);
            int sz = count(curList);
            if(sz&1){
                for(int j = 0 ; j < sz && head;j++){
                    cur->next = new ListNode(head->val);
                    cur = cur->next;
                    head = head->next;
                }
            }
            else {
                cur->next = reverse(curList);
                for(int j = 0 ; j < sz && head; j++){
                    cur = cur->next;
                    head = head->next;
                }
            }
            if(sz!=i)break;
           
        }
        return top;
        
    }
};