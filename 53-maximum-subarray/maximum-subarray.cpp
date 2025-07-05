class Solution {
public:
    
    int maxSubArray(vector<int>& nums) {
        // int ans = -1e4;
        // for(int i = 0 ; i < nums.size();i++){ // i = 5 
        //     for(int j = i; j < nums.size(); j++){ // j = 0 
        //         int sum = 0; 
        //         for(int k = i ; k <= j ; k++){
        //             sum+=nums[k];
        //         }
        //         ans=max(ans,sum);
        //     }
        // }

        int ans = -1e4;
        int sum = 0; 
        for(int i = 0 ; i < nums.size();i++){
         
           sum = max(sum+nums[i],nums[i]);
           ans=max(ans,sum);

        }
        return ans;
        // sum = 0 , ans = -1e4
   
        // -2,1,-3,4,-1,2,1,-5,4
        // 
    }
};