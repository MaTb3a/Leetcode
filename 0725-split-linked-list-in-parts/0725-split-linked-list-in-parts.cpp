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
    
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int sz = 0;
        ListNode* cur = head;
        while(cur)sz++,cur=cur->next;
        auto [q,r] = div(sz,k);
        vector<ListNode*>v;
        cur = head;
        for(int i = 0 ; i < k;i++){
            ListNode* top = cur;
            int n = q + (r > 0 ? 1 : 0);
            r--;
            for(int j = 0 ; j < n -1 && cur; j++)
                cur = cur->next;
            if(cur){
                ListNode* nxt = cur->next;
                cur->next = nullptr;
                cur = nxt;
            }
            v.push_back(top);
        }
        return v;

    }
};