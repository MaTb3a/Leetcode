class Solution {
public:
   
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) { // L R V
        int n = nums.size(), sum = 0,idx= 0;
        vector<int>v(n+1);
        for(int i = 0 ; i < n;i++){ 
            while(sum + v[i] < nums[i]){
                if(idx == queries.size())return -1;
                int l = queries[idx][0] , r =queries[idx][1], val = queries[idx][2];
                idx++;
                if(r <i)continue;
                v[max(i,l)]+=val;  
                v[r+1]-=val;
            }
            sum+=v[i];
        }
        return idx;
    }
};