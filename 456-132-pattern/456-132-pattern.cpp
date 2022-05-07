class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        map<int,int>mpk;
        set<int>stk;
        
        for(auto t : nums)mpk[t]++,stk.insert(t);
        int i = nums[0];
        
        for(int j=0;j<nums.size();j++){
            auto itk = stk.upper_bound(i);
            if(itk!=stk.end() && i < *itk && *itk  <nums[j] )return 1;  
            i = min(i,nums[j]);
            mpk[nums[j]]--;
            if(mpk[nums[j]]==0)stk.erase(nums[j]);  
        }
        return 0;
    }    

};