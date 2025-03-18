/**
 * @param {number[]} nums
 * @return {number}
 */
var longestNiceSubarray = function(nums) {
    let l = 0,ans = 0,mask =0;
    for (let r = 0; r < nums.length;r++){
        while(nums[r]&mask){
            mask^=nums[l];
            l+=1;
        }
          mask^=nums[r];
        ans=Math.max(ans,r-l+1);
    }
    return ans;
};