var findDifferentBinaryString = function(nums) {
    let s = "";
    for (let i = 0; i < nums.length; i++) {
        s += nums[i][i] === '0' ? '1' : '0';
    }
    return s;
};
