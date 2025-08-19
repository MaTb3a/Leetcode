class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0,cnt = 0;
        for(int x: nums){
            if(!x)cnt++;
            else{
                ans+=(cnt*(cnt+1))/2;
                cnt = 0;
            }
        }
        return ans + (cnt*(cnt+1))/2;
    }
};