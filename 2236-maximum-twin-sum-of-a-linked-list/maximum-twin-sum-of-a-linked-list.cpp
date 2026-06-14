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
    int pairSum(ListNode* head) {
        vector<int>v;
        while(head){
            v.push_back(head->val);
            head = head->next;
        }
        int mx = 0,n = v.size();
        for(int i = 0 ; i < n /2 ;i++)
            mx=max(mx,v[i] + v[n-i-1]);
        return mx;
    }
};