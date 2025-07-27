class Solution {
public:

    int countHillValley(vector<int>& nums) {
        int cnt = 0,n = nums.size();
        // l = 0 , r = 2
        //2,4,1,1,6,5
        int l = nums[0];
       

        for(int i = 1 ; i < n-1;i++){
            if(nums[i] != nums[i+1]){
                if( nums[i] > l && nums[i] > nums[i+1])cnt++;
                if( nums[i] < l && nums[i] < nums[i+1])cnt++;
                l = nums[i];
            }
         }
         return cnt;

    }
};