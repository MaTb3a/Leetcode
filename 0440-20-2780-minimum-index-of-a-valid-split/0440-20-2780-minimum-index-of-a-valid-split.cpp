class Solution {
public:
    int minimumIndex(vector<int>& nums) {
       

        int cnt2 = 0, x;
        for(auto it : nums){
            if(!cnt2) x = it;
            cnt2+=(it==x);
            cnt2-=(it!=x);
        }
        cnt2 = count(nums.begin(),nums.end(),x);

        int n = nums.size(), cnt1 = 0;
        for(int i = 0 ; i < n;i++){
            cnt1+=(nums[i]==x);
            cnt2-=(nums[i]==x);
            if(cnt1*2 > i+1 && cnt2*2 > n - (i+1))
                return i;
        }
        return -1;
    }
};