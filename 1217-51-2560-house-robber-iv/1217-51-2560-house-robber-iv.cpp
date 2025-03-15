class Solution {
public:
    bool ok(int c ,vector<int>& nums, int k){
        int cnt = 0;
        for(int i = 0 ; i < nums.size();i++){
            if(nums[i]<=c){
                cnt++;i++;
            }
        }
        return cnt >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int st = *min_element(nums.begin(), nums.end()),ed = *max_element(nums.begin(), nums.end()),cur = -1,md;
        while(st<=ed){
            md = (st+ed)/2;
            if(ok(md,nums,k)){
                cur = md;
                ed = md -1;
            }
            else 
                st = md+1;
        }
        return cur;
    }
};