class Solution {
    public boolean divideArray(int[] nums) {
        int xr = 0;
        int xr2 = 0;
        for(int i = 0 ; i < nums.length;i++){
            xr^=nums[i];
            xr2^=(nums[i]+1);
        }
        return xr == 0 && xr2==0;
    }
}