/**
 * @param {number[]} nums
 * @return {boolean}
 */
var divideArray = function(nums) {
    let xr = 0,xr2=0;
    for(let x of nums){
        xr^=x;
        xr2^=(x+1);
    }
    return xr == 0 && xr2==0;
};