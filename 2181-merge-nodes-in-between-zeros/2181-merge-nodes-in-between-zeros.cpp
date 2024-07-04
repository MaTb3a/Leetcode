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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* node = head;
        while(node){
            while(node->next && node->next->val != 0){
                node->val += node->next->val;
                node->next = node->next->next;
            }
            if(node->next->next == nullptr)
                node->next = nullptr;
            node = node->next;
        }
        return head;
    }
};