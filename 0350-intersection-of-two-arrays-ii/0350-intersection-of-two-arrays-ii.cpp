class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int freq[1001]={};
         for(auto it : nums1)
            freq[it]++;
        vector<int>ans;
        for(auto it : nums2){
            if(freq[it]){
                freq[it]--;
                ans.push_back(it);
            }
        }
        return ans;
    }
};