class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt = 0;
        for(int i = 0 ; i+2 < nums.size();i++){
            if(!nums[i]){
                cnt++;
                nums[i]=!nums[i];
                nums[i+1]^=1;
                nums[i+2]^=1;
            }
        }
        return (count(nums.begin(),nums.end(),1)  == nums.size() ? cnt : -1); 
    }
};