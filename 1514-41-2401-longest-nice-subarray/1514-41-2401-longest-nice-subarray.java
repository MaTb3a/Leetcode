class Solution {
    public int longestNiceSubarray(int[] nums) {
        int l = 0, ans = 0 ,mask =0;
        for(int r = 0 ; r < nums.length;r++){
            while((nums[r] & mask) !=0){
                mask^=nums[l];
                l+=1;
            }
            mask^=nums[r];
            ans=Math.max(ans,r-l+1);
        }
        return ans;
    }
}