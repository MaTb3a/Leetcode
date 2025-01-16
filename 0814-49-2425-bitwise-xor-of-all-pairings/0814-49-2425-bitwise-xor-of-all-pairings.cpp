class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        return (nums2.size()&1 ? reduce(nums1.begin(),nums1.end(),0,bit_xor<>()) : 0 ) ^ (nums1.size()&1 ? reduce(nums2.begin(),nums2.end(),0,bit_xor<>()) : 0 );
    }
};