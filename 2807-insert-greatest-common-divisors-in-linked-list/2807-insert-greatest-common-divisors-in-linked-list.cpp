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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* cur = head;
        while(cur->next){
            int g = __gcd(cur->val,cur->next->val);
            ListNode* gcdN = new ListNode(g,cur->next);
            cur->next = gcdN;
            cur = gcdN->next;
        }
        return head;
    }
};