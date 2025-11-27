class Solution {
public:
    
    
    int search(vector<int>& nums, int target) {
        int n= nums.size(),st = 0,ed = n-1,idx = -1;
        while(st<=ed){
            int md = (st+ed)/2;
            if(nums[md] == target)return md;

            if(nums[st] <= nums[md]){ // sorted range(st , md)
                if(nums[st] <= target && target < nums[md]){
                    ed = md-1;
                }
                else {
                    st = md+1;
                }
            }
            else{ // sorted range(md, ed)
                if(nums[md] <= nums[ed]){
                    if(nums[md] < target && target <= nums[ed]){
                        st = md+1;
                    }
                    else 
                        ed = md-1;
                }
            }
        }
        return -1;
       
    }
};