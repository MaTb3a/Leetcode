class Solution {
public:
    int n;
    int dp[1001][1002][2];
    vector<int>v;
    // 0 is pos
    // 1 is neg
    int solve(int idx,int lst,bool dif){
        if(idx==n)return 0;
        int &ret=dp[idx][lst][dif];
        if(~ret)return ret;
        ret=solve(idx+1,lst,dif);
        if(!dif && v[idx]-v[lst] < 0)
            ret=max(ret,solve(idx+1,idx,!dif)+1);
        if(dif && v[idx]-v[lst] >0)
            ret=max(ret,solve(idx+1,idx,!dif)+1);
        return ret;
    }
    
    int wiggleMaxLength(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        int ans=0;
        n=nums.size();
        v=nums;
        for(int i=0;i<n-1;i++)
            ans=max({ans,solve(i+1,i,0),solve(i+1,i,1)});
        return  ans+1;    
        
    }
};