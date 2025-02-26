class Solution {
    public int maxAbsoluteSum(int[] nums) {
        int sm = 0,mn =0,mx =0;
        for(int x:nums){
            sm+=x;
            mx=Math.max(mx,sm);
            mn=Math.min(mn,sm);
        }
        return mx - mn;
    }
}