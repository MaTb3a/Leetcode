class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0,ed = nums.size()-1;
        while(st<=ed){
            int md = (st+ed)/2;
            if(nums[md] == target)
                return md;
            if(nums[st] <= nums[md]){
                if(nums[st]<=target && target < nums[md]){
                    ed = md-1;
                }
                else 
                    st = md+1;
            }
            else{

                if( nums[md] < target && target <= nums[ed]){
                    st = md+1;
                }
                else 
                    ed = md-1;
            }
        }
        return -1;
    }
};