class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        map<int,int>mpk;
        set<int>sti,stk;
        
        for(auto t : nums)mpk[t]++,stk.insert(t);
        
        for(int j=0;j<nums.size();j++){
            auto iti = sti.begin();
            if(iti != sti.end()){
                auto itk = stk.upper_bound(*iti);
                if(itk!=stk.end() && *iti < *itk && *itk  <nums[j] )return 1;  
            }
                sti.insert(nums[j]);
                mpk[nums[j]]--;
                if(mpk[nums[j]]==0)stk.erase(nums[j]);  
        }
        return 0;
    }    

};