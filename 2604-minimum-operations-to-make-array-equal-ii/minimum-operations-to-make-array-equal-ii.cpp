class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if(!k)return (nums1 == nums2 ? 0 : -1);
        long long s = 0 , op = 0;
        for(int i =  0 ; i < nums1.size();i++){
            if(abs(nums1[i] - nums2[i])%k)return -1;
            s+=nums1[i] - nums2[i];
            op+=abs(nums1[i] - nums2[i])/k;
        }
        return !s ? op/2 : -1;

    }
};