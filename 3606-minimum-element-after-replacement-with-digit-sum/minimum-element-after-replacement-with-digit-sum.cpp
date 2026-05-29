class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = 1e9;
        for(int x : nums){
            int sum = 0;
            while(x){
                sum+=x%10;
                x/=10;
            }
            ans=min(ans,sum);
        }
        return ans;
    }
};