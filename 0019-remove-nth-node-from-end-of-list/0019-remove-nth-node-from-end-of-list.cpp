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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)return NULL;
        if(head->next == NULL)return NULL;

        int length = 0 ;
        ListNode* p = head;
        ListNode* tmp = head;
        while(tmp){
            length++;
            tmp = tmp->next;
        }
        if(length==n)head=head->next;
        else 
            for(int i = 1 ; i <(length - n) ;i++)
                p=p->next;
        p->next = p->next->next;
        return head;
         
    }
};