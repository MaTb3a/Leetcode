class Solution {
    public int minOperations(int[] nums) {
        int cnt = 0;
        for(int i = 0 ; i< nums.length-2;i++){
            if(nums[i]==0){
                nums[i] = 1;
                nums[i+1] ^=1;
                nums[i+2] ^=1;
                cnt++;
            }
        }
        return (Arrays.stream(nums).sum() == nums.length ? cnt : -1);
    }
}