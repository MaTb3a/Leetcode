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
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int>v;
        while(head){
            v.push_back(head->val);
            head = head->next;
        }
        vector<pair<int,int>>v2;
        for(int i = 0 ; i < v.size();i++){
            int sum = v[i];
            for(int j = i+1 ; j < v.size();j++){
                sum+=v[j];
                if(!sum)v2.push_back({i,j});
            }
        }
        for(auto t : v2){
            cout<<t.first<<" "<<t.second<<endl;
            if(v[t.first]==1001)continue;
            for(int i = t.first ; i <=t.second ;i++)
                v[i] = 1001;
        }
        cout<<endl<<endl;
        vector<int>ans;
  
        for(int i = 0 ; i < v.size();i++)if(v[i]!=1001 && v[i])ans.push_back(v[i]);
              for(auto t : ans)cout<<t<<" ";
        cout<<endl;
        ListNode* Fans = NULL;
        if(ans.size())Fans = new ListNode(ans[0]);
        ListNode* r = Fans;
        for(int i = 1; i < ans.size();i++){
            ListNode *cur = new ListNode(ans[i]);
            Fans->next = cur;
            Fans = Fans->next;
        }
        return r;
        
        return NULL;
    }
};