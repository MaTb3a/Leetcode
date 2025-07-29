class Solution {
public:
    int get(vector<int>&v){
        int x = 0;
        for(int i = 0 ; i < 32;i++)
            if(v[i])x|=(1<<i);
        return x;
    }
    bool can(int x,vector<int>&v,int mx){
        update(x,v,0);
        int cur = get(v);
        update(x,v,1);
        return cur >= mx;
    }
    void update(int x,vector<int>&v,bool add){
        for(int i = 0 ; i < 32;i++){
            if(x&(1<<i)){
                if(add)v[i]++;
                else v[i]--;
            }
        }
    }
   
    vector<int> smallestSubarrays(vector<int>& nums) {
        int mxOr = 0,n = nums.size(), j = n-1;
        for(int x : nums)mxOr|=x;
        vector<int>bts(32),v(n);
        for(int i = n-1; i  >= 0;i--){
            update(nums[i],bts,1);
            while(j > i && can(nums[j],bts,get(bts)))update(nums[j--],bts,0);        
            v[i] = j - i+1;
            
        }
        return v;
      
    }

};