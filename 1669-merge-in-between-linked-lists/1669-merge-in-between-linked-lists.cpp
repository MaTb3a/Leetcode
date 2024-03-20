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
    
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prevA = nullptr;
        ListNode* curr = list1;
        for (int i = 0; i < a; ++i) {
            prevA = curr;
            curr = curr->next;
        }

        ListNode* afterB = curr;
        for (int i = a; i <= b; ++i) {
            afterB = afterB->next;
        }

        if (prevA) {
            prevA->next = list2;
        } else {
            list1 = list2;
        }

        ListNode* endList2 = list2;
        while (endList2->next) {
            endList2 = endList2->next;
        }
        endList2->next = afterB;

        return list1;
            
    
    }
};