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
    int len(ListNode* head){
        int cnt = 0;
        while(head){
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    int getDecimalValue(ListNode* head) {
        int ans = 0,cnt = len(head);
        cout<<cnt<<"\n";
        while(cnt--){
            if(head->val)ans+=(1<<cnt);
            head = head->next;
        }
        return ans;
    }
};