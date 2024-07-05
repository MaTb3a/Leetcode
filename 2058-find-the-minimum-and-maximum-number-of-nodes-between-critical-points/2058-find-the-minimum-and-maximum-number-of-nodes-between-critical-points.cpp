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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* cur = head->next;
        int idx = 1,lstCritical = -1 , curCritical = -1,miniCritical;
        int minAns= INT_MAX,maxAns = -1;
        while(cur->next){
            if( (cur->val > prev->val  && cur->val > cur->next->val) ||
                (cur->val < prev->val  && cur->val < cur->next->val) ){
                    if(curCritical == -1){
                        curCritical = miniCritical = idx;
                    }
                    else {
                        lstCritical = curCritical;
                        curCritical = idx;
                        minAns = min(minAns,curCritical - lstCritical);
                        maxAns = max(maxAns,curCritical - miniCritical);
                    }
            }
            idx++;
            prev = prev->next;
            cur = cur->next;
        }
        if(minAns == INT_MAX)minAns = -1;
        return {minAns,maxAns};
    }
};