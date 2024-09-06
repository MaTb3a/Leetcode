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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        bitset<100001>vis;//false;
        for(auto it : nums)vis[it]=true;
        ListNode* top = nullptr;
        ListNode* cur = nullptr;
        while(head){
            if(!vis[head->val]){
                if(!top){
                    top = new ListNode(head->val);
                    cur = top;
                }
                else {
                    cur-> next = new ListNode(head->val);
                    cur = cur->next;
                }
            }
            head = head->next;

        }
        return top;
    }
};