var majorityElement = function(nums) {
    let ans = 0, cnt = 0;
    for (let x of nums) {
        if (cnt === 0) {
            ans = x;
            cnt = 1;
        } else if (ans === x) {
            cnt++;
        } else {
            cnt--;
        }
    }
    return ans;
};
