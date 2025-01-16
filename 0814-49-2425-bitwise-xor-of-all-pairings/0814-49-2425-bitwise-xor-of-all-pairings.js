var xorAllNums = function(nums1, nums2) {
    let xor1 = nums2.length % 2 === 1 ? nums1.reduce((acc, num) => acc ^ num, 0) : 0;
    let xor2 = nums1.length % 2 === 1 ? nums2.reduce((acc, num) => acc ^ num, 0) : 0;
    return xor1 ^ xor2;
};
