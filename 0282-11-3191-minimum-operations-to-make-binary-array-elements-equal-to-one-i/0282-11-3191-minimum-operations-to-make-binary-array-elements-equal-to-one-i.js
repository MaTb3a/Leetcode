/**
 * @param {number[]} nums
 * @return {number}
 */
var minOperations = function(nums) {
    let cnt = 0;
    for (let i = 0 ; i < nums.length-2;i++){
        if(nums[i]==0){
            nums[i] = 1;
            nums[i+1]^=1;
            nums[i+2]^=1;
            cnt+=1;
        }
    }
     let s = 0;
    nums.forEach(x=>{
        s+=x;
    });
    return (s == nums.length ? cnt : -1);
};