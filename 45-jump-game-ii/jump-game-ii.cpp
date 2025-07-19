class Solution {
public:
    int jump(vector<int>& nums) {
     
        int l = 0 ,r = 0,jumps = 0;
        for(int i = 0 ; i < nums.size()-1;i++){
            r = max(r,i+nums[i]);
            if(i == l){
                jumps++;
                l = r;
            }
        }
        return jumps;
    }
};